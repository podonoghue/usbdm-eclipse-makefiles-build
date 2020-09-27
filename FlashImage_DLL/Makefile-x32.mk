include ../Common.mk

TARGET  = usbdm-flash-image

DLL_DEFS ='-DCOMPILE_FLASH_IMAGE_DLL'

$(TARGET):
	@echo ''
	@echo  Building $@ 32-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@ CDEFS='$(DLL_DEFS)' BITNESS=32

$(TARGET)-debug:
	@echo ''
	@echo  Building $@ 32-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@ CDEFS='$(DLL_DEFS)' DEBUG='Y' BITNESS=32

EXE_DEFS = -DUSE_ICON

all: $(TARGET) $(TARGET)-debug 

clean:
	-${RMDIR} $(TARGET)$(BUILDDIR_SUFFIXx32)         $(TARGET)-debug$(BUILDDIR_SUFFIXx32)

.PHONY: all clean 
.PHONY: $(TARGET) $(TARGET)-debug
