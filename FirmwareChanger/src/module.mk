# Build list for Module
# List source file to include from current directory
SRC += Version.rc
SRC += FirmwareChangerSkeleton.cpp
SRC += FirmwareChanger.cpp
SRC += ProgressDialogue.cpp
SRC += Version.rc

# Shared files $(SHARED_SRC)
VPATH := $(VPATH) $(SHARED_SRC)
INCS  += -I$(SHARED_SRC)
SRC   += Names.cpp
SRC += Utils.cpp
SRC += AppSettings.cpp