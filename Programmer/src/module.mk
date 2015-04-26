# Build list for Flash Programmer

# List source file to include from current directory
SRC += Version.rc

SRC += UsbdmDialogueSkeleton.cpp
SRC += UsbdmDialogue.cpp
SRC += ProgrammerDialogue.cpp
SRC += FlashProgrammerApp.cpp
SRC += BdmInterfaceFactory.cpp
SRC += DeviceInterface.cpp
SRC += FlashProgrammerFactory.cpp

# Shared files $(SHARED_SRC)
VPATH := $(SHARED_SRC) $(VPATH)
INCS  += -I$(SHARED_SRC)
SRC += AppSettings.cpp
SRC += Names.cpp
SRC += UsbdmTclInterpreterFactory.h
SRC += Utils.cpp

# Shared files $(SHARED_SRC)/Programmer
#VPATH := $(SHARED_SRC)/Programmer $(VPATH)
#INCS  += -I$(SHARED_SRC)/Programmer

