include ../Common.mk

TARGET  = usbdm-flash-image
MODULE = module
TEST_MODULE = test

DLL_DEFS ='-DCOMPILE_FLASH_IMAGE_DLL'

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

EXE_DEFS = -DUSE_ICON

$(TARGET)-test:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) exe -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@ MODULE=$(TEST_MODULE) CDEFS='$(EXE_DEFS)'

$(TARGET)-debug-test:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) exe -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@ MODULE=$(TEST_MODULE) CDEFS='$(EXE_DEFS)' DEBUG='Y'

all: $(TARGET) $(TARGET)-debug $(TARGET)-test $(TARGET)-debug-test

clean:
	${RMDIR} $(TARGET)$(BUILDDIR_SUFFIX)   
	${RMDIR} $(TARGET)-debug$(BUILDDIR_SUFFIX)
	${RMDIR} $(TARGET)-test$(BUILDDIR_SUFFIX)   
	${RMDIR} $(TARGET)-debug-test$(BUILDDIR_SUFFIX)

.PHONY: all clean 
.PHONY: $(TARGET) $(TARGET)-debug $(TARGET)-test $(TARGET)-debug-test
