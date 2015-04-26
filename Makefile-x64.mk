include Common-x64.mk
export TARGET_BINDIR TARGET_LIBDIR BITNESS BUILDDIR_SUFFIX VSUFFIX

# Built on both Windows and Linux
# Note - order is important
DIRS = \
  Usbdm_DLL            \
  UsbdmJni_DLL

BUILD_DIRS = $(DIRS:%=build-%)
CLEAN_DIRS = $(DIRS:%=clean-%)

.PHONY: $(CLEAN_DIRS)
.PHONY: $(BUILD_DIRS)
.PHONY: clean all cleanTargetFiles

all: addExternalFiles $(BUILD_DIRS)

clean: cleanTargetFiles $(CLEAN_DIRS)

cleanTargetFiles:
	$(RMDIR) $(DUMMY_CHILD)/$(TARGET_LIBDIR)
	$(RMDIR) $(DUMMY_CHILD)/$(TARGET_BINDIR)

# Copy external DLLs
addExternalFiles:
	$(MKDIR) $(DUMMY_CHILD)/$(TARGET_LIBDIR)
	$(MKDIR) $(DUMMY_CHILD)/$(TARGET_BINDIR)
	$(CP) $(DUMMY_CHILD)/$(SHARED_LIBDIRS)/* $(DUMMY_CHILD)/$(TARGET_LIBDIR)

$(BUILD_DIRS):
	$(MAKE) -C $(@:build-%=%) all -f Makefile-x64.mk 

$(CLEAN_DIRS):
	$(MAKE) -C $(@:clean-%=%) clean -f Makefile-x64.mk 
