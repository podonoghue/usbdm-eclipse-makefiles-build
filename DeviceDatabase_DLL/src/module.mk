# Build list for Flash Programmer
SRC += Version.rc

# List source file to include from current directory
SRC += DeviceData.cpp
SRC += DeviceXmlParser.cpp
SRC += DualString.cpp

# Shared files $(SHARED_SRC)
VPATH := $(SHARED_SRC) $(VPATH)
INCS  += -I$(SHARED_SRC)
SRC += Utils.cpp
SRC += Names.cpp
