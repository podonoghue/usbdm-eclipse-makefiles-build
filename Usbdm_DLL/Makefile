include ../Common.mk

TARGET := usbdm

DLL_DEFS := -DUSBDM_DLL_EXPORTS -DLINK_USBDM_SYSTEM_DLL

$(TARGET):
	@echo ''
	@echo  Building $@ 64-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@ MODULE=usbdm CDEFS='$(DLL_DEFS)' BITNESS=64
	@echo ''
	@echo  Building $@ 32-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@ MODULE=usbdm CDEFS='$(DLL_DEFS)' BITNESS=32

$(TARGET)-debug:
	@echo ''
	@echo  Building $@ 64-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@ MODULE=usbdm CDEFS='$(DLL_DEFS)' DEBUG='Y' BITNESS=64
	@echo ''
	@echo  Building $@ 32-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@ MODULE=usbdm CDEFS='$(DLL_DEFS)' DEBUG='Y' BITNESS=32
	
$(TARGET)-static:
	@echo ''
	@echo  Building $@ 32-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@ MODULE=usbdm CDEFS='$(DLL_DEFS)' LFLAGS='$(STATIC_GCC_OPTION)' BITNESS=32
	@echo ''
	@echo  Building $@ 64-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@ MODULE=usbdm CDEFS='$(DLL_DEFS)' LFLAGS='$(STATIC_GCC_OPTION)' BITNESS=64

$(TARGET)-static-debug:
	@echo ''
	@echo  Building $@ 32-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@ MODULE=usbdm CDEFS='$(DLL_DEFS)'  LFLAGS='$(STATIC_GCC_OPTION)' DEBUG='Y' BITNESS=32
	@echo ''
	@echo  Building $@ 64-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@ MODULE=usbdm CDEFS='$(DLL_DEFS)'  LFLAGS='$(STATIC_GCC_OPTION)' DEBUG='Y' BITNESS=64

osbdm-jm60:
	@echo ''
	@echo  Building $@ 32-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@ TARGET=$@ MODULE=osbdm      CDEFS='$(DLL_DEFS)' BITNESS=32

osbdm-jm60-debug:
	@echo ''
	@echo  Building $@ 32-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@ TARGET=$@ MODULE=osbdm      CDEFS='$(DLL_DEFS)'  DEBUG='Y' BITNESS=32

usbdm-cff:
	@echo ''
	@echo  Building $@ 32-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@ TARGET=$@ MODULE=cfflasher  CDEFS='$(DLL_DEFS)'  EXTRA_LINK_OPTS='-Wl,--kill-at'  BITNESS=32

usbdm-cff-debug:
	@echo ''
	@echo  Building $@ 32-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@ TARGET=$@ MODULE=cfflasher  CDEFS='$(DLL_DEFS)'  EXTRA_LINK_OPTS='-Wl,--kill-at'  DEBUG='Y' BITNESS=32

allCommon: $(TARGET) $(TARGET)-debug

cleanCommon:
	-${RMDIR} $(TARGET)$(BUILDDIR_SUFFIXx32) $(TARGET)-debug$(BUILDDIR_SUFFIXx32)
	-${RMDIR} $(TARGET)$(BUILDDIR_SUFFIXx64) $(TARGET)-debug$(BUILDDIR_SUFFIXx64)
	-${RMDIR} $(TARGET)-static$(BUILDDIR_SUFFIXx32) $(TARGET)-static-debug$(BUILDDIR_SUFFIXx32)  
	-${RMDIR} $(TARGET)-static$(BUILDDIR_SUFFIXx64) $(TARGET)-static-debug$(BUILDDIR_SUFFIXx64)  

ifeq ($(UNAME_S),Windows)
allWindows: osbdm-jm60 osbdm-jm60-debug usbdm-cff usbdm-cff-debug 
allWindows: $(TARGET)-static $(TARGET)-static-debug

cleanWindows:
	${RMDIR} osbdm-jm60${BUILDDIR_SUFFIXx32} osbdm-jm60-debug${BUILDDIR_SUFFIXx32}
	${RMDIR} usbdm-cff${BUILDDIR_SUFFIXx32}  usbdm-cff-debug${BUILDDIR_SUFFIXx32}
	${RMDIR} $(TARGET)-static$(BUILDDIR_SUFFIXx32) $(TARGET)-static-debug$(BUILDDIR_SUFFIXx32)
else
allWindows:
cleanWindows:
endif

all: allCommon allWindows

clean: cleanCommon cleanWindows

test: $(TARGET)-debug

.PHONY: all clean 
.PHONY: $(TARGET) 
.PHONY: $(TARGET)-debug
.PHONY: $(TARGET)-static 
.PHONY: $(TARGET)-static-debug
.PHONY: allCommon allWindows cleanCommon cleanWindows
.PHONY: osbdm-jm60 osbdm-jm60-debug usbdm-cff usbdm-cff-debug
.PHONY: test
