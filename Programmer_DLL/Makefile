include ../Common.mk

TARGET  = usbdm-programmer
   
DLL_DEFS ='-DCOMPILE_FLASHPROGRAMMER_DLL'

$(TARGET)-arm:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-arm BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) CDEFS=$(DLL_DEFS) 

$(TARGET)-arm-debug:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-arm BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) CDEFS=$(DLL_DEFS) DEBUG='Y'

$(TARGET)-cfv1:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-cfv1 BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) CDEFS=$(DLL_DEFS) 

$(TARGET)-cfv1-debug:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-cfv1 BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) CDEFS=$(DLL_DEFS) DEBUG='Y'

$(TARGET)-cfvx:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-cfvx BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) CDEFS=$(DLL_DEFS) 

$(TARGET)-cfvx-debug:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-cfvx BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) CDEFS=$(DLL_DEFS) DEBUG='Y'

$(TARGET)-dsc:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-dsc BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) CDEFS=$(DLL_DEFS) 

$(TARGET)-dsc-debug:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-dsc BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) CDEFS=$(DLL_DEFS) DEBUG='Y'

$(TARGET)-hcs08:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-hcs08 BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) CDEFS=$(DLL_DEFS) 

$(TARGET)-hcs08-debug:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-hcs08 BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) CDEFS=$(DLL_DEFS) DEBUG='Y'

$(TARGET)-hcs12:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-hcs12 BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) CDEFS=$(DLL_DEFS) 

$(TARGET)-hcs12-debug:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-hcs12 BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) CDEFS=$(DLL_DEFS) DEBUG='Y'

$(TARGET)-rs08:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-rs08 BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) CDEFS=$(DLL_DEFS) 

$(TARGET)-rs08-debug:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-rs08 BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) CDEFS=$(DLL_DEFS) DEBUG='Y'

$(TARGET)-s12z:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-s12z BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) CDEFS=$(DLL_DEFS) 

$(TARGET)-s12z-debug:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk MODULE=$(TARGET)-s12z BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) CDEFS=$(DLL_DEFS) DEBUG='Y'

all: $(TARGET)-arm   $(TARGET)-arm-debug 
all: $(TARGET)-cfv1  $(TARGET)-cfv1-debug 
all: $(TARGET)-cfvx  $(TARGET)-cfvx-debug 
all: $(TARGET)-dsc   $(TARGET)-dsc-debug 
all: $(TARGET)-hcs08 $(TARGET)-hcs08-debug 
all: $(TARGET)-hcs12 $(TARGET)-hcs12-debug 
all: $(TARGET)-rs08  $(TARGET)-rs08-debug 
all: $(TARGET)-s12z  $(TARGET)-s12z-debug 

clean:
	${RMDIR} $(TARGET)-arm$(BUILDDIR_SUFFIX)     $(TARGET)-arm-debug$(BUILDDIR_SUFFIX)
	${RMDIR} $(TARGET)-cfv1$(BUILDDIR_SUFFIX)    $(TARGET)-cfv1-debug$(BUILDDIR_SUFFIX)
	${RMDIR} $(TARGET)-cfvx$(BUILDDIR_SUFFIX)    $(TARGET)-cfvx-debug$(BUILDDIR_SUFFIX)
	${RMDIR} $(TARGET)-dsc$(BUILDDIR_SUFFIX)     $(TARGET)-dsc-debug$(BUILDDIR_SUFFIX)
	${RMDIR} $(TARGET)-hcs08$(BUILDDIR_SUFFIX)   $(TARGET)-hcs08-debug$(BUILDDIR_SUFFIX)
	${RMDIR} $(TARGET)-hcs12$(BUILDDIR_SUFFIX)   $(TARGET)-hcs12-debug$(BUILDDIR_SUFFIX)
	${RMDIR} $(TARGET)-rs08$(BUILDDIR_SUFFIX)    $(TARGET)-rs08-debug$(BUILDDIR_SUFFIX)
	${RMDIR} $(TARGET)-s12z$(BUILDDIR_SUFFIX)    $(TARGET)-s12z-debug$(BUILDDIR_SUFFIX)

.PHONY: all clean
.PHONY: $(TARGET)-arm   $(TARGET)-arm-debug
.PHONY: $(TARGET)-cfv1  $(TARGET)-cfv1-debug
.PHONY: $(TARGET)-cfvx  $(TARGET)-cfvx-debug
.PHONY: $(TARGET)-dsc   $(TARGET)-dsc-debug
.PHONY: $(TARGET)-hcs08 $(TARGET)-hcs08-debug
.PHONY: $(TARGET)-hcs12 $(TARGET)-hcs12-debug
.PHONY: $(TARGET)-rs08  $(TARGET)-rs08-debug
.PHONY: $(TARGET)-s12z  $(TARGET)-s12z-debug
