include ../Common.mk

TARGET = usbdm-wx-plugin

DEFS = -DMINIMAL_APP=wxPluginApp

$(TARGET)::
	@echo ''
	@echo  Building $@ 32-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@ CDEFS='$(DEFS) -DCOMPILE_WX_PLUGIN_DLL' BITNESS=32

$(TARGET)-debug::
	@echo ''
	@echo  Building $@ 32-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@ CDEFS='$(DEFS) -DCOMPILE_WX_PLUGIN_DLL' DEBUG='Y' BITNESS=32

TestWx-debug::
	@echo ''
	@echo  Building $@ 32-bit
	@echo "================================================================"
	$(MAKE) exe -f Target.mk BUILDDIR=$@ MODULE=TestWx TARGET=$@ CDEFS='$(DEFS)' DEBUG='Y' BITNESS=32

all:: $(TARGET) $(TARGET)-debug
all:: TestWx-debug 

clean::
	-${RMDIR} $(TARGET)$(BUILDDIR_SUFFIXx32) $(TARGET)-debug$(BUILDDIR_SUFFIXx32)
	-${RMDIR} TestWx-debug$(BUILDDIR_SUFFIXx32)

.PHONY: all clean 
.PHONY: $(TARGET) $(TARGET)-debug
.PHONY: TestWx-debug
