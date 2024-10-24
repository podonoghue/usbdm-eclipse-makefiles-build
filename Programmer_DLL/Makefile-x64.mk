include ../Common.mk

TARGET  = usbdm-programmer
   
DLL_DEFS ='-DCOMPILE_FLASHPROGRAMMER_DLL'

$(TARGET)-arm:
	@echo ''
	@echo  Building $@ 64-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-arm BUILDDIR=$@ CDEFS=$(DLL_DEFS)  BITNESS=64

$(TARGET)-arm-debug:
	@echo ''
	@echo  Building $@ 64-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-arm BUILDDIR=$@ CDEFS=$(DLL_DEFS) DEBUG='Y' BITNESS=64

$(TARGET)-cfv1:
	@echo ''
	@echo  Building $@ 64-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-cfv1 BUILDDIR=$@ CDEFS=$(DLL_DEFS)  BITNESS=64

$(TARGET)-cfv1-debug:
	@echo ''
	@echo  Building $@ 64-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-cfv1 BUILDDIR=$@ CDEFS=$(DLL_DEFS) DEBUG='Y' BITNESS=64

$(TARGET)-cfvx:
	@echo ''
	@echo  Building $@ 64-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-cfvx BUILDDIR=$@ CDEFS=$(DLL_DEFS)  BITNESS=64

$(TARGET)-cfvx-debug:
	@echo ''
	@echo  Building $@ 64-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-cfvx BUILDDIR=$@ CDEFS=$(DLL_DEFS) DEBUG='Y' BITNESS=64

$(TARGET)-dsc:
	@echo ''
	@echo  Building $@ 64-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-dsc BUILDDIR=$@ CDEFS=$(DLL_DEFS)  BITNESS=64

$(TARGET)-dsc-debug:
	@echo ''
	@echo  Building $@ 64-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-dsc BUILDDIR=$@ CDEFS=$(DLL_DEFS) DEBUG='Y' BITNESS=64

$(TARGET)-hcs08:
	@echo ''
	@echo  Building $@ 64-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-hcs08 BUILDDIR=$@ CDEFS=$(DLL_DEFS)  BITNESS=64

$(TARGET)-hcs08-debug:
	@echo ''
	@echo  Building $@ 64-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-hcs08 BUILDDIR=$@ CDEFS=$(DLL_DEFS) DEBUG='Y' BITNESS=64

$(TARGET)-hcs12:
	@echo ''
	@echo  Building $@ 64-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-hcs12 BUILDDIR=$@ CDEFS=$(DLL_DEFS)  BITNESS=64

$(TARGET)-hcs12-debug:
	@echo ''
	@echo  Building $@ 64-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-hcs12 BUILDDIR=$@ CDEFS=$(DLL_DEFS) DEBUG='Y' BITNESS=64

$(TARGET)-rs08:
	@echo ''
	@echo  Building $@ 64-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-rs08 BUILDDIR=$@ CDEFS=$(DLL_DEFS)  BITNESS=64

$(TARGET)-rs08-debug:
	@echo ''
	@echo  Building $@ 64-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-rs08 BUILDDIR=$@ CDEFS=$(DLL_DEFS) DEBUG='Y' BITNESS=64

$(TARGET)-s12z:
	@echo ''
	@echo  Building $@ 64-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-s12z BUILDDIR=$@ CDEFS=$(DLL_DEFS)  BITNESS=64

$(TARGET)-s12z-debug:
	@echo ''
	@echo  Building $@ 64-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-s12z BUILDDIR=$@ CDEFS=$(DLL_DEFS) DEBUG='Y' BITNESS=64

all: $(TARGET)-arm   $(TARGET)-arm-debug 
all: $(TARGET)-cfv1  $(TARGET)-cfv1-debug 
all: $(TARGET)-cfvx  $(TARGET)-cfvx-debug 
all: $(TARGET)-dsc   $(TARGET)-dsc-debug 
all: $(TARGET)-hcs08 $(TARGET)-hcs08-debug 
all: $(TARGET)-hcs12 $(TARGET)-hcs12-debug 
all: $(TARGET)-rs08  $(TARGET)-rs08-debug 
all: $(TARGET)-s12z  $(TARGET)-s12z-debug 

clean:
	${RMDIR} $(TARGET)-arm$(BUILDDIR_SUFFIXx64)     $(TARGET)-arm-debug$(BUILDDIR_SUFFIXx64)
	${RMDIR} $(TARGET)-cfv1$(BUILDDIR_SUFFIXx64)    $(TARGET)-cfv1-debug$(BUILDDIR_SUFFIXx64)
	${RMDIR} $(TARGET)-cfvx$(BUILDDIR_SUFFIXx64)    $(TARGET)-cfvx-debug$(BUILDDIR_SUFFIXx64)
	${RMDIR} $(TARGET)-hcs08$(BUILDDIR_SUFFIXx64)   $(TARGET)-hcs08-debug$(BUILDDIR_SUFFIXx64)
	${RMDIR} $(TARGET)-hcs12$(BUILDDIR_SUFFIXx64)   $(TARGET)-hcs12-debug$(BUILDDIR_SUFFIXx64)
	${RMDIR} $(TARGET)-rs08$(BUILDDIR_SUFFIXx64)    $(TARGET)-rs08-debug$(BUILDDIR_SUFFIXx64)
	${RMDIR} $(TARGET)-s12z$(BUILDDIR_SUFFIXx64)    $(TARGET)-s12z-debug$(BUILDDIR_SUFFIXx64)
	${RMDIR} $(TARGET)-dsc$(BUILDDIR_SUFFIXx64)     $(TARGET)-dsc-debug$(BUILDDIR_SUFFIXx64)

.PHONY: all clean
.PHONY: $(TARGET)-arm   $(TARGET)-arm-debug
.PHONY: $(TARGET)-cfv1  $(TARGET)-cfv1-debug
.PHONY: $(TARGET)-cfvx  $(TARGET)-cfvx-debug
.PHONY: $(TARGET)-hcs08 $(TARGET)-hcs08-debug
.PHONY: $(TARGET)-hcs12 $(TARGET)-hcs12-debug
.PHONY: $(TARGET)-rs08  $(TARGET)-rs08-debug
.PHONY: $(TARGET)-s12z  $(TARGET)-s12z-debug
.PHONY: $(TARGET)-dsc   $(TARGET)-dsc-debug
