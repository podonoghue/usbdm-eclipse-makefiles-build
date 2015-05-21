# Build list for Flash Programmer
SRC += Version.rc

# List source file to include from current directory

SRC += GDI_Common.cpp
SRC += MetrowerksInterface.cpp
SRC += FindWindow.cpp

# Shared files $(SHARED_SRC)
VPATH := $(SHARED_SRC) $(VPATH)
INCS  += -I$(SHARED_SRC)
