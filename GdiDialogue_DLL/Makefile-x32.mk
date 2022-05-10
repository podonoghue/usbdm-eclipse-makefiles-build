include ../Common.mk

EXE_DEFS = -DUSE_ICON -DLEGACY -DMINIMAL_APP=gdiDialoguePluginApp

usbdm-gdi-dialogue:
	@echo ''
	@echo  Building $@ 32-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@ MODULE=GdiDialoguePlugin CDEFS='$(EXE_DEFS) -DCOMPILE_GDI_DIALOGUE_PLUGIN_DLL' BITNESS=32
	
usbdm-gdi-dialogue-debug:
	@echo ''
	@echo  Building $@ 32-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@ MODULE=GdiDialoguePlugin CDEFS='$(EXE_DEFS) -DCOMPILE_GDI_DIALOGUE_PLUGIN_DLL' DEBUG='Y' BITNESS=32

TestGdiDialogueApp:
	@echo ''
	@echo  Building $@ 32-bit
	@echo "================================================================"
	$(MAKE) exe -f Target.mk BUILDDIR=$@ MODULE=TestGdiDialogueApp TARGET=$@ CDEFS='$(EXE_DEFS)' BITNESS=32

TestGdiDialogueApp-debug:
	@echo ''
	@echo  Building $@ 32-bit
	@echo "================================================================"
	$(MAKE) exe -f Target.mk BUILDDIR=$@ MODULE=TestGdiDialogueApp TARGET=$@ CDEFS='$(EXE_DEFS)' DEBUG='Y' BITNESS=32

all: usbdm-gdi-dialogue-debug usbdm-gdi-dialogue TestGdiDialogueApp-debug TestGdiDialogueApp

clean:
	${RMDIR} TestGdiDialogueApp$(BUILDDIR_SUFFIX) TestGdiDialogueApp-debug$(BUILDDIR_SUFFIX)
	${RMDIR} usbdm-gdi-dialogue$(BUILDDIR_SUFFIXx32)      usbdm-gdi-dialogue-debug$(BUILDDIR_SUFFIXx32)

.PHONY: all clean 
.PHONY: TestGdiDialogueApp TestGdiDialogueApp-debug  usbdm-gdi-dialogue usbdm-gdi-dialogue-debug
