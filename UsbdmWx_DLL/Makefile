include ../Common.mk

DEFS = -DMINIMAL_APP=wxPluginApp

TestWx-debug:
	@echo
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) exe -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) MODULE=TestWx TARGET=$@ CDEFS='$(DEFS)' DEBUG='Y'

# Always enable debugging
usbdm-wx-plugin:
	@echo
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) MODULE=wxPlugin TARGET=$@$(VSUFFIX) CDEFS='$(DEFS) -DCOMPILE_WX_PLUGIN_DLL'  DEBUG='Y'
	
usbdm-wx-plugin-debug:
	@echo
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) MODULE=wxPlugin TARGET=$@$(VSUFFIX) CDEFS='$(DEFS) -DCOMPILE_WX_PLUGIN_DLL' DEBUG='Y'

all: usbdm-wx-plugin-debug usbdm-wx-plugin 
all: TestWx-debug 

clean:
	${RMDIR} TestWx-debug$(BUILDDIR_SUFFIX) usbdm-wx-plugin-debug$(BUILDDIR_SUFFIX) usbdm-wx-plugin$(BUILDDIR_SUFFIX)

.PHONY: all clean 
.PHONY: TestWx-debug  usbdm-wx-plugin usbdm-wx-plugin-debug
