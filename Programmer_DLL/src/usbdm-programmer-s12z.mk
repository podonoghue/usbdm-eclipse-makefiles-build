# Build list for Flash Programmer
SRC += Version.rc

# List source file to include from current directory
SRC += FlashProgrammerCommon.cpp
SRC += FlashProgrammer_S12Z.cpp
SRC += ProgressTimer.cpp
SRC += SimpleSRecords.cpp

# Shared files $(SHARED_SRC)
VPATH := $(SHARED_SRC) $(VPATH)
INCS  += -I$(SHARED_SRC)
SRC += Names.cpp
SRC += Utils.cpp
