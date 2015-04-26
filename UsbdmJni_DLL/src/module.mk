# List source file to include from current directory
SRC += UsbdmJniWrapper.cpp
INCS  += -I$(SHARED_SRC)
ifeq ($(UNAME_S),Windows)
SRC += WinPaths.cpp
SRC += Version.rc
else
SRC += LinuxPaths.cpp
endif

