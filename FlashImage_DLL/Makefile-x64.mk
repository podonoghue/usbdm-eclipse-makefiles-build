include ../Common.mk

TARGET  = usbdm-flash-image

DLL_DEFS ='-DCOMPILE_FLASH_IMAGE_DLL'

$(TARGET):
	@echo ''
	@echo  Building $@ 64-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@ CDEFS='$(DLL_DEFS)' BITNESS=64

$(TARGET)-debug:
	@echo ''
	@echo  Building $@ 64-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@ CDEFS='$(DLL_DEFS)' DEBUG='Y' BITNESS=64

EXE_DEFS = -DUSE_ICON

$(TARGET)-test:
	@echo ''
	@echo  Building $@ 64-bit
	@echo "================================================================"
	$(MAKE) exe -f Target.mk BUILDDIR=$@ MODULE=test TARGET=$@ CDEFS='$(EXE_DEFS)' BITNESS=64

$(TARGET)-debug-test:
	@echo ''
	@echo  Building $@ 64-bit
	@echo "================================================================"
	$(MAKE) exe -f Target.mk BUILDDIR=$@ MODULE=test TARGET=$@ CDEFS='$(EXE_DEFS)' DEBUG='Y' BITNESS=64

all: $(TARGET) $(TARGET)-debug $(TARGET)-test $(TARGET)-debug-test

clean:
	-${RMDIR} $(TARGET)$(BUILDDIR_SUFFIXx64)         $(TARGET)-debug$(BUILDDIR_SUFFIXx64)
	-${RMDIR} $(TARGET)-test$(BUILDDIR_SUFFIXx64)    $(TARGET)-debug-test$(BUILDDIR_SUFFIXx64)

.PHONY: all clean 
.PHONY: $(TARGET) $(TARGET)-debug
.PHONY: $(TARGET)-test $(TARGET)-debug-test
