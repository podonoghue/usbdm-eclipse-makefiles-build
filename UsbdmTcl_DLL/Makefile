include ../Common.mk

TARGET = usbdm-tcl
MODULE = module

EXE_DEFS  = -DNEED_ALL_NAMES -DUSE_ICON -DINTERACTIVE
DLL_DEFS  = -DNEED_ALL_NAMES -DUSBDM_TCL_DLL_EXPORTS
TEST_DEFS = -DNEED_ALL_NAMES -DUSE_ICON -DTEST_APP

$(TARGET):
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) MODULE=$(MODULE) CDEFS='$(DLL_DEFS)'

$(TARGET)-debug:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) MODULE=$(MODULE) CDEFS='$(DLL_DEFS)'  DEBUG='Y'

UsbdmScript:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) exe -f Script.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@ MODULE=UsbdmScript CDEFS='$(EXE_DEFS)'

UsbdmScript-debug:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) exe -f Script.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@ MODULE=UsbdmScript CDEFS='$(EXE_DEFS)' DEBUG='Y'

TestTclApp:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) exe -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@ MODULE=$@ CDEFS='$(TEST_DEFS)' DEBUG='Y'

all: $(TARGET) $(TARGET)-debug
all: UsbdmScript UsbdmScript-debug 
all: TestTclApp

clean:
	${RMDIR} $(TARGET)$(BUILDDIR_SUFFIX)   $(TARGET)-debug$(BUILDDIR_SUFFIX)
	${RMDIR} UsbdmScript$(BUILDDIR_SUFFIX) UsbdmScript-debug$(BUILDDIR_SUFFIX)
	${RMDIR} TestTclApp$(BUILDDIR_SUFFIX)

.PHONY: all clean 
.PHONY: $(TARGET) $(TARGET)-debug
.PHONY: UsbdmScript UsbdmScript-debug 
.PHONY: TestTclApp

