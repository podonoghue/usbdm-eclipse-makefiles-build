# Build list for Flash Programmer

# List source file to include from current directory
SRC += Version.rc

SRC += GdiDialoguePluginImp.cpp
SRC += GdiDialogueSkeleton.cpp
SRC += GdiDialogue.cpp
SRC += BdmInterfaceFactory.cpp
SRC += AppSettings.cpp
SRC += Utils.cpp
SRC += wxStub.cpp
SRC += Names.cpp

# Shared files $(SHARED_SRC)
VPATH := $(SHARED_SRC) $(VPATH)
INCS  += -I$(SHARED_SRC)
