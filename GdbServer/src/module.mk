# Build list for Flash Programmer

# List source file to include from current directory
SRC += Version.rc
SRC += GdbBreakpoints_ARM.cpp
SRC += GdbBreakpoints_CFV1.cpp
SRC += GdbBreakpoints.cpp
SRC += GdbHandler_ARM.cpp
SRC += GdbHandler_CFV1.cpp
SRC += GdbHandler_CFVx.cpp
SRC += GdbHandler.cpp
SRC += GdbHandlerCommon.cpp
SRC += GdbHandlerFactory.cpp
SRC += GdbInOut.cpp
SRC += GdbInOutWx.cpp
SRC += GdbServerApp.cpp
SRC += GdbServerDialogue.cpp
SRC += GdbServerWindow.cpp
SRC += GdbServerWindowSkeleton.cpp

# Shared files $(SHARED_SRC)
VPATH := $(SHARED_SRC) $(VPATH)
INCS  += -I$(SHARED_SRC)
SRC += AppSettings.cpp
SRC += Names.cpp
SRC += Utils.cpp
SRC += UsbdmDialogueSkeleton.cpp
SRC += UsbdmDialogue.cpp
SRC += BdmInterfaceFactory.cpp
SRC += DeviceInterface.cpp
SRC += FlashProgrammerFactory.cpp
