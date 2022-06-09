include ../Common.mk

TARGET = usbdm-tcl

EXE_DEFS  = -DNEED_ALL_NAMES -DUSE_ICON -DINTERACTIVE
DLL_DEFS  = -DNEED_ALL_NAMES -DUSBDM_TCL_DLL_EXPORTS
TEST_DEFS = -DNEED_ALL_NAMES -DUSE_ICON -DTEST_APP

$(TARGET):
	@echo ''
	@echo  Building $@ 32-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@ CDEFS='$(DLL_DEFS)' BITNESS=32

$(TARGET)-debug:
	@echo ''
	@echo  Building $@ 32-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@ CDEFS='$(DLL_DEFS)'  DEBUG='Y' BITNESS=32


all: $(TARGET) $(TARGET)-debug

clean:
	-${RMDIR} $(TARGET)$(BUILDDIR_SUFFIXx32)    $(TARGET)-debug$(BUILDDIR_SUFFIXx32)

.PHONY: all clean 
.PHONY: $(TARGET) $(TARGET)-debug

