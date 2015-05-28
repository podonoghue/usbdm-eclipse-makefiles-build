include ../Common.mk

EXE_DEFS = -DUSE_ICON -DLEGACY -DMINIMAL_APP=gdiDialoguePluginApp

TestGdiDialogueApp-debug:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) exe -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) MODULE=TestGdiDialogueApp TARGET=$@ CDEFS='$(EXE_DEFS)' DEBUG='Y'

usbdm-gdi-dialogue:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) MODULE=GdiDialoguePlugin TARGET=$@$(VSUFFIX) CDEFS='$(EXE_DEFS) -DCOMPILE_GDI_DIALOGUE_PLUGIN_DLL'
	
usbdm-gdi-dialogue-debug:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) MODULE=GdiDialoguePlugin TARGET=$@$(VSUFFIX) CDEFS='$(EXE_DEFS) -DCOMPILE_GDI_DIALOGUE_PLUGIN_DLL' DEBUG='Y'

all: TestGdiDialogueApp-debug usbdm-gdi-dialogue-debug usbdm-gdi-dialogue 

clean:
	${RMDIR} TestGdiDialogueApp-debug$(BUILDDIR_SUFFIX) usbdm-gdi-dialogue-debug$(BUILDDIR_SUFFIX) usbdm-gdi-dialogue$(BUILDDIR_SUFFIX)

.PHONY: all clean 
.PHONY: TestGdiDialogueApp-debug  usbdm-gdi-dialogue usbdm-gdi-dialogue-debug
