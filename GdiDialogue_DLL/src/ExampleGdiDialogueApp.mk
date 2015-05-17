# Build list 

# List source file to include from current directory
SRC += Example.cpp
SRC += BdmInterfaceFactory.cpp
SRC += AppSettings.cpp
SRC += Names.cpp
SRC += Utils.cpp

# Shared files $(SHARED_SRC)
VPATH := $(SHARED_SRC) $(VPATH)
INCS  += -I$(SHARED_SRC)