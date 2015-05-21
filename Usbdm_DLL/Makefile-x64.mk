include ../Common-x64.mk

TARGET = usbdm
MODULE = usbdm

DLL_DEFS = -DUSBDM_DLL_EXPORTS -DLINK_USBDM_SYSTEM_DLL

$(TARGET):
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target-x64.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@${VSUFFIX}     MODULE=$(MODULE)  CDEFS='$(DLL_DEFS)'

$(TARGET)-debug:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target-x64.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@${VSUFFIX}     MODULE=$(MODULE)  CDEFS='$(DLL_DEFS)'  DEBUG='Y'

all: $(TARGET) $(TARGET)-debug

clean:
	-${RMDIR} $(TARGET)$(BUILDDIR_SUFFIX) $(TARGET)-debug$(BUILDDIR_SUFFIX)

.PHONY: all clean 
.PHONY: $(TARGET) $(TARGET)-debug
