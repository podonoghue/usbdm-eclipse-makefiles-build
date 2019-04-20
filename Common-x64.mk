# Shared make definitions
# Modified for Raspberry Pi

#.SILENT :

MAJOR_VERSION := 4
MINOR_VERSION := 12
MICRO_VERSION := 1
USBDM_VERSION := $(MAJOR_VERSION).$(MINOR_VERSION)

# Used as prefix with the above when in build directory $(DUMMY_CHILD)/$(SHARED_SRC) = PackageFiles/src
DUMMY_CHILD    := PackageFiles

ifeq ($(OS),Windows_NT)
    UNAME_S := Windows
    UNAME_M := x86_64
    MULTIARCH := x86_64-win-gnu
else
    UNAME_S := $(shell uname -s)
    UNAME_M := $(shell uname -m)
    MULTIARCH := $(shell gcc --print-multiarch)
endif

#===========================================================
# Shared directories - Relative to child directory
SHARED_SRC     := ../Shared_V4/src
SHARED_LIBDIRS := ../Shared_V4/$(MULTIARCH)

#===========================================================
# Where to find private libraries on linux
USBDM_LIBDIR="/usr/lib/$(MULTIARCH)/usbdm"

#===========================================================
# Where to build
# These may be forced on the command line
ifeq ($(UNAME_S),Windows)
   DIRS = $(COMMON_DIRS) $(WIN_DIRS)
   BITNESS         ?= 32
   TARGET_BINDIR   ?= ../PackageFiles/bin/$(MULTIARCH)
   TARGET_LIBDIR   ?= ../PackageFiles/bin/$(MULTIARCH)
   BUILDDIR_SUFFIX ?= .$(MULTIARCH)
   VSUFFIX         ?= .$(MAJOR_VERSION)
else
   # Assume Linux
   DIRS = $(COMMON_DIRS)
   BITNESS ?= $(shell getconf LONG_BIT)
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
   MINGWBIN := C:/Apps/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/bin
   MSYSBIN  := C:/Apps/MinGW/msys/1.0/bin
   RM       := $(MSYSBIN)/rm -f
   RMDIR    := $(MSYSBIN)/rm -R -f
   TOUCH    := $(MSYSBIN)/touch
   MKDIR    := $(MSYSBIN)/mkdir -p
   CP       := $(MSYSBIN)/cp
   MAKE     := $(MINGWBIN)/mingw32-make
   GCC      := $(MINGWBIN)/gcc
   GPP      := $(MINGWBIN)/g++
   WINDRES  := $(MINGWBIN)/windres
   STRIP    := $(MINGWBIN)/strip
   STRIPFLAGS := --strip-unneeded
   #PROGRAM_DIR = C:/"Program Files"
   PROGRAM_DIR = C:/'Program Files (x86)'
else
   .SUFFIXES : .d
   LIB_PREFIX 			:= lib
   LIB_SUFFIX 			:= .so.$(MAJOR_VERSION).$(MINOR_VERSION)
   LIB_MAJOR_SUFFIX 	:= .so.$(MAJOR_VERSION)
   LIB_NO_SUFFIX 		:= .so
   EXE_SUFFIX 			:= 

   MINGWBIN := 
   MSYSBIN  := 
   RM       := rm -f
   RMDIR    := rm -R -f
   TOUCH    := touch
   MKDIR    := mkdir -p
   CP       := cp
   LN       := ln -s -f
   MAKE     := make
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
   STATIC_GCC_OPTION := -static-libstdc++ -static-libgcc
endif

#===========================================================
# WIN32
ifeq ($(UNAME_S),Windows)
   WIN32_GUI_OPTS     := -Wl,--subsystem,windows -mwindows
else
   WIN32_GUI_OPTS     := 
endif

#===========================================================
# WDI
# Header files in local dir
WDI_INC        := 
# Pick up shared DLLs from Shared_V4/lib
WDI_LIBDIRS    := 
WDI_LIBS       := -lwdi-static -lsetupapi -lole32  -lcomctl32

#===========================================================
# TCL
# Pick up shared DLLs from Shared_V4/lib
TCL_LIBDIRS    := 
ifeq ($(UNAME_S),Windows)
   TCL_INC        := -IC:/Apps/Tcl/include
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
   USBDM_DYNAMIC_LIBS    := 
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
   WXWIDGETS_INSTALL_DIR=C:/Apps/wxWidgets-3.1.2
   WXWIDGETS_VERSION_NUM=312
   WXWIDGETS_INC     := -I$(WXWIDGETS_INSTALL_DIR)/lib/gcc_lib/mswu -I$(WXWIDGETS_INSTALL_DIR)/include -I$(WXWIDGETS_INSTALL_DIR)/lib/gcc_dll/mswu
   WXWIDGETS_DEFS    := -DuseWxWidgets -D__WXMSW__ -D__GNUWIN32__ -DUNICODE

   # Pick up shared DLLs from Shared_V4/lib
   WXWIDGETS_SHARED_LIBDIRS :=
   WXWIDGETS_SHARED_LIBS    := \
   -lwxmsw$(WXWIDGETS_VERSION_NUM)u_core_gcc_custom       \
   -lwxbase$(WXWIDGETS_VERSION_NUM)u_gcc_custom           \
   -lwxmsw$(WXWIDGETS_VERSION_NUM)u_adv_gcc_custom        
   
   #-lwxmsw$(WXWIDGETS_VERSION_NUM)u_richtext_gcc_custom     \
   #-lwxbase$(WXWIDGETS_VERSION_NUM)u_xml_gcc_custom         \
   #-lwxmsw$(WXWIDGETS_VERSION_NUM)u_html_gcc_custom         \
   #-lwxbase$(WXWIDGETS_VERSION_NUM)u_net_gcc_custom         \
   #-lwxmsw$(WXWIDGETS_VERSION_NUM)u_aui_gcc_custom          \
   #-lwxmsw$(WXWIDGETS_VERSION_NUM)u_gl_gcc_custom           \
   #-lwxmsw$(WXWIDGETS_VERSION_NUM)u_media_gcc_custom      -lwxmsw$(WXWIDGETS_VERSION_NUM)u_propgrid_gcc_custom \
   #-lwxmsw$(WXWIDGETS_VERSION_NUM)u_ribbon_gcc_custom     -lwxmsw$(WXWIDGETS_VERSION_NUM)u_richtext_gcc_custom \
   #-lwxmsw$(WXWIDGETS_VERSION_NUM)u_stc_gcc_custom        -lwxmsw$(WXWIDGETS_VERSION_NUM)u_webview_gcc_custom  \
   #-lwxmsw$(WXWIDGETS_VERSION_NUM)u_xrc_gcc_custom   

   WXWIDGETS_STATIC_LIBDIRS := -L$(WXWIDGETS_INSTALL_DIR)/lib/gcc_lib
   WXWIDGETS_STATIC_LIBS    := \
   -lwxmsw29u_core \
   -lwxpng \
   -lwxzlib \
   -lwxbase29u \
   -lgdi32 -lcomdlg32 -lwinspool -lcomctl32 -lole32 -loleaut32 -luuid 
   
   #-luser32 -lshell32 -lwinmm -lkernel32 -ladvapi32 -lwsock32
   #-lwxjpeg \
   #-lwxbase29u_xml \
   #-lwxbase29u_net \
   #-lwxmsw29u_xrc  \
   #-lwxmsw29u_html \
   #-lwxmsw29u_aui \
   #-lwxbase29u \
   #-lwxmsw29u_adv \
   #-lwxtiff \
   #-lwxmsw29u_richtext \
   #-lwxzlib -lwxregexu  \
   #-lwxexpat
   #-lrpcrt4 
   #-lwxmsw29u_gl -lwxmsw29u_media -lwxmsw29u_propgrid -lwxmsw29u_ribbon \
   #-lwxmsw29u_stc -lwxmsw29u_webview \
   #-lwxscintilla           

else
#   WXWIDGETS_INC     := `wx-config --cppflags`
   WXWIDGETS_INC     := $(shell wx-config --cppflags)
   WXWIDGETS_DEFS    := -DuseWxWidgets

   WXWIDGETS_SHARED_LIBDIRS :=
#   WXWIDGETS_SHARED_LIBS    := `wx-config --libs`
   WXWIDGETS_SHARED_LIBS    := $(shell wx-config --libs)

   WXWIDGETS_STATIC_LIBDIRS := 
   WXWIDGETS_STATIC_LIBS    := 
endif

ifdef SHARED_WXWIDGETS
   WXWIDGETS_LIBDIRS := $(WXWIDGETS_SHARED_LIBDIRS)
   WXWIDGETS_LIBS    := $(WXWIDGETS_SHARED_LIBS)
else
   WXWIDGETS_LIBDIRS := $(WXWIDGETS_STATIC_LIBDIRS)
   WXWIDGETS_LIBS    := $(WXWIDGETS_STATIC_LIBS)       
endif

#===========================================================
# XERCES
ifeq ($(UNAME_S),Windows)
   XERCES_INC     := -IC:/Apps/xerces-c-3.1.1/src/

   # Pick up shared DLLs from Shared_V4/lib
   XERCES_SHARED_LIBDIRS := 
   XERCES_STATIC_LIBDIRS := -LC:/Apps/xerces-c-3.1.1/src/.libs
   XERCES_SHARED_LIBS    := -lxerces-c-3-1
   XERCES_STATIC_LIBS    := -lxerces-c
else
   XERCES_INC     :=

   # Pick up shared DLLs from Shared_V4/lib
   XERCES_SHARED_LIBDIRS := 
   XERCES_STATIC_LIBDIRS := 
   XERCES_SHARED_LIBS    := -lxerces-c
   XERCES_STATIC_LIBS    := 
endif

ifdef SHARED_XERCES
   XERCES_LIBS    := $(XERCES_SHARED_LIBS)
   XERCES_LIBDIRS := $(XERCES_SHARED_LIBDIRS)
else
   XERCES_LIBS    := $(XERCES_STATIC_LIBS)
   XERCES_LIBDIRS := $(XERCES_STATIC_LIBDIRS)
endif

#===========================================================
# Windows Installer XML v3.5 & Windows Installer v4.5 SDK

WIN_XML_INSTALLER_INC     := -I$(PROGRAM_DIR)/'Windows Installer 4.5 SDK'/INCLUDE
WIN_XML_INSTALLER_LIBDIRS := -L$(PROGRAM_DIR)/'Windows Installer 4.5 SDK'/LIB/x86
WIN_XML_INSTALLER_LIBS    := -lMsi

#===========================================================
# Java for JNI
PROGRAM_DIR_JAVA = C:/'Program Files'
#PROGRAM_DIR_JAVA = C:/'Program Files (x86)'
ifeq ($(UNAME_S),Windows)
   JAVA_INC := -I$(PROGRAM_DIR_JAVA)/Java/jdk1.8.0_201/include
   JAVA_INC += -I$(PROGRAM_DIR_JAVA)/Java/jdk1.8.0_201/include/win32
else
   JAVA_INC := -I/usr/lib/jvm/default-java/include $(jvm_includes)
endif

#=============================================================
# Common USBDM DLLs in debug and non-debug versions as needed
USBDM_WX_LIBS := -lusbdm-wx-plugin$(VSUFFIX)

_LIB_USB_SHARED  := usb-1.0
_LIB_USB_STATIC  := usb-static-1.0

ifeq ($(UNAME_S),Windows)
   LIB_USB = -l$(_LIB_USB_STATIC)
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
   CFLAGS  := -D__USE_MINGW_ANSI_STDIO # required for snprintf() to work!!
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
   # Compiler flags (Linking)
   LDFLAGS = -s
endif

ifneq ($(OS),Windows_NT)
   LDFLAGS += -Wl,-rpath,${USBDM_LIBDIR}
   LDFLAGS += -Wl,-rpath-link,${TARGET_LIBDIR}

   ifeq ($(UNAME_M),x86)
      CFLAGS  += -m32
      LDFLAGS += -m32
   else ifeq ($(UNAME_M),x86_64)
      CFLAGS  += -m64
      LDFLAGS += -m64
   endif
endif

CFLAGS  += ${THREADS} -Wall -shared ${GCC_VISIBILITY_DEFS}
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
LIBDIRS := -L$(TARGET_LIBDIR) -L$(SHARED_LIBDIRS)
