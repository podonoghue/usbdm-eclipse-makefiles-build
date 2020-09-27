# Defined on command line
#BUILDDIR  = UsbdmScript-debug
#CDEFS     = -DLOG
#MODULE    = module
#TARGET    = BUILDDIR
#LFLAGS    = 

include ../Common.mk

# Makefiles in subdirs used to collect targets (default 'module.mk')
ifeq ($(origin MODULE), undefined)
	MODULE := module
endif

# Main target name (default same as build directory)
ifeq ($(origin TARGET), undefined)
	TARGET := $(BUILDDIR)$(VSUFFIX)
endif

TARGET_DLL = $(LIB_PREFIX)$(TARGET)$(LIB_SUFFIX)
TARGET_EXE = $(TARGET)$(EXE_SUFFIX)

override BUILDDIR:=$(BUILDDIR)$(BUILDDIR_SUFFIX)

VPATH      := src $(BUILDDIR) 
SOURCEDIRS := src

# Use C++ Compiler
CC = $(GPP)

# Extra Compiler flags
CFLAGS +=

# Extra C Definitions
DEFS += $(CDEFS)  # From command line
#DEFS += $(XERCES_DEFS)

# Look for include files in each of the modules
INCS := $(patsubst %,-I%,$(SOURCEDIRS))
#INCS += $(XERCES_INC)

# Extra Library dirs
#LIBDIRS += $(XERCES_LIBDIRS)

# Extra libraries
ifneq ($(UNAME_S),Windows)
LIBS += -ldl
LIBS += -lm
endif
LIBS += $(USBDM_LIBS) 
LIBS += $(USBDM_DEVICE_LIBS)
LIBS += $(USBDM_SYSTEM_LIBS)
LIBS += $(USBDM_DYNAMIC_LIBS)

# Extra libraries for EXE only
EXELIBS += 

# Each module will add to this
SRC :=

# Include the source list from each module
-include $(patsubst %,%/$(MODULE).mk,$(SOURCEDIRS))

# Determine the C/CPP object files from source file list
OBJ := \
$(patsubst %.cpp,$(BUILDDIR)/%.o, \
$(filter %.cpp,$(SRC))) \
$(patsubst %.c,$(BUILDDIR)/%.o, \
$(filter %.c,$(SRC)))

ifeq ($(UNAME_S),Windows)
# Determine the resource object files 
RESOURCE_OBJ := \
$(patsubst %.rc,$(BUILDDIR)/%.o, \
$(filter %.rc,$(SRC))) 
else
RESOURCE_OBJ := 
endif

# Include the C dependency files (if they exist)
-include $(OBJ:.o=.d)

# Rules to build object (.o) files
#==============================================
ifeq ($(UNAME_S),Windows)
$(BUILDDIR)/%.o : %.rc
	@echo -- Building $@ from $<
	$(WINDRES) $< $(DEFS) $(INCS) -o $@
endif

$(BUILDDIR)/%.o : %.c
	@echo -- Building $@ from $<
	$(CC) $(CFLAGS) $(DEFS) $(INCS) -MD -c $< -o $@
	
$(BUILDDIR)/%.o : %.cpp
	@echo -- Building $@ from $<
	$(CC) $(CFLAGS) $(DEFS) $(INCS) -MD -c $< -o $@
	
# How to link an EXE
#==============================================
$(BUILDDIR)/$(TARGET_EXE): $(OBJ) $(RESOURCE_OBJ)
	@echo --
	@echo -- Linking Target $@
	$(CC) -o $@ $(LDFLAGS) $(OBJ) $(RESOURCE_OBJ) $(LIBDIRS) $(LIBS) $(EXELIBS)

# How to copy EXE to target directory
#==============================================
$(TARGET_BINDIR)/$(TARGET_EXE): $(BUILDDIR)/$(TARGET_EXE)
	@echo --
	@echo -- Copying $? to $@
	$(CP) $? $@
	$(STRIP) $(STRIPFLAGS) $@

# How to link a LIBRARY
#==============================================
$(BUILDDIR)/$(TARGET_DLL): $(OBJ) $(RESOURCE_OBJ)
	@echo --
	@echo -- Linking Target $@
	$(CC) -shared -o $@ -Wl,-soname,$(basename $(notdir $@)) $(LDFLAGS) $(OBJ) $(RESOURCE_OBJ) $(LIBDIRS) $(LIBS) ${EXELIBS}
	
# How to copy LIBRARY to target directory
#==============================================
$(TARGET_LIBDIR)/$(TARGET_DLL): $(BUILDDIR)/$(TARGET_DLL)
	@echo --
	@echo -- Copying $? to $@
	$(CP) $? $@
	$(STRIP) $(STRIPFLAGS) $@
ifneq ($(UNAME_S),Windows)
	$(LN) $(TARGET_DLL) $(TARGET_LIBDIR)/$(LIB_PREFIX)$(TARGET)$(LIB_MAJOR_SUFFIX)
	$(LN) $(TARGET_DLL) $(TARGET_LIBDIR)/$(LIB_PREFIX)$(TARGET)$(LIB_NO_SUFFIX)
endif

# Create required directories for targets
#==============================================
$(BUILDDIR) :
	@echo -- Making directory $(BUILDDIR)
	-$(MKDIR) $(BUILDDIR)
       
$(TARGET_LIBDIR)/$(TARGET_DLL): | $(TARGET_LIBDIR)

$(TARGET_BINDIR)/$(TARGET_EXE): | $(TARGET_BINDIR)

$(BUILDDIR)/$(TARGET_DLL) $(OBJ) $(RESOURCE_OBJ): | $(BUILDDIR)

# Main targets
#==============================================
clean:
	-$(RMDIR) $(BUILDDIR)

dll: commonFiles $(TARGET_LIBDIR)/$(TARGET_DLL)

exe: commonFiles $(TARGET_BINDIR)/$(TARGET_EXE)
   
.PHONY: clean dll exe

