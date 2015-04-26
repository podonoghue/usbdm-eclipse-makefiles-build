# Shared make definitions
#

#.SILENT :

MAJOR_VERSION := 4
MINOR_VERSION := 11
MICRO_VERSION := 1
USBDM_VERSION := $(MAJOR_VERSION).$(MINOR_VERSION)

#===========================================================
# Where to find private libraries on linux
USBDM_LIBDIR32="/usr/lib/i386-linux-gnu/usbdm"
USBDM_LIBDIR64="/usr/lib/x86_64-linux-gnu/usbdm"

#===========================================================
# Shared directories - Relative to child directory
SHARED_SRC     := ../Shared_V4/src
SHARED_LIBDIRS := ../Shared_V4/lib.x86_64

# Used as prefix with the above when in build directory $(DUMMY_CHILD)/$(SHARED_SRC) = PackageFiles/src
DUMMY_CHILD    := PackageFiles

ifeq ($(OS),Windows_NT)
    UNAME_S := Windows
else
    UNAME_S := $(shell uname -s)
endif

#===========================================================
# Where to build
# These may be forced on the command line
ifeq ($(UNAME_S),Windows)
   DIRS = $(COMMON_DIRS) $(WIN_DIRS)
   BITNESS         ?= 32
   TARGET_BINDIR   ?= ../PackageFiles/bin/x86_64-win-gnu
   TARGET_LIBDIR   ?= ../PackageFiles/bin/x86_64-win-gnu
   BUILDDIR_SUFFIX ?= .x86_64
   VSUFFIX         ?= .4
else
   # Assume Linux
   DIRS = $(COMMON_DIRS)
   BITNESS ?= $(shell getconf LONG_BIT)
   ifeq ($(BITNESS),32)
      TARGET_BINDIR   ?= ../PackageFiles/bin/i386-linux-gnu
      TARGET_LIBDIR   ?= ../PackageFiles/lib/i386-linux-gnu
      BUILDDIR_SUFFIX ?= .i386
   endif
   ifeq ($(BITNESS),64)
      TARGET_BINDIR   ?= ../PackageFiles/bin/x86_64-linux-gnu
      TARGET_LIBDIR   ?= ../PackageFiles/lib/x86_64-linux-gnu
      BUILDDIR_SUFFIX ?= .x86_64
   endif
endif

ifeq ($(UNAME_S),Windows)
   .SUFFIXES : .d .rc
   LIB_PREFIX = 
   LIB_SUFFIX = .dll
   EXE_SUFFIX = .exe
   MINGWBIN := C:/Apps/mingw-w64/x86_64-4.9.2-posix-seh-rt_v4-rev2/mingw64/bin
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
   TCL_LIBS       := -ltcl85
else
   TCL_INC        := -I/usr/include/tcl8.5
   TCL_LIBS       := -ltcl8.5
endif

#===========================================================
# System Library
ifdef DEBUG
   USBDM_SYSTEM_LIBS    := -lusbdm-system-debug.4
else
   USBDM_SYSTEM_LIBS    := -lusbdm-system.4
endif

#===========================================================
# Device Library
ifdef DEBUG
   USBDM_DEVICE_LIBS    := -lusbdm-device-database-debug.4
else
   USBDM_DEVICE_LIBS    := -lusbdm-device-database.4
endif

#===========================================================
# Programmer Library
ifdef DEBUG
   USBDM_PROGRAMMERS_LIBS   := -lusbdm-programmer-arm-debug.4
   USBDM_PROGRAMMERS_LIBS   += -lusbdm-programmer-cfv1-debug.4
   USBDM_PROGRAMMERS_LIBS   += -lusbdm-programmer-cfvx-debug.4
   USBDM_PROGRAMMERS_LIBS   += -lusbdm-programmer-hcs08-debug.4
   USBDM_PROGRAMMERS_LIBS   += -lusbdm-programmer-hcs12-debug.4
   USBDM_PROGRAMMERS_LIBS   += -lusbdm-programmer-rs08-debug.4
   USBDM_PROGRAMMERS_LIBS   += -lusbdm-programmer-s12z-debug.4
else
   USBDM_PROGRAMMERS_LIBS   := -lusbdm-programmer-arm.4
   USBDM_PROGRAMMERS_LIBS   += -lusbdm-programmer-cfv1.4
   USBDM_PROGRAMMERS_LIBS   += -lusbdm-programmer-cfvx.4
   USBDM_PROGRAMMERS_LIBS   += -lusbdm-programmer-hcs08.4
   USBDM_PROGRAMMERS_LIBS   += -lusbdm-programmer-hcs12.4
   USBDM_PROGRAMMERS_LIBS   += -lusbdm-programmer-rs08.4
   USBDM_PROGRAMMERS_LIBS   += -lusbdm-programmer-s12z.4
endif

#===========================================================
# WXWIDGETS
ifeq ($(UNAME_S),Windows)
   WXWIDGETS_INSTALL_DIR=C:/Apps/wxWidgets-3.0.2
   WXWIDGETS_VERSION_NUM=30
   WXWIDGETS_INC     := -I$(WXWIDGETS_INSTALL_DIR)/lib/gcc_lib/mswu -I$(WXWIDGETS_INSTALL_DIR)/include -IC:\Apps\wxWidgets-3.0.2\lib\gcc_dll\mswu
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
   JAVA_INC := -I$(PROGRAM_DIR_JAVA)/Java/jdk1.8.0_40/include
   JAVA_INC += -I$(PROGRAM_DIR_JAVA)/Java/jdk1.8.0_40/include/win32
else
   JAVA_INC := -I/usr/lib/jvm/default-java/include
endif

#=============================================================
# Common USBDM DLLs in debug and non-debug versions as needed
USBDM_WX_LIBS := -lusbdm-wx.4

_LIB_USB_SHARED  := usb-1.0
_LIB_USB_STATIC  := usb-static-1.0

ifeq ($(UNAME_S),Windows)
   LIB_USB = -l$(_LIB_USB_STATIC)
   ifdef DEBUG
      USBDM_LIBS     := -lusbdm-debug.4 
      USBDM_TCL_LIBS := -lusbdm-tcl-debug.4 
      USBDM_DSC_LIBS := -lusbdm-dsc-debug.4 
   else
      USBDM_LIBS     := -lusbdm.4 
      USBDM_TCL_LIBS := -lusbdm-tcl.4 
      USBDM_DSC_LIBS := -lusbdm-dsc.4 
   endif
else
   LIB_USB = -l$(_LIB_USB_SHARED)
   ifdef DEBUG
      USBDM_LIBS     := -lusbdm-debug
      USBDM_TCL_LIBS := -lusbdm-tcl-debug 
      USBDM_DSC_LIBS := -lusbdm-dsc-debug 
   else
      USBDM_LIBS     := -lusbdm
      USBDM_TCL_LIBS := -lusbdm-tcl 
      USBDM_DSC_LIBS := -lusbdm-dsc 
   endif
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
   LDFLAGS = 
   # C Definitions
   DEFS   := -DLOG
else
   # Compiler flags
   CFLAGS += -O3 -g0 
   # Compiler flags (Linking)
   LDFLAGS = -s
endif

ifneq ($(OS),Windows_NT)
   ifeq ($(BITNESS),32)
      CFLAGS  += -m32
      LDFLAGS += -m32 -Wl,-rpath,${USBDM_LIBDIR32}
   endif
   ifeq ($(BITNESS),64)
      CFLAGS  += -m64
      LDFLAGS += -m64 -Wl,-rpath,${USBDM_LIBDIR64}
   endif
endif

CFLAGS  += ${THREADS} -Wall -shared ${GCC_VISIBILITY_DEFS}
LDFLAGS += ${THREADS}

#CFLAGS += -Wshadow -DWINVER=0x500 -D_WIN32_IE=0x500 -std=gnu99 -Wall -Wundef -Wunused -Wstrict-prototypes -Werror-implicit-function-declaration -Wno-pointer-sign

#===========================================================
# Extra libraries for WINSOCK
ifeq ($(UNAME_S),Windows)
   SOCKET_LIBS := -lws2_32
else
   SOCKET_LIBS := 
endif

#===========================================================
# Look in shared Library dir first
LIBDIRS := -L$(TARGET_LIBDIR) -L$(SHARED_LIBDIRS)

#===========================================================
# Common Definitions for building Programmer, GDI & GDB
GDI_DEFS        = -DTARGET=$(TARGET) -DGDI
GDI_LEGACY_DEFS = -DTARGET=$(TARGET) -DGDI -DLEGACY

ifeq ($(UNAME_S),Windows)
# Windows version of Codewarrior packs structs
GDI_DEFS        = -DPACK_STRUCTS=1 -DTARGET=$(TARGET) -DGDI
endif

