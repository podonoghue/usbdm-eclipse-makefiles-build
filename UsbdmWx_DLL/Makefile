include ../Common.mk

DEFS = -DMINIMAL_APP=wxPluginApp

ExampleWxApp-debug:
	@echo
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) exe -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) MODULE=wxPluginExample TARGET=$@ CDEFS='$(DEFS)' DEBUG='Y'

usbdm-wx-plugin:
	@echo
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) MODULE=wxPlugin TARGET=$@$(VSUFFIX) CDEFS='$(DEFS) -DCOMPILE_WX_PLUGIN_DLL'
	
usbdm-wx-plugin-debug:
	@echo
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) MODULE=wxPlugin TARGET=$@$(VSUFFIX) CDEFS='$(DEFS) -DCOMPILE_WX_PLUGIN_DLL' DEBUG='Y'

all: usbdm-wx-plugin-debug usbdm-wx-plugin 
all: ExampleWxApp-debug 

clean:
	${RMDIR} ExampleWxApp-debug$(BUILDDIR_SUFFIX) usbdm-wx-plugin-debug$(BUILDDIR_SUFFIX) usbdm-wx-plugin$(BUILDDIR_SUFFIX)

.PHONY: all clean 
.PHONY: ExampleWxApp-debug  usbdm-wx-plugin usbdm-wx-plugin-debug
