
BITNESS=64

include Common.mk

# Built on both Windows and Linux
# Note - order is important
DIRS = \
  UsbdmSystem_DLL      \
  Usbdm_DLL            \
  UsbdmJni_DLL         \
  UsbdmWx_DLL          \
  UsbdmDsc_DLL         \
  BdmInterface_DLL     \
  DeviceDatabase_DLL   \
  UsbdmTcl_DLL         \
  FlashImage_DLL       \
  Programmer_DLL       \
  Programmer           \
  GdbServer            \
  CreateFlashTestImage \
  CreateCTestImage     \
  KinetisUnlock        \
  JS16_Bootloader      \
  JB16_Bootloader      \
  FirmwareChanger      \
  MemoryDump           \
  MergeXML             \
  USBDM_API_Example    \
  USBDM_Programmer_API_Example

ifeq ($(UNAME_S),Windows)
DIRS += \
  MyCustomAction
endif

export TARGET_BINDIR TARGET_LIBDIR BUILDDIR_SUFFIX VSUFFIX
export BITNESS TARGET_BINDIR TARGET_LIBDIR BUILDDIR_SUFFIX

BUILD_DIRS = $(DIRS:%=build-%)
CLEAN_DIRS = $(DIRS:%=clean-%)

all: addExternalFiles $(BUILD_DIRS)

clean: cleanTargetFiles $(CLEAN_DIRS)

cleanTargetFiles:
	$(RMDIR) $(DUMMY_CHILD)/$(TARGET_LIBDIR)
	$(RMDIR) $(DUMMY_CHILD)/$(TARGET_BINDIR)

# Copy external DLLs
addExternalFiles:
ifeq ($(UNAME_S),Windows)
	$(MKDIR) $(DUMMY_CHILD)/$(TARGET_LIBDIR)
	$(MKDIR) $(DUMMY_CHILD)/$(TARGET_BINDIR)
endif

$(BUILD_DIRS):
	$(MAKE) -C $(@:build-%=%) all -f Makefile-x64.mk

$(CLEAN_DIRS):
	$(MAKE) -C $(@:clean-%=%) clean -f Makefile-x64.mk 

.PHONY: $(CLEAN_DIRS)
.PHONY: $(BUILD_DIRS)
.PHONY: clean all cleanTargetFiles addExternalFiles

