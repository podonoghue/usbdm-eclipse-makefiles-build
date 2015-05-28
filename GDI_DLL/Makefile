include ../Common.mk

GDI_DEFS := -DGDI 

ifeq ($(UNAME_S),Windows)
# Windows version of Codewarrior packs structs for CW 10.x only
GDI_DEFS += -DPACK_STRUCTS=1
endif

TARGET   = usbdm-gdi

# Codewarrior 10.x GDI DLLs
#------------------------------------------------------------
$(TARGET)-arm:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-arm BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) CDEFS='$(GDI_DEFS) -DTARGET=ARM' 

$(TARGET)-arm-debug:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-arm BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) CDEFS='$(GDI_DEFS) -DTARGET=ARM' DEBUG='Y'

$(TARGET)-cfv1:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-cfv1 BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) CDEFS='$(GDI_DEFS) -DTARGET=CFV1' 

$(TARGET)-cfv1-debug:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-cfv1 BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) CDEFS='$(GDI_DEFS) -DTARGET=CFV1' DEBUG='Y'

$(TARGET)-cfvx:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-cfvx BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) CDEFS='$(GDI_DEFS) -DTARGET=CFVx' 

$(TARGET)-cfvx-debug:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-cfvx BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) CDEFS='$(GDI_DEFS) -DTARGET=CFVx' DEBUG='Y'

$(TARGET)-dsc:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-dsc BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) CDEFS='$(GDI_DEFS) -DTARGET=MC56F80xx' 

$(TARGET)-dsc-debug:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-dsc BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) CDEFS='$(GDI_DEFS) -DTARGET=MC56F80xx' DEBUG='Y'

$(TARGET)-hcs08:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-hcs08 BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) CDEFS='$(GDI_DEFS) -DTARGET=HCS08' 

$(TARGET)-hcs08-debug:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-hcs08 BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) CDEFS='$(GDI_DEFS) -DTARGET=HCS08' DEBUG='Y'

$(TARGET)-hcs12:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-hcs12 BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) CDEFS='$(GDI_DEFS) -DTARGET=HCS12' 

$(TARGET)-hcs12-debug:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-hcs12 BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) CDEFS='$(GDI_DEFS) -DTARGET=HCS12' DEBUG='Y'

$(TARGET)-rs08:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-rs08 BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) CDEFS='$(GDI_DEFS) -DTARGET=RS08' 

$(TARGET)-rs08-debug:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-rs08 BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) CDEFS='$(GDI_DEFS) -DTARGET=RS08' DEBUG='Y'

$(TARGET)-s12z:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-s12z BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) CDEFS='$(GDI_DEFS) -DTARGET=S12Z' 

$(TARGET)-s12z-debug:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-s12z BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) CDEFS='$(GDI_DEFS) -DTARGET=S12Z' DEBUG='Y'

# Legacy GDI DLLs
#------------------------------------------------------------
GDI_LEGACY_DEFS := -DGDI
GDI_LEGACY_DEFS += -DLEGACY

$(TARGET)-cfvx-legacy:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f LegacyTarget.mk MODULE=$(TARGET)-cfvx-legacy BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) CDEFS='$(GDI_LEGACY_DEFS) -DTARGET=CFVx'

$(TARGET)-cfvx-legacy-debug:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f LegacyTarget.mk MODULE=$(TARGET)-cfvx-legacy BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) CDEFS='$(GDI_LEGACY_DEFS) -DTARGET=CFVx' DEBUG='Y'

$(TARGET)-dsc-legacy:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f LegacyTarget.mk MODULE=$(TARGET)-dsc-legacy BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) CDEFS='$(GDI_LEGACY_DEFS) -DTARGET=MC56F80xx'

$(TARGET)-dsc-legacy-debug:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f LegacyTarget.mk MODULE=$(TARGET)-dsc-legacy BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) CDEFS='$(GDI_LEGACY_DEFS) -DTARGET=MC56F80xx' DEBUG='Y'

TestCFVxGDI-debug:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) exe -f LegacyTarget.mk MODULE=TestCFVxGDI BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) CDEFS='$(GDI_LEGACY_DEFS) -DTARGET=CFVx -DTEST_APP=1' DEBUG='Y'

#------------------------------------------------------------

all: $(TARGET)-arm          $(TARGET)-arm-debug 
all: $(TARGET)-cfv1         $(TARGET)-cfv1-debug 
all: $(TARGET)-cfvx         $(TARGET)-cfvx-debug 
all: $(TARGET)-dsc          $(TARGET)-dsc-debug 
all: $(TARGET)-hcs08        $(TARGET)-hcs08-debug 
all: $(TARGET)-hcs12        $(TARGET)-hcs12-debug 
all: $(TARGET)-rs08         $(TARGET)-rs08-debug 
all: $(TARGET)-s12z         $(TARGET)-s12z-debug 
all: $(TARGET)-cfvx-legacy  $(TARGET)-cfvx-legacy-debug TestCFVxGDI-debug
all: $(TARGET)-dsc-legacy   $(TARGET)-dsc-legacy-debug

clean:
	${RMDIR} $(TARGET)-arm$(BUILDDIR_SUFFIX)          $(TARGET)-arm-debug$(BUILDDIR_SUFFIX)
	${RMDIR} $(TARGET)-cfv1$(BUILDDIR_SUFFIX)         $(TARGET)-cfv1-debug$(BUILDDIR_SUFFIX)
	${RMDIR} $(TARGET)-cfvx$(BUILDDIR_SUFFIX)         $(TARGET)-cfvx-debug$(BUILDDIR_SUFFIX)
	${RMDIR} $(TARGET)-dsc$(BUILDDIR_SUFFIX)          $(TARGET)-dsc-debug$(BUILDDIR_SUFFIX)
	${RMDIR} $(TARGET)-hcs08$(BUILDDIR_SUFFIX)        $(TARGET)-hcs08-debug$(BUILDDIR_SUFFIX)
	${RMDIR} $(TARGET)-hcs12$(BUILDDIR_SUFFIX)        $(TARGET)-hcs12-debug$(BUILDDIR_SUFFIX)
	${RMDIR} $(TARGET)-rs08$(BUILDDIR_SUFFIX)         $(TARGET)-rs08-debug$(BUILDDIR_SUFFIX)
	${RMDIR} $(TARGET)-s12z$(BUILDDIR_SUFFIX)         $(TARGET)-s12z-debug$(BUILDDIR_SUFFIX)
	${RMDIR} $(TARGET)-cfvx-legacy$(BUILDDIR_SUFFIX)  $(TARGET)-cfvx-legacy-debug$(BUILDDIR_SUFFIX) TestCFVxGDI-debug$(BUILDDIR_SUFFIX)
	${RMDIR} $(TARGET)-dsc-legacy$(BUILDDIR_SUFFIX)   $(TARGET)-dsc-legacy-debug$(BUILDDIR_SUFFIX)

.PHONY: all clean
.PHONY: $(TARGET)-arm          $(TARGET)-arm-debug
.PHONY: $(TARGET)-cfv1         $(TARGET)-cfv1-debug
.PHONY: $(TARGET)-cfvx         $(TARGET)-cfvx-debug
.PHONY: $(TARGET)-dsc          $(TARGET)-dsc-debug
.PHONY: $(TARGET)-hcs08        $(TARGET)-hcs08-debug
.PHONY: $(TARGET)-hcs12        $(TARGET)-hcs12-debug
.PHONY: $(TARGET)-rs08         $(TARGET)-rs08-debug
.PHONY: $(TARGET)-s12z         $(TARGET)-s12z-debug
.PHONY: $(TARGET)-cfvx-legacy  $(TARGET)-cfvx-legacy-debug TestCFVxGDI-debug
.PHONY: $(TARGET)-dsc-legacy   $(TARGET)-dsc-legacy-debug
