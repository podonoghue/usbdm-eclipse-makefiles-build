include ../Common.mk

TARGET := usbdm

DLL_DEFS := -DUSBDM_DLL_EXPORTS -DLINK_USBDM_SYSTEM_DLL

$(TARGET):
	@echo ''
	@echo  Building $@ 64-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@ MODULE=usbdm CDEFS='$(DLL_DEFS)' BITNESS=64

$(TARGET)-debug:
	@echo ''
	@echo  Building $@ 64-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@ MODULE=usbdm CDEFS='$(DLL_DEFS)' DEBUG='Y' BITNESS=64
	
$(TARGET)-static:
	@echo ''
	@echo  Building $@ 64-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@ MODULE=usbdm CDEFS='$(DLL_DEFS)' LFLAGS='$(STATIC_GCC_OPTION)' BITNESS=64

$(TARGET)-static-debug:
	@echo ''
	@echo  Building $@ 64-bit
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@ MODULE=usbdm CDEFS='$(DLL_DEFS)'  LFLAGS='$(STATIC_GCC_OPTION)' DEBUG='Y' BITNESS=64

all: $(TARGET)         $(TARGET)-debug 
all: $(TARGET)-static  $(TARGET)-static-debug 

clean:
	-${RMDIR} $(TARGET)$(BUILDDIR_SUFFIXx64)        $(TARGET)-debug$(BUILDDIR_SUFFIXx64)
	-${RMDIR} $(TARGET)-static$(BUILDDIR_SUFFIXx64) $(TARGET)-static-debug$(BUILDDIR_SUFFIXx64)  

.PHONY: all clean 
.PHONY: $(TARGET)          $(TARGET)-debug
.PHONY: $(TARGET)-static   $(TARGET)-static-debug
