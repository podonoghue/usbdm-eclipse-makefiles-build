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
	@echo  Building $@ 32-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-arm BUILDDIR=$@ CDEFS='$(GDI_DEFS) -DTARGET=ARM' BITNESS=32

$(TARGET)-arm-debug:
	@echo ''
	@echo  Building $@ 32-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-arm BUILDDIR=$@ CDEFS='$(GDI_DEFS) -DTARGET=ARM' DEBUG='Y' BITNESS=32

$(TARGET)-cfv1:
	@echo ''
	@echo  Building $@ 32-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-cfv1 BUILDDIR=$@ CDEFS='$(GDI_DEFS) -DTARGET=CFV1' BITNESS=32

$(TARGET)-cfv1-debug:
	@echo ''
	@echo  Building $@ 32-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-cfv1 BUILDDIR=$@ CDEFS='$(GDI_DEFS) -DTARGET=CFV1' DEBUG='Y' BITNESS=32

$(TARGET)-cfvx:
	@echo ''
	@echo  Building $@ 32-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-cfvx BUILDDIR=$@ CDEFS='$(GDI_DEFS) -DTARGET=CFVx' BITNESS=32

$(TARGET)-cfvx-debug:
	@echo ''
	@echo  Building $@ 32-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-cfvx BUILDDIR=$@ CDEFS='$(GDI_DEFS) -DTARGET=CFVx' DEBUG='Y' BITNESS=32

$(TARGET)-dsc:
	@echo ''
	@echo  Building $@ 32-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-dsc BUILDDIR=$@ CDEFS='$(GDI_DEFS) -DTARGET=MC56F80xx' BITNESS=32

$(TARGET)-dsc-debug:
	@echo ''
	@echo  Building $@ 32-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-dsc BUILDDIR=$@ CDEFS='$(GDI_DEFS) -DTARGET=MC56F80xx' DEBUG='Y' BITNESS=32

$(TARGET)-hcs08:
	@echo ''
	@echo  Building $@ 32-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-hcs08 BUILDDIR=$@ CDEFS='$(GDI_DEFS) -DTARGET=HCS08' BITNESS=32

$(TARGET)-hcs08-debug:
	@echo ''
	@echo  Building $@ 32-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-hcs08 BUILDDIR=$@ CDEFS='$(GDI_DEFS) -DTARGET=HCS08' DEBUG='Y' BITNESS=32

$(TARGET)-hcs12:
	@echo ''
	@echo  Building $@ 32-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-hcs12 BUILDDIR=$@ CDEFS='$(GDI_DEFS) -DTARGET=HCS12' BITNESS=32

$(TARGET)-hcs12-debug:
	@echo ''
	@echo  Building $@ 32-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-hcs12 BUILDDIR=$@ CDEFS='$(GDI_DEFS) -DTARGET=HCS12' DEBUG='Y' BITNESS=32

$(TARGET)-rs08:
	@echo ''
	@echo  Building $@ 32-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-rs08 BUILDDIR=$@ CDEFS='$(GDI_DEFS) -DTARGET=RS08' BITNESS=32

$(TARGET)-rs08-debug:
	@echo ''
	@echo  Building $@ 32-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-rs08 BUILDDIR=$@ CDEFS='$(GDI_DEFS) -DTARGET=RS08' DEBUG='Y' BITNESS=32

$(TARGET)-s12z:
	@echo ''
	@echo  Building $@ 32-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-s12z BUILDDIR=$@ CDEFS='$(GDI_DEFS) -DTARGET=S12Z' BITNESS=32

$(TARGET)-s12z-debug:
	@echo ''
	@echo  Building $@ 32-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-s12z BUILDDIR=$@ CDEFS='$(GDI_DEFS) -DTARGET=S12Z' DEBUG='Y' BITNESS=32

# Legacy GDI DLLs
#------------------------------------------------------------
GDI_LEGACY_DEFS := -DGDI
GDI_LEGACY_DEFS += -DLEGACY

$(TARGET)-cfvx-legacy:
	@echo ''
	@echo  Building $@ 32-bit
	@echo "================================================================"
	$(MAKE) dll -f LegacyTarget.mk MODULE=$(TARGET)-cfvx-legacy BUILDDIR=$@ CDEFS='$(GDI_LEGACY_DEFS) -DTARGET=CFVx' BITNESS=32

$(TARGET)-cfvx-legacy-debug:
	@echo ''
	@echo  Building $@ 32-bit
	@echo "================================================================" 
	$(MAKE) dll -f LegacyTarget.mk MODULE=$(TARGET)-cfvx-legacy BUILDDIR=$@ CDEFS='$(GDI_LEGACY_DEFS) -DTARGET=CFVx' DEBUG='Y' BITNESS=32

$(TARGET)-dsc-legacy:
	@echo ''
	@echo  Building $@ 32-bit
	@echo "================================================================"
	$(MAKE) dll -f LegacyTarget.mk MODULE=$(TARGET)-dsc-legacy BUILDDIR=$@ CDEFS='$(GDI_LEGACY_DEFS) -DTARGET=MC56F80xx' BITNESS=32

$(TARGET)-dsc-legacy-debug:
	@echo ''
	@echo  Building $@ 32-bit
	@echo "================================================================"
	$(MAKE) dll -f LegacyTarget.mk MODULE=$(TARGET)-dsc-legacy BUILDDIR=$@ CDEFS='$(GDI_LEGACY_DEFS) -DTARGET=MC56F80xx' DEBUG='Y' BITNESS=32

TestCFVxGDI-debug:
	@echo ''
	@echo  Building $@ 32-bit
	@echo "================================================================"
	$(MAKE) exe -f LegacyTarget.mk MODULE=TestCFVxGDI BUILDDIR=$@ TARGET=$@ CDEFS='$(GDI_LEGACY_DEFS) -DTARGET=CFVx -DTEST_APP=1' DEBUG='Y' BITNESS=32

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
	${RMDIR} $(TARGET)-arm$(BUILDDIR_SUFFIXx32)          $(TARGET)-arm-debug$(BUILDDIR_SUFFIXx32)
	${RMDIR} $(TARGET)-cfv1$(BUILDDIR_SUFFIXx32)         $(TARGET)-cfv1-debug$(BUILDDIR_SUFFIXx32)
	${RMDIR} $(TARGET)-cfvx$(BUILDDIR_SUFFIXx32)         $(TARGET)-cfvx-debug$(BUILDDIR_SUFFIXx32)
	${RMDIR} $(TARGET)-dsc$(BUILDDIR_SUFFIXx32)          $(TARGET)-dsc-debug$(BUILDDIR_SUFFIXx32)
	${RMDIR} $(TARGET)-hcs08$(BUILDDIR_SUFFIXx32)        $(TARGET)-hcs08-debug$(BUILDDIR_SUFFIXx32)
	${RMDIR} $(TARGET)-hcs12$(BUILDDIR_SUFFIXx32)        $(TARGET)-hcs12-debug$(BUILDDIR_SUFFIXx32)
	${RMDIR} $(TARGET)-rs08$(BUILDDIR_SUFFIXx32)         $(TARGET)-rs08-debug$(BUILDDIR_SUFFIXx32)
	${RMDIR} $(TARGET)-s12z$(BUILDDIR_SUFFIXx32)         $(TARGET)-s12z-debug$(BUILDDIR_SUFFIXx32)
	${RMDIR} $(TARGET)-cfvx-legacy$(BUILDDIR_SUFFIXx32)  $(TARGET)-cfvx-legacy-debug$(BUILDDIR_SUFFIXx32) 
	${RMDIR} $(TARGET)-dsc-legacy$(BUILDDIR_SUFFIXx32)   $(TARGET)-dsc-legacy-debug$(BUILDDIR_SUFFIXx32)
	${RMDIR} TestCFVxGDI-debug$(BUILDDIR_SUFFIXx32)
	
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
