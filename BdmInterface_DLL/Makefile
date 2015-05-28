include ../Common.mk

TARGET = usbdm-interface
MODULE = bdm-interface

DLL_DEFS ='-DCOMPILE_USBDM_INTERFACE_DLL'

$(TARGET)-arm:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) MODULE=$(MODULE)-arm CDEFS='$(DLL_DEFS)'

$(TARGET)-arm-debug:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) MODULE=$(MODULE)-arm CDEFS='$(DLL_DEFS)'  DEBUG='Y'

$(TARGET)-cfv1:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) MODULE=$(MODULE)-cfv1 CDEFS='$(DLL_DEFS)'

$(TARGET)-cfv1-debug:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) MODULE=$(MODULE)-cfv1 CDEFS='$(DLL_DEFS)'  DEBUG='Y'

$(TARGET)-cfvx:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) MODULE=$(MODULE)-cfvx CDEFS='$(DLL_DEFS)'

$(TARGET)-cfvx-debug:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) MODULE=$(MODULE)-cfvx CDEFS='$(DLL_DEFS)'  DEBUG='Y'

$(TARGET)-hcs08:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) MODULE=$(MODULE)-hcs08 CDEFS='$(DLL_DEFS)'

$(TARGET)-hcs08-debug:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) MODULE=$(MODULE)-hcs08 CDEFS='$(DLL_DEFS)'  DEBUG='Y'

$(TARGET)-hcs12:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) MODULE=$(MODULE)-hcs12 CDEFS='$(DLL_DEFS)'

$(TARGET)-hcs12-debug:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) MODULE=$(MODULE)-hcs12 CDEFS='$(DLL_DEFS)'  DEBUG='Y'

$(TARGET)-rs08:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) MODULE=$(MODULE)-rs08 CDEFS='$(DLL_DEFS)'

$(TARGET)-rs08-debug:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) MODULE=$(MODULE)-rs08 CDEFS='$(DLL_DEFS)'  DEBUG='Y'

$(TARGET)-s12z:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) MODULE=$(MODULE)-s12z CDEFS='$(DLL_DEFS)'

$(TARGET)-s12z-debug:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) MODULE=$(MODULE)-s12z CDEFS='$(DLL_DEFS)'  DEBUG='Y'

$(TARGET)-jtag:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) MODULE=$(MODULE)-jtag CDEFS='$(DLL_DEFS)'

$(TARGET)-jtag-debug:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) MODULE=$(MODULE)-jtag CDEFS='$(DLL_DEFS)'  DEBUG='Y'

$(TARGET)-dsc:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f dscTarget.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) MODULE=$(MODULE)-dsc CDEFS='$(DLL_DEFS)'

$(TARGET)-dsc-debug:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f dscTarget.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@$(VSUFFIX) MODULE=$(MODULE)-dsc CDEFS='$(DLL_DEFS)'  DEBUG='Y'

TestBdmInterface-debug:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) exe -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@ MODULE=TestBdmInterface DEBUG='Y'

all: $(TARGET)-arm $(TARGET)-arm-debug
all: $(TARGET)-cfv1 $(TARGET)-cfv1-debug
all: $(TARGET)-cfvx $(TARGET)-cfvx-debug
all: $(TARGET)-hcs08 $(TARGET)-hcs08-debug
all: $(TARGET)-hcs12 $(TARGET)-hcs12-debug
all: $(TARGET)-rs08 $(TARGET)-rs08-debug
all: $(TARGET)-s12z $(TARGET)-s12z-debug
all: $(TARGET)-jtag $(TARGET)-jtag-debug
all: $(TARGET)-dsc $(TARGET)-dsc-debug
all: TestBdmInterface-debug

clean:
	${RMDIR} $(TARGET)-arm$(BUILDDIR_SUFFIX)   $(TARGET)-arm-debug$(BUILDDIR_SUFFIX)
	${RMDIR} $(TARGET)-cfv1$(BUILDDIR_SUFFIX)   $(TARGET)-cfv1-debug$(BUILDDIR_SUFFIX)
	${RMDIR} $(TARGET)-cfvx$(BUILDDIR_SUFFIX)   $(TARGET)-cfvx-debug$(BUILDDIR_SUFFIX)
	${RMDIR} $(TARGET)-hcs08$(BUILDDIR_SUFFIX)   $(TARGET)-hcs08-debug$(BUILDDIR_SUFFIX)
	${RMDIR} $(TARGET)-hcs12$(BUILDDIR_SUFFIX)   $(TARGET)-hcs12-debug$(BUILDDIR_SUFFIX)
	${RMDIR} $(TARGET)-rs08$(BUILDDIR_SUFFIX)   $(TARGET)-rs08-debug$(BUILDDIR_SUFFIX)
	${RMDIR} $(TARGET)-s12z$(BUILDDIR_SUFFIX)   $(TARGET)-s12z-debug$(BUILDDIR_SUFFIX)
	${RMDIR} $(TARGET)-jtag$(BUILDDIR_SUFFIX)   $(TARGET)-jtag-debug$(BUILDDIR_SUFFIX)
	${RMDIR} $(TARGET)-dsc$(BUILDDIR_SUFFIX)   $(TARGET)-dsc-debug$(BUILDDIR_SUFFIX)
	${RMDIR} TestBdmInterface-debug$(BUILDDIR_SUFFIX)

.PHONY: all clean 
.PHONY: $(TARGET)-arm $(TARGET)-arm-debug
.PHONY: $(TARGET)-cfv1 $(TARGET)-cfv1-debug
.PHONY: $(TARGET)-cfvx $(TARGET)-cfvx-debug
.PHONY: $(TARGET)-hcs08 $(TARGET)-hcs08-debug
.PHONY: $(TARGET)-hcs12 $(TARGET)-hcs12-debug
.PHONY: $(TARGET)-rs08 $(TARGET)-rs08-debug
.PHONY: $(TARGET)-s12z $(TARGET)-s12z-debug
.PHONY: $(TARGET)-jtag $(TARGET)-jtag-debug
.PHONY: $(TARGET)-dsc $(TARGET)-dsc-debug
.PHONY: TestBdmInterface-debug
