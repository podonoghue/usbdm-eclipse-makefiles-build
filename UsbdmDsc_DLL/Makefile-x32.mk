include ../Common.mk

TARGET = usbdm-dsc
             
DLL_DEFS = -DTARGET=MC56F80xx -DUSBDMDSC_DLL_EXPORTS -DLINK_USBDM_SYSTEM_DLL

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

test:
	@echo ''
	@echo  Building $@ 32-bit
	@echo "================================================================"
	$(MAKE) exe -f Target.mk BUILDDIR=$@ CDEFS='$(DLL_DEFS)'  DEBUG='Y' BITNESS=32

all: $(TARGET) $(TARGET)-debug

clean:
	${RMDIR} $(TARGET)$(BUILDDIR_SUFFIXx32) $(TARGET)-debug$(BUILDDIR_SUFFIXx32)
	${RMDIR} test$(BUILDDIR_SUFFIXx32)

.PHONY: all clean 
.PHONY: $(TARGET) $(TARGET)-debug
.PHONY: test
