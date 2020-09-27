# Shared make definitions
#.SILENT :

MAJOR_VERSION := 4
MINOR_VERSION := 12
MICRO_VERSION := 1

PKG_VERSION := $(MAJOR_VERSION).$(MINOR_VERSION)
PKG_NAME = usbdm

# Used as prefix with the above when in build directory $(DUMMY_CHILD)/$(SHARED_SRC) = PackageFiles/src
DUMMY_CHILD    := PackageFiles

ifeq ('$(OS)','')
   OS=Windows_NT
endif

#BITNESS ?= 64

ifeq ($(OS),Windows_NT)
   UNAME_S := Windows
   ifeq ($(BITNESS),32)
      UNAME_M   := i386
      MULTIARCH := i386-win-gnu
   else
      UNAME_M   := x86_64
      MULTIARCH := x86_64-win-gnu
   endif
   export TMP  ?= C:\Users\PETERO~1\AppData\Local\Temp
   export TEMP ?= C:\Users\PETERO~1\AppData\Local\Temp
else
   UNAME_S   := $(shell uname -s)
   UNAME_M   := $(shell uname -m)
   MULTIARCH := $(shell gcc --print-multiarch)
   BITNESS   ?= $(shell getconf LONG_BIT)
endif

#===========================================================
# Shared directories - Relative to child directory
SHARED_SRC     := ../Shared/src
SHARED_LIBDIR := ../Shared/$(MULTIARCH)

#===========================================================
# Where to find private libraries on linux
PKG_LIBDIR="/usr/lib/$(MULTIARCH)/${PKG_NAME}"

BUILDDIR_SUFFIXx32 ?= .i386-win-gnu
BUILDDIR_SUFFIXx64 ?= .x86_64-win-gnu

#===========================================================
# Where to build
# These may be forced on the command line
ifeq ($(UNAME_S),Windows)
   DIRS = $(COMMON_DIRS) $(WIN_DIRS)
   TARGET_BINDIR   ?= ../PackageFiles/bin/$(MULTIARCH)
   TARGET_LIBDIR   ?= ../PackageFiles/bin/$(MULTIARCH)
   BUILDDIR_SUFFIX ?= .$(MULTIARCH)
   VSUFFIX         ?= .$(MAJOR_VERSION)
else
   # Assume Linux
   DIRS = $(COMMON_DIRS)
   TARGET_BINDIR   ?= ../PackageFiles/bin/$(MULTIARCH)
   TARGET_LIBDIR   ?= ../PackageFiles/lib/$(MULTIARCH)
   BUILDDIR_SUFFIX ?= .$(MULTIARCH)
   include /usr/share/java/java_defaults.mk
endif

ifeq ($(UNAME_S),Windows)
   .SUFFIXES : .d .rc
   LIB_PREFIX = 
   LIB_SUFFIX = .dll
   EXE_SUFFIX = .exe
   
   MSYS_HOME_64  := 
   MINGW_HOME    := /mingw$(BITNESS)
#   MSYS_HOME_64  := C:/Apps/msys64/
#   MINGW_HOME    := C:/Apps/msys64/mingw$(BITNESS)/
   MSYS_BIN      := $(MSYS_HOME_64)/usr/bin/
   MINGW_BIN     := $(MINGW_HOME)/bin/
   RM            := $(MSYS_BIN)rm -fy
   RMDIR         := $(MSYS_BIN)rm -R -f
   TOUCH         := $(MSYS_BIN)touch
   MKDIR         := $(MSYS_BIN)mkdir -p
   CP            := $(MSYS_BIN)cp
#   MAKE          := $(MSYS_BIN)make
   MAKE          := make
   AR            := $(MINGW_BIN)ar
   GCC           := $(MINGW_BIN)gcc
   GPP           := $(MINGW_BIN)g++
   WINDRES       := $(MINGW_BIN)windres  --use-temp-file
#   WINDRES       := $(MINGW_BIN)windres   --use-temp-file 
   STRIP         := $(MINGW_BIN)strip
   STRIPFLAGS    := --strip-unneeded
#	export PATH=/usr/bin:/usr/local/bin:/mingw64/bin:
	export PATH=$(MSYS_BIN):$(MINGW_BIN)

   PROGRAM_DIR_x64 = C:\'Program Files'
   PROGRAM_DIR_x32 = C:\'Program Files (x86)'
else
   .SUFFIXES : .d
   LIB_PREFIX 			:= lib
   LIB_SUFFIX 			:= .so.$(MAJOR_VERSION).$(MINOR_VERSION)
   LIB_MAJOR_SUFFIX 	:= .so.$(MAJOR_VERSION)
   LIB_NO_SUFFIX 		:= .so
   EXE_SUFFIX 			:= 

   MINGW_BIN := 
   MSYS_BIN  := 
   RM       := rm -f
   RMDIR    := rm -R -f
   TOUCH    := touch
   MKDIR    := mkdir -p
   CP       := cp
   LN       := ln -s -f
   MAKE     := make
   AR       := ar
   GCC      := gcc
   GPP      := g++
   STRIP    := strip
   STRIPFLAGS := --strip-unneeded
   WINDRES  := 
endif

SHARED_WXWIDGETS := "Y"
SHARED_XERCES    := "Y"

#===========================================================
# Options to build standalone DLL (windows)
ifeq ($(UNAME_S),Windows)
   STATIC_GCC_OPTION := -static -static-libstdc++ -static-libgcc
endif

#===========================================================
# Should change to using $(GUI_OPTS)
#
ifeq ($(UNAME_S),Windows)
   GUI_OPTS := -Wl,--subsystem,windows -mwindows
else
   GUI_OPTS     := 
endif
WIN32_GUI_OPTS  := GUI_OPTS

#===========================================================
# WDI
# Header files in local dir
WDI_INC        := 
# Pick up shared DLLs from Shared/lib
WDI_LIBDIRS    := 
WDI_LIBS       := -lwdi-static -lsetupapi -lole32  -lcomctl32

#===========================================================
# TCL
# Pick up shared DLLs from Shared/lib
TCL_LIBDIRS    := 
ifeq ($(UNAME_S),Windows)
   TCL_INC        := -Itcl8.6
   TCL_LIBS       := -ltcl86
else
   TCL_INC        := -I/usr/include/tcl8.6
   TCL_LIBS       := -ltcl8.6
endif

#===========================================================
# System Library
ifdef DEBUG
   USBDM_SYSTEM_LIBS    := -lusbdm-system-debug$(VSUFFIX)
else
   USBDM_SYSTEM_LIBS    := -lusbdm-system$(VSUFFIX)
endif

#===========================================================
# Device Library
ifdef DEBUG
   USBDM_DEVICE_LIBS    := -lusbdm-device-database-debug$(VSUFFIX)
else
   USBDM_DEVICE_LIBS    := -lusbdm-device-database$(VSUFFIX)
endif

#===========================================================
# Dynamic Library loading
ifeq ($(UNAME_S),Windows)
   USBDM_DYNAMIC_LIBS    := -ldl
else
   USBDM_DYNAMIC_LIBS    := -ldl
endif

#===========================================================
# Programmer Library
ifdef DEBUG
   USBDM_PROGRAMMERS_LIBS   := -lusbdm-programmer-arm-debug$(VSUFFIX)
   USBDM_PROGRAMMERS_LIBS   += -lusbdm-programmer-cfv1-debug$(VSUFFIX)
   USBDM_PROGRAMMERS_LIBS   += -lusbdm-programmer-cfvx-debug$(VSUFFIX)
   USBDM_PROGRAMMERS_LIBS   += -lusbdm-programmer-hcs08-debug$(VSUFFIX)
   USBDM_PROGRAMMERS_LIBS   += -lusbdm-programmer-hcs12-debug$(VSUFFIX)
   USBDM_PROGRAMMERS_LIBS   += -lusbdm-programmer-rs08-debug$(VSUFFIX)
   USBDM_PROGRAMMERS_LIBS   += -lusbdm-programmer-s12z-debug$(VSUFFIX)
else
   USBDM_PROGRAMMERS_LIBS   := -lusbdm-programmer-arm$(VSUFFIX)
   USBDM_PROGRAMMERS_LIBS   += -lusbdm-programmer-cfv1$(VSUFFIX)
   USBDM_PROGRAMMERS_LIBS   += -lusbdm-programmer-cfvx$(VSUFFIX)
   USBDM_PROGRAMMERS_LIBS   += -lusbdm-programmer-hcs08$(VSUFFIX)
   USBDM_PROGRAMMERS_LIBS   += -lusbdm-programmer-hcs12$(VSUFFIX)
   USBDM_PROGRAMMERS_LIBS   += -lusbdm-programmer-rs08$(VSUFFIX)
   USBDM_PROGRAMMERS_LIBS   += -lusbdm-programmer-s12z$(VSUFFIX)
endif

#===========================================================
# WXWIDGETS
ifeq ($(UNAME_S),Windows)
   WXWIDGETS_INC            := $(shell $(MINGW_BIN)/wx-config --cppflags)
   WXWIDGETS_SHARED_LIBS    := $(shell $(MINGW_BIN)/wx-config --libs)
#   WXWIDGETS_INC            := '$(shell wx-config --cppflags)'
#   WXWIDGETS_INC            := `wx-config --cppflags` #$(shell wx-config --cppflags)
#   WXWIDGETS_SHARED_LIBS    := `wx-config --libs`     #$(shell wx-config --libs)
   WXWIDGETS_DEFS           := -DuseWxWidgets -D__WXMSW__ -D__GNUWIN32__ -D_UNICODE -DUNICODE
else
   WXWIDGETS_INC            := $(shell wx-config --cppflags)
   WXWIDGETS_DEFS           := -DuseWxWidgets
   WXWIDGETS_SHARED_LIBS    := $(shell wx-config --libs)
   WXWIDGETS_STATIC_LIBDIRS := 
   WXWIDGETS_STATIC_LIBS    := 
endif

ifdef SHARED_WXWIDGETS
   WXWIDGETS_LIBDIRS := $(WXWIDGETS_SHARED_LIBDIR)
   WXWIDGETS_LIBS    := $(WXWIDGETS_SHARED_LIBS)
else
   WXWIDGETS_LIBDIRS := $(WXWIDGETS_STATIC_LIBDIRS)
   WXWIDGETS_LIBS    := $(WXWIDGETS_STATIC_LIBS)       
endif

#===========================================================
# XERCES
   XERCES_SHARED_LIBS    := -lxerces-c
   XERCES_LIBS    := $(XERCES_SHARED_LIBS)

#===========================================================
# Windows Installer XML v3.5 & Windows Installer v4.5 SDK

WIN_XML_INSTALLER_INC     := -I$(PROGRAM_DIR_x32)/'Windows Installer 4.5 SDK'/INCLUDE
WIN_XML_INSTALLER_LIBDIRS := -L$(PROGRAM_DIR_x32)/'Windows Installer 4.5 SDK'/LIB/x86
WIN_XML_INSTALLER_LIBS    := -lMsi

#===========================================================
# Java for JNI
#JAVA_DIR = 'C:/Program Files/Java/jdk1.8.0_201/'
JAVA_DIR = C:/Apps/jdk-14.0.2
ifeq ($(UNAME_S),Windows)
   JAVA_INC := -I$(JAVA_DIR)/include
   JAVA_INC += -I$(JAVA_DIR)/include/win32
else
   JAVA_INC := -I/usr/lib/jvm/default-java/include $(jvm_includes)
endif

#=============================================================
# Common USBDM DLLs in debug and non-debug versions as needed
USBDM_WX_LIBS := -lusbdm-wx-plugin$(VSUFFIX)

LIB_USB_SHARED  := -lusb-1.0
LIB_USB_STATIC  := -l:libusb-1.0.a

ifeq ($(UNAME_S),Windows)
   LIB_USB = $(LIB_USB_SHARED)
#   LIB_USB = $(LIB_USB_STATIC)
   ifdef DEBUG
      USBDM_LIBS     := -lusbdm-debug$(VSUFFIX) 
      USBDM_DSC_LIBS := -lusbdm-dsc-debug$(VSUFFIX) 
   else
      USBDM_LIBS     := -lusbdm$(VSUFFIX) 
      USBDM_DSC_LIBS := -lusbdm-dsc$(VSUFFIX) 
   endif
else
   LIB_USB = -l$(_LIB_USB_SHARED)
   ifdef DEBUG
      USBDM_LIBS     := -lusbdm-debug
      USBDM_DSC_LIBS := -lusbdm-dsc-debug 
   else
      USBDM_LIBS     := -lusbdm
      USBDM_DSC_LIBS := -lusbdm-dsc 
   endif
endif

ifdef DEBUG
   FLASHIMAGE_LIBS     := -lusbdm-flash-image-debug$(VSUFFIX) 
else
   FLASHIMAGE_LIBS     := -lusbdm-flash-image$(VSUFFIX) 
endif

#===========================================================
# Debug flags
ifeq ($(UNAME_S),Windows)
   GCC_VISIBILITY_DEFS :=
   THREADS := -mthreads
else
   GCC_VISIBILITY_DEFS :=-fvisibility=hidden -fvisibility-inlines-hidden
   THREADS := 
   CFLAGS := -fPIC
endif

ifdef DEBUG
   # Compiler flags
   CFLAGS += -O0 -g3
   # Compiler flags (Linking)
   LDFLAGS = -O0 -g3
   # C Definitions
   DEFS   := -DLOG
else
   # Compiler flags
   CFLAGS += -O3 -g3 
   # Compiler flags (Linking) - include DEBUG info as can be stripped later
   LDFLAGS = -O3 -g3 
endif

ifneq ($(OS),Windows_NT)
   # Executable will look here for libraries
   LDFLAGS += -Wl,-rpath,${PKG_LIBDIR}
   
   # Linker will look here
   LDFLAGS += -Wl,-rpath-link,${SHARED_LIBDIR}
   LDFLAGS += -Wl,-rpath-link,${TARGET_LIBDIR}

   ifeq ($(UNAME_M),x86)
      CFLAGS  += -m32
      LDFLAGS += -m32
   else ifeq ($(UNAME_M),x86_64)
      CFLAGS  += -m64
      LDFLAGS += -m64
   endif
endif

CFLAGS  += -std=gnu++14 ${THREADS} -Wall -shared ${GCC_VISIBILITY_DEFS}
LDFLAGS += ${THREADS}

#===========================================================
# Extra libraries for WINSOCK
ifeq ($(UNAME_S),Windows)
   SOCKET_LIBS := -lws2_32
else
   SOCKET_LIBS := 
endif

#===========================================================
# Look in build and shared library directories first
LIBDIRS := -L$(TARGET_LIBDIR) -L$(SHARED_LIBDIR)

#===========================================================
# Look in build and shared library directories first
LIBDIRS := -L$(TARGET_LIBDIR) -L$(SHARED_LIBDIR)

PACKAGED_FILES := $(patsubst $(SHARED_LIBDIR)/%, $(TARGET_LIBDIR)/%, $(wildcard $(SHARED_LIBDIR)/*))

$(TARGET_LIBDIR)/%.dll: $(SHARED_LIBDIR)/%.dll
	@echo -- Copying $(@F) to package directory
	$(CP) $< $@

$(TARGET_LIBDIR)/%.jed: $(SHARED_LIBDIR)/%.jed
	@echo -- Copying $(@F) to package directory
	$(CP) $< $@

$(TARGET_LIBDIR)/%.xsvf: $(SHARED_LIBDIR)/%.xsvf
	@echo -- Copying $(@F) to package directory
	$(CP) $< $@

$(TARGET_LIBDIR)/%.map: $(SHARED_LIBDIR)/%.map
	@echo -- Copying $(@F) to package directory
	$(CP) $< $@

$(TARGET_LIBDIR)/%.md: $(SHARED_LIBDIR)/%.md
	@echo -- Copying $(@F) to package directory
	$(CP) $< $@

$(TARGET_LIBDIR)/%.exe: $(SHARED_LIBDIR)/%.exe
	@echo -- Copying $(@F) to package directory
	$(CP) $< $@

$(TARGET_LIBDIR) :
	@echo -- Making directory $(TARGET_LIBDIR)
	-$(MKDIR) $(TARGET_LIBDIR)

ifneq ($(TARGET_LIBDIR),$(TARGET_BINDIR))
$(TARGET_BINDIR) :
	@echo -- Making directory $(TARGET_BINDIR)
	-$(MKDIR) $(TARGET_BINDIR)
endif

$(PACKAGED_FILES) :

commonFiles: $(TARGET_LIBDIR) $(TARGET_BINDIR) $(PACKAGED_FILES) 

.PHONY: commonFiles

