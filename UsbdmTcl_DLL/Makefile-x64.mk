include ../Common.mk

TARGET = usbdm-tcl

EXE_DEFS  = -DNEED_ALL_NAMES -DUSE_ICON -DINTERACTIVE
DLL_DEFS  = -DNEED_ALL_NAMES -DUSBDM_TCL_DLL_EXPORTS
TEST_DEFS = -DNEED_ALL_NAMES -DUSE_ICON -DTEST_APP

$(TARGET):
	@echo ''
	@echo  Building $@ 64-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@ CDEFS='$(DLL_DEFS)' BITNESS=64

$(TARGET)-debug:
	@echo ''
	@echo  Building $@ 64-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@ CDEFS='$(DLL_DEFS)'  DEBUG='Y' BITNESS=64

UsbdmScript:
	@echo ''
	@echo  Building $@ 64-bit
	@echo "================================================================"
	$(MAKE) exe -f Script.mk BUILDDIR=$@ TARGET=$@ MODULE=UsbdmScript CDEFS='$(EXE_DEFS)' BITNESS=64

UsbdmScript-debug:
	@echo ''
	@echo  Building $@ 64-bit
	@echo "================================================================"
	$(MAKE) exe -f Script.mk BUILDDIR=$@ TARGET=$@ MODULE=UsbdmScript CDEFS='$(EXE_DEFS)' DEBUG='Y' BITNESS=64

TestTclApp:
	@echo ''
	@echo  Building $@ 64-bit
	@echo "================================================================"
	$(MAKE) exe -f Target.mk BUILDDIR=$@ TARGET=$@ MODULE=$@ CDEFS='$(TEST_DEFS)' DEBUG='Y' BITNESS=64

all: $(TARGET) $(TARGET)-debug
all: UsbdmScript UsbdmScript-debug 
all: TestTclApp

clean:
	-${RMDIR} $(TARGET)$(BUILDDIR_SUFFIXx64)    $(TARGET)-debug$(BUILDDIR_SUFFIXx64)
	-${RMDIR} UsbdmScript$(BUILDDIR_SUFFIXx64)  UsbdmScript-debug$(BUILDDIR_SUFFIXx64)
	-${RMDIR} TestTclApp$(BUILDDIR_SUFFIXx64)

.PHONY: all clean 
.PHONY: $(TARGET) $(TARGET)-debug
.PHONY: UsbdmScript UsbdmScript-debug 
.PHONY: TestTclApp

