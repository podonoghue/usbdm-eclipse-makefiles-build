# List source file to include from current directory
INCS  += -I$(SHARED_SRC)

SRC   += UsbdmJniWrapper.cpp
ifeq ($(UNAME_S),Windows)
SRC   += WinPaths.cpp
SRC   += Version.rc
else
SRC   += LinuxPaths.cpp
endif

