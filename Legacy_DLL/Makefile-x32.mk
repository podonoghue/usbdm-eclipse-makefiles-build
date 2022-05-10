include ../Common.mk

tbdml:
	@echo ''
	@echo  Building $@ 32-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@ TARGET=$@ MODULE=tbdml CDEFS='-DLEGACY_DLL_EXPORTS -DTBDML -DGDI' BITNESS=32

tbdml-debug:
	@echo ''
	@echo  Building $@ 32-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@ TARGET=$@ MODULE=tbdml CDEFS='-DLEGACY_DLL_EXPORTS -DTBDML -DGDI' DEBUG='Y' BITNESS=32

TestTbdml:
	@echo ''
	@echo  Building $@ 32-bit
	@echo "================================================================"
	$(MAKE) exe -f Target.mk BUILDDIR=$@ TARGET=$@ MODULE=tbdml-exe CDEFS='-DLEGACY_DLL_EXPORTS -DTBDML -DGDI -DTEST_APP' BITNESS=32

TestTbdml-debug:
	@echo ''
	@echo  Building $@ 32-bit
	@echo "================================================================"
	$(MAKE) exe -f Target.mk BUILDDIR=$@ TARGET=$@ MODULE=tbdml-exe CDEFS='-DLEGACY_DLL_EXPORTS -DTBDML -DGDI -DTEST_APP' DEBUG='Y' BITNESS=32

opensourcebdm:
	@echo ''
	@echo  Building $@ 32-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@ TARGET=$@ MODULE=osbdm CDEFS='-DLEGACY_DLL_EXPORTS -DOSBDM -DGDI' BITNESS=32

opensourcebdm-debug:
	@echo ''
	@echo  Building $@ 32-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@ TARGET=$@ MODULE=osbdm CDEFS='-DLEGACY_DLL_EXPORTS -DOSBDM -DGDI' DEBUG='Y' BITNESS=32

TestOpensourcebdm:
	@echo ''
	@echo  Building $@ 32-bit
	@echo "================================================================"
	$(MAKE) exe -f Target.mk BUILDDIR=$@ TARGET=$@ MODULE=osbdm-exe CDEFS='-DLEGACY_DLL_EXPORTS -DOSBDM -DGDI -DTEST_APP' BITNESS=32

TestOpensourcebdm-debug:
	@echo ''
	@echo  Building $@ 32-bit
	@echo "================================================================"
	$(MAKE) exe -f Target.mk BUILDDIR=$@ TARGET=$@ MODULE=osbdm-exe CDEFS='-DLEGACY_DLL_EXPORTS -DOSBDM -DGDI -DTEST_APP' DEBUG='Y' BITNESS=32

all: tbdml tbdml-debug TestTbdml TestTbdml-debug
all: opensourcebdm opensourcebdm-debug TestOpensourcebdm TestOpensourcebdm-debug

clean:
	${RMDIR} tbdml$(BUILDDIR_SUFFIXx32)
	${RMDIR} tbdml-debug$(BUILDDIR_SUFFIXx32)
	${RMDIR} TestTbdml$(BUILDDIR_SUFFIXx32)
	${RMDIR} TestTbdml-debug$(BUILDDIR_SUFFIXx32)
	${RMDIR} opensourcebdm$(BUILDDIR_SUFFIXx32)
	${RMDIR} opensourcebdm-debug$(BUILDDIR_SUFFIXx32)
	${RMDIR} TestOpensourcebdm$(BUILDDIR_SUFFIXx32)
	${RMDIR} TestOpensourcebdm-debug$(BUILDDIR_SUFFIXx32)
	
.PHONY: all clean 
.PHONY: tbdml tbdml-debug
.PHONY: opensourcebdm opensourcebdm-debug
.PHONY: TestTbdml TestTbdml-debug 
.PHONY: TestOpensourcebdm TestOpensourcebdm-debug
