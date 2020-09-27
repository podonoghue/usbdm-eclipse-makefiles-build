# Build list for Flash Programmer

# List source file to include from current directory
SRC += Version.rc

SRC += WxPluginImp.cpp
SRC += WxStub.cpp

# Shared files $(SHARED_SRC)
VPATH := $(SHARED_SRC) $(VPATH)
INCS  += -I$(SHARED_SRC)
