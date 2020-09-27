include ../Common.mk

TARGET = CreateCTestImage

EXE_DEFS = -DUSE_ICON

$(TARGET):
	@echo ''
	@echo  Building $@ 64-bit
	@echo "================================================================"
	$(MAKE) exe -f Target.mk BUILDDIR=$@ TARGET=$@ CDEFS='$(EXE_DEFS)' BITNESS=64

all: $(TARGET)

clean:
	${RMDIR} $(TARGET)$(BUILDDIR_SUFFIXx64)

.PHONY: all clean 
.PHONY: $(TARGET)
