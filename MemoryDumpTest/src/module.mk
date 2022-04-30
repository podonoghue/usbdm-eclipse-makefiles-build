# Build list for Flash Programmer

# List source file to include from current directory
SRC += Version.rc

SRC += MemoryDumpApp.cpp
SRC += MemoryDumpDialogueSkeleton.cpp
SRC += MemoryDumpDialogue.cpp

# Shared files $(SHARED_SRC)
VPATH := $(SHARED_SRC) $(VPATH)
INCS  += -I$(SHARED_SRC)
SRC += AppSettings.cpp
SRC += Names.cpp
SRC += ProgressDialogue.cpp
