include ../Common.mk

TARGET = JS16_Bootloader

EXE_DEFS = -DUSE_ICON

$(TARGET):
	@echo ''
	@echo  Building $@ 64-bit
	@echo "================================================================"
	$(MAKE) exe -f Target.mk BUILDDIR=$@ TARGET=$@ CDEFS='$(EXE_DEFS)' BITNESS=64

$(TARGET)-debug:
	@echo ''
	@echo  Building $@ 64-bit
	@echo "================================================================"
	$(MAKE) exe -f Target.mk BUILDDIR=$@ TARGET=$@ CDEFS='$(EXE_DEFS)' DEBUG='Y' BITNESS=64

all: $(TARGET) $(TARGET)-debug

clean:
	${RMDIR} $(TARGET)$(BUILDDIR_SUFFIXx64) $(TARGET)-debug$(BUILDDIR_SUFFIXx64)

.PHONY: all clean 
.PHONY: $(TARGET) $(TARGET)-debug