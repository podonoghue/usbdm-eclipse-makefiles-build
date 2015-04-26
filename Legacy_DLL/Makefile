include ../Common.mk

tbdml:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@ MODULE=tbdml CDEFS='-DLEGACY_DLL_EXPORTS -DTBDML -DGDI'

tbdml-debug:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@ MODULE=tbdml CDEFS='-DLEGACY_DLL_EXPORTS -DTBDML -DGDI' DEBUG='Y'

tbdml-debug-exe:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) exe -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@ MODULE=tbdml-exe CDEFS='-DLEGACY_DLL_EXPORTS -DTBDML -DGDI -DTEST_APP' DEBUG='Y'

opensourcebdm:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@ MODULE=osbdm CDEFS='-DLEGACY_DLL_EXPORTS -DOSBDM -DGDI'

opensourcebdm-debug:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@ MODULE=osbdm CDEFS='-DLEGACY_DLL_EXPORTS -DOSBDM -DGDI' DEBUG='Y'

opensourcebdm-debug-exe:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) exe -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@ MODULE=osbdm-exe CDEFS='-DLEGACY_DLL_EXPORTS -DOSBDM -DGDI -DTEST_APP' DEBUG='Y'

all: tbdml tbdml-debug tbdml-debug-exe
all: opensourcebdm opensourcebdm-debug opensourcebdm-debug-exe

clean:
	${RMDIR} tbdml$(BUILDDIR_SUFFIX)
	${RMDIR} tbdml-debug$(BUILDDIR_SUFFIX)
	${RMDIR} tbdml-debug-exe$(BUILDDIR_SUFFIX)
	${RMDIR} opensourcebdm$(BUILDDIR_SUFFIX)
	${RMDIR} opensourcebdm-debug$(BUILDDIR_SUFFIX)
	${RMDIR} opensourcebdm-debug-exe$(BUILDDIR_SUFFIX)
	
.PHONY: all clean 
.PHONY: tbdml tbdml-debug
.PHONY: opensourcebdm opensourcebdm-debug
.PHONY: tbdml-debug-exe opensourcebdm-debug-exe
