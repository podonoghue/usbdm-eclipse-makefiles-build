include ../Common.mk

tbdml:
	$(info )
	$(info Building $@ 32-bit)
	$(info ================================================================)
	$(MAKE) dll -f Target.mk BUILDDIR=$@ TARGET=$@ MODULE=tbdml CDEFS="-DLEGACY_DLL_EXPORTS -DTBDML -DGDI" BITNESS=32

tbdml-debug:
	$(info )
	$(info Building $@ 32-bit)
	$(info ================================================================)
	$(MAKE) dll -f Target.mk BUILDDIR=$@ TARGET=$@ MODULE=tbdml CDEFS="-DLEGACY_DLL_EXPORTS -DTBDML -DGDI" DEBUG='Y' BITNESS=32

TestTbdml-debug:
	$(info )
	$(info Building $@ 32-bit)
	$(info ================================================================)
	$(MAKE) exe -f Target.mk BUILDDIR=$@ TARGET=$@ MODULE=tbdml-exe CDEFS="-DLEGACY_DLL_EXPORTS -DTBDML -DGDI -DTEST_APP" DEBUG='Y' BITNESS=32

opensourcebdm:
	$(info )
	$(info Building $@ 32-bit)
	$(info ================================================================)
	$(MAKE) dll -f Target.mk BUILDDIR=$@ TARGET=$@ MODULE=osbdm CDEFS="-DLEGACY_DLL_EXPORTS -DOSBDM -DGDI" BITNESS=32

opensourcebdm-debug:
	$(info )
	$(info Building $@ 32-bit)
	$(info ================================================================)
	$(MAKE) dll -f Target.mk BUILDDIR=$@ TARGET=$@ MODULE=osbdm CDEFS="-DLEGACY_DLL_EXPORTS -DOSBDM -DGDI" DEBUG='Y' BITNESS=32

TestOpensourcebdm-debug:
	$(info )
	$(info Building $@ 32-bit)
	$(info ================================================================)
	$(MAKE) exe -f Target.mk BUILDDIR=$@ TARGET=$@ MODULE=osbdm-exe CDEFS="-DLEGACY_DLL_EXPORTS -DOSBDM -DGDI -DTEST_APP" DEBUG='Y' BITNESS=32

all: tbdml tbdml-debug TestTbdml-debug
all: opensourcebdm opensourcebdm-debug TestOpensourcebdm-debug

clean:
	${RMDIR} tbdml$(BUILDDIR_SUFFIXx32)
	${RMDIR} tbdml-debug$(BUILDDIR_SUFFIXx32)
	${RMDIR} TestTbdml-debug$(BUILDDIR_SUFFIXx32)
	${RMDIR} opensourcebdm$(BUILDDIR_SUFFIXx32)
	${RMDIR} opensourcebdm-debug$(BUILDDIR_SUFFIXx32)
	${RMDIR} TestOpensourcebdm-debug$(BUILDDIR_SUFFIXx32)
	
.PHONY: all clean 
.PHONY: tbdml tbdml-debug
.PHONY: opensourcebdm opensourcebdm-debug
.PHONY: TestTbdml-debug TestOpensourcebdm-debug
