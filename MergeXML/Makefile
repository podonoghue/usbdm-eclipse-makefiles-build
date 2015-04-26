include ../Common.mk

TARGET = MergeXML
MODULE = module

EXE_DEFS = -DUSE_ICON

ifeq ($(UNAME_S),Windows)
Version.o : src/Version.rc src/uacManifest.xml
	@echo -- Building $@ from $<
	$(WINDRES) $< $(DEFS) $(INCS) -o $@
endif

$(TARGET): # Version.o
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) exe -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) MODULE=$(MODULE) TARGET=$@ CDEFS='$(EXE_DEFS)'

$(TARGET)-debug: # Version.o
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) exe -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) MODULE=$(MODULE) TARGET=$@ CDEFS='$(EXE_DEFS)' DEBUG='Y'

all: $(TARGET) $(TARGET)-debug

clean:
	${RMDIR} $(TARGET)$(BUILDDIR_SUFFIX) $(TARGET)-debug$(BUILDDIR_SUFFIX)

.PHONY: all clean 
.PHONY: $(TARGET) $(TARGET)-debug