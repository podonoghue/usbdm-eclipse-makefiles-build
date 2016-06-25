include Common.mk

export TARGET_BINDIR TARGET_LIBDIR BITNESS BUILDDIR_SUFFIX VSUFFIX

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
  GDI_DLL              \
  GdiDialogue_DLL      \
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
  Legacy_DLL           \
  MyCustomAction
endif

#  USBDM_ARM_DLL        \
#  USBDM_MPC_DLL        \

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
	$(CP) $(DUMMY_CHILD)/$(SHARED_LIBDIRS)/* $(DUMMY_CHILD)/$(TARGET_LIBDIR)
endif

$(BUILD_DIRS):
	$(MAKE) -C $(@:build-%=%) all -f Makefile

$(CLEAN_DIRS):
	$(MAKE) -C $(@:clean-%=%) clean -f Makefile

.PHONY: $(CLEAN_DIRS)
.PHONY: $(BUILD_DIRS)
.PHONY: clean all cleanTargetFiles addExternalFiles

