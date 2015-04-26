include ../Common.mk

TARGET = usbdm-dsc
MODULE = module

DLL_DEFS = -DTARGET=MC56F80xx -DUSBDMDSC_DLL_EXPORTS -DLINK_USBDM_SYSTEM_DLL

$(TARGET):
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) MODULE=$(MODULE)  CDEFS='$(DLL_DEFS)'

$(TARGET)-debug:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@${VSUFFIX} MODULE=$(MODULE)  CDEFS='$(DLL_DEFS)'  DEBUG='Y'

test:
	$(MAKE) exe -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@ MODULE=$@ CDEFS='$(DLL_DEFS)'  DEBUG='Y'

all:    $(TARGET) $(TARGET)-debug

clean:
	${RMDIR} $(TARGET)$(BUILDDIR_SUFFIX) $(TARGET)-debug$(BUILDDIR_SUFFIX)
	${RMDIR} test$(BUILDDIR_SUFFIX)

.PHONY: all clean 
.PHONY: $(TARGET) $(TARGET)-debug
.PHONY: test
