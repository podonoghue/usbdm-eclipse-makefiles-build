
include ../Common.mk

TARGET = UsbdmFlashProgrammer
MODULE = module

EXE_DEFS = -DFLASH_PROGRAMMER -DUSE_ICON

$(TARGET):
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) exe -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) MODULE=$(MODULE) TARGET=$@ CDEFS='$(EXE_DEFS)'

$(TARGET)-debug:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) exe -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) MODULE=$(MODULE) TARGET=$@ CDEFS='$(EXE_DEFS)' DEBUG='Y'

all: $(TARGET) $(TARGET)-debug

clean:
	${RMDIR} $(TARGET)$(BUILDDIR_SUFFIX) $(TARGET)-debug$(BUILDDIR_SUFFIX)

.PHONY: all clean 
.PHONY: $(TARGET) $(TARGET)-debug