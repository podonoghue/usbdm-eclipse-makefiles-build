include ../Common.mk

TARGET = usbdm
MODULE = usbdm

DLL_DEFS = -DUSBDM_DLL_EXPORTS -DLINK_USBDM_SYSTEM_DLL

$(TARGET):
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@${VSUFFIX} MODULE=$(MODULE)  CDEFS='$(DLL_DEFS)'

$(TARGET)-debug:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@${VSUFFIX} MODULE=$(MODULE)  CDEFS='$(DLL_DEFS)'  DEBUG='Y'

osbdm-jm60:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@ TARGET=$@  MODULE=osbdm      CDEFS='$(DLL_DEFS)'

osbdm-jm60-debug:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@ TARGET=$@  MODULE=osbdm      CDEFS='$(DLL_DEFS)'  DEBUG='Y'

usbdm-cff:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@ TARGET=$@  MODULE=cfflasher  CDEFS='$(DLL_DEFS)'  EXTRA_LINK_OPTS='-Wl,--kill-at' 

usbdm-cff-debug:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@ TARGET=$@  MODULE=cfflasher  CDEFS='$(DLL_DEFS)'  EXTRA_LINK_OPTS='-Wl,--kill-at'  DEBUG='Y'

allCommon: $(TARGET) $(TARGET)-debug

cleanCommon:
	-${RMDIR} $(TARGET)$(BUILDDIR_SUFFIX) $(TARGET)-debug$(BUILDDIR_SUFFIX)

ifeq ($(UNAME_S),Windows)
allWindows: osbdm-jm60 osbdm-jm60-debug usbdm-cff usbdm-cff-debug

cleanWindows:
	${RMDIR} osbdm-jm60 osbdm-jm60-debug
	${RMDIR} usbdm-cff  usbdm-cff-debug
else
allWindows:
cleanWindows:
endif

all: allCommon allWindows

clean: cleanCommon cleanWindows

test: $(TARGET)-debug

.PHONY: all clean 
.PHONY: $(TARGET) $(TARGET)-debug
.PHONY: allCommon allWindows cleanCommon cleanWindows
.PHONY: osbdm-jm60 osbdm-jm60-debug usbdm-cff usbdm-cff-debug
.PHONY: test
