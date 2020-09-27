include ../Common.mk

TARGET = MergeXML

EXE_DEFS = -DUSE_ICON

ifeq ($(UNAME_S),Windows)
Version.o : src/Version.rc src/uacManifest.xml
	@echo -- Building $@ from $<
	$(WINDRES) $< $(DEFS) $(INCS) -o $@
endif

$(TARGET):
	@echo ''
	@echo  Building $@ 64-bit
	@echo "================================================================"
	$(MAKE) exe -f Target.mk BUILDDIR=$@ TARGET=$@ CDEFS='$(EXE_DEFS)' BITNESS=64

$(TARGET)-debug:
	@echo ''
	@echo  Building $@ 64-bit
	@echo "================================================================"
	$(MAKE) exe -f Target.mk BUILDDIR=$@ TARGET=$@ CDEFS='$(EXE_DEFS)' DEBUG='Y' BITNESS=64

all: $(TARGET) $(TARGET)-debug

clean:
	${RMDIR} $(TARGET)$(BUILDDIR_SUFFIXx64) $(TARGET)-debug$(BUILDDIR_SUFFIXx64)

.PHONY: all clean 
.PHONY: $(TARGET) $(TARGET)-debug