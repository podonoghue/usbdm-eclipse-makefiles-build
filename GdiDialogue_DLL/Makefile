include ../Common.mk

EXE_DEFS = -DUSE_ICON -DLEGACY -DMINIMAL_APP=gdiDialoguePluginApp

ExampleGdiDialogueApp-debug:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) exe -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) MODULE=ExampleGdiDialogueApp TARGET=$@ CDEFS='$(EXE_DEFS)' DEBUG='Y'

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

all: ExampleGdiDialogueApp-debug usbdm-gdi-dialogue-debug usbdm-gdi-dialogue 

clean:
	${RMDIR} ExampleGdiDialogueApp-debug$(BUILDDIR_SUFFIX) usbdm-gdi-dialogue-debug$(BUILDDIR_SUFFIX) usbdm-gdi-dialogue$(BUILDDIR_SUFFIX)

.PHONY: all clean 
.PHONY: ExampleGdiDialogueApp-debug  usbdm-gdi-dialogue usbdm-gdi-dialogue-debug
