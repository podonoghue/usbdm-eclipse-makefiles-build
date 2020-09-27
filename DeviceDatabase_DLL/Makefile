include ../Common.mk

TARGET  = usbdm-device-database
             
DLL_DEFS ='-DCOMPILE_DEVICE_DATA_DLL'

$(TARGET):
	@echo ''
	@echo  Building $@ 64-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@ CDEFS='$(DLL_DEFS)' BITNESS=64
	@echo ''
	@echo  Building $@ 32-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@ CDEFS='$(DLL_DEFS)' BITNESS=32

$(TARGET)-debug:
	@echo ''
	@echo  Building $@ 64-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@ CDEFS='$(DLL_DEFS)' DEBUG='Y' BITNESS=64
	@echo ''
	@echo  Building $@ 32-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@ CDEFS='$(DLL_DEFS)' DEBUG='Y' BITNESS=32

all: $(TARGET) $(TARGET)-debug

clean:
	-${RMDIR} $(TARGET)$(BUILDDIR_SUFFIXx32) $(TARGET)-debug$(BUILDDIR_SUFFIXx32)
	-${RMDIR} $(TARGET)$(BUILDDIR_SUFFIXx64) $(TARGET)-debug$(BUILDDIR_SUFFIXx64)

.PHONY: all clean 
.PHONY: $(TARGET) $(TARGET)-debug
