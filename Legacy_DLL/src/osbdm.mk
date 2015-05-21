# List source file to include in build
SRC += Version.rc
SRC += OpenSourceBDM_dll.cpp
#SRC += hcs12UnsecureDialogue.cpp

# Shared files $(SHARED_SRC)
VPATH := $(SHARED_SRC) $(VPATH)
INCS  += -I$(SHARED_SRC)
SRC   += Utils.cpp
SRC   += AppSettings.cpp
SRC   += Names.cpp
