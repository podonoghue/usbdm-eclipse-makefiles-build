################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/peter/Documents/Development/usbdm/usbdm-eclipse-makefiles-build/Shared/src/AppSettings.cpp \
/home/peter/Documents/Development/usbdm/usbdm-eclipse-makefiles-build/Shared/src/DeviceInterface.cpp \
/home/peter/Documents/Development/usbdm/usbdm-eclipse-makefiles-build/Shared/src/ErrorMessages.cpp \
/home/peter/Documents/Development/usbdm/usbdm-eclipse-makefiles-build/Shared/src/Names.cpp \
/home/peter/Documents/Development/usbdm/usbdm-eclipse-makefiles-build/Shared/src/ProgressDialogue.cpp \
/home/peter/Documents/Development/usbdm/usbdm-eclipse-makefiles-build/Shared/src/UsbdmDialogue.cpp \
/home/peter/Documents/Development/usbdm/usbdm-eclipse-makefiles-build/Shared/src/UsbdmDialogueSkeleton.cpp \
/home/peter/Documents/Development/usbdm/usbdm-eclipse-makefiles-build/Shared/src/UsbdmSystem.cpp \
/home/peter/Documents/Development/usbdm/usbdm-eclipse-makefiles-build/Shared/src/UsbdmSystemLinux.cpp \
/home/peter/Documents/Development/usbdm/usbdm-eclipse-makefiles-build/Shared/src/UsbdmSystemWin.cpp \
/home/peter/Documents/Development/usbdm/usbdm-eclipse-makefiles-build/Shared/src/Utils.cpp \
/home/peter/Documents/Development/usbdm/usbdm-eclipse-makefiles-build/Shared/src/WxStub.cpp \
/home/peter/Documents/Development/usbdm/usbdm-eclipse-makefiles-build/Shared/src/low_level_usb.cpp 

C_SRCS += \
/home/peter/Documents/Development/usbdm/usbdm-eclipse-makefiles-build/Shared/src/FindWindow.c 

OBJS += \
./source/AppSettings.o \
./source/DeviceInterface.o \
./source/ErrorMessages.o \
./source/FindWindow.o \
./source/Names.o \
./source/ProgressDialogue.o \
./source/UsbdmDialogue.o \
./source/UsbdmDialogueSkeleton.o \
./source/UsbdmSystem.o \
./source/UsbdmSystemLinux.o \
./source/UsbdmSystemWin.o \
./source/Utils.o \
./source/WxStub.o \
./source/low_level_usb.o 

CPP_DEPS += \
./source/AppSettings.d \
./source/DeviceInterface.d \
./source/ErrorMessages.d \
./source/Names.d \
./source/ProgressDialogue.d \
./source/UsbdmDialogue.d \
./source/UsbdmDialogueSkeleton.d \
./source/UsbdmSystem.d \
./source/UsbdmSystemLinux.d \
./source/UsbdmSystemWin.d \
./source/Utils.d \
./source/WxStub.d \
./source/low_level_usb.d 

C_DEPS += \
./source/FindWindow.d 


# Each subdirectory must supply rules for building sources it contributes
source/AppSettings.o: /home/peter/Documents/Development/usbdm/usbdm-eclipse-makefiles-build/Shared/src/AppSettings.cpp source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DTARGET=ARM -DuseWxWidgets -D__WXMSW__ -DUNICODE -D__GNUWIN32__ -DwxUSE_COMBOBOX -I"/include" -I"/lib/gcc_dll/mswu" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/DeviceInterface.o: /home/peter/Documents/Development/usbdm/usbdm-eclipse-makefiles-build/Shared/src/DeviceInterface.cpp source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DTARGET=ARM -DuseWxWidgets -D__WXMSW__ -DUNICODE -D__GNUWIN32__ -DwxUSE_COMBOBOX -I"/include" -I"/lib/gcc_dll/mswu" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/ErrorMessages.o: /home/peter/Documents/Development/usbdm/usbdm-eclipse-makefiles-build/Shared/src/ErrorMessages.cpp source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DTARGET=ARM -DuseWxWidgets -D__WXMSW__ -DUNICODE -D__GNUWIN32__ -DwxUSE_COMBOBOX -I"/include" -I"/lib/gcc_dll/mswu" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/FindWindow.o: /home/peter/Documents/Development/usbdm/usbdm-eclipse-makefiles-build/Shared/src/FindWindow.c source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -DTARGET=ARM -DuseWxWidgets -D__WXMSW__ -DUNICODE -D__GNUWIN32__ -I"/include" -I"/lib/gcc_dll/mswu" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/Names.o: /home/peter/Documents/Development/usbdm/usbdm-eclipse-makefiles-build/Shared/src/Names.cpp source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DTARGET=ARM -DuseWxWidgets -D__WXMSW__ -DUNICODE -D__GNUWIN32__ -DwxUSE_COMBOBOX -I"/include" -I"/lib/gcc_dll/mswu" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/ProgressDialogue.o: /home/peter/Documents/Development/usbdm/usbdm-eclipse-makefiles-build/Shared/src/ProgressDialogue.cpp source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DTARGET=ARM -DuseWxWidgets -D__WXMSW__ -DUNICODE -D__GNUWIN32__ -DwxUSE_COMBOBOX -I"/include" -I"/lib/gcc_dll/mswu" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/UsbdmDialogue.o: /home/peter/Documents/Development/usbdm/usbdm-eclipse-makefiles-build/Shared/src/UsbdmDialogue.cpp source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DTARGET=ARM -DuseWxWidgets -D__WXMSW__ -DUNICODE -D__GNUWIN32__ -DwxUSE_COMBOBOX -I"/include" -I"/lib/gcc_dll/mswu" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/UsbdmDialogueSkeleton.o: /home/peter/Documents/Development/usbdm/usbdm-eclipse-makefiles-build/Shared/src/UsbdmDialogueSkeleton.cpp source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DTARGET=ARM -DuseWxWidgets -D__WXMSW__ -DUNICODE -D__GNUWIN32__ -DwxUSE_COMBOBOX -I"/include" -I"/lib/gcc_dll/mswu" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/UsbdmSystem.o: /home/peter/Documents/Development/usbdm/usbdm-eclipse-makefiles-build/Shared/src/UsbdmSystem.cpp source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DTARGET=ARM -DuseWxWidgets -D__WXMSW__ -DUNICODE -D__GNUWIN32__ -DwxUSE_COMBOBOX -I"/include" -I"/lib/gcc_dll/mswu" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/UsbdmSystemLinux.o: /home/peter/Documents/Development/usbdm/usbdm-eclipse-makefiles-build/Shared/src/UsbdmSystemLinux.cpp source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DTARGET=ARM -DuseWxWidgets -D__WXMSW__ -DUNICODE -D__GNUWIN32__ -DwxUSE_COMBOBOX -I"/include" -I"/lib/gcc_dll/mswu" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/UsbdmSystemWin.o: /home/peter/Documents/Development/usbdm/usbdm-eclipse-makefiles-build/Shared/src/UsbdmSystemWin.cpp source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DTARGET=ARM -DuseWxWidgets -D__WXMSW__ -DUNICODE -D__GNUWIN32__ -DwxUSE_COMBOBOX -I"/include" -I"/lib/gcc_dll/mswu" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/Utils.o: /home/peter/Documents/Development/usbdm/usbdm-eclipse-makefiles-build/Shared/src/Utils.cpp source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DTARGET=ARM -DuseWxWidgets -D__WXMSW__ -DUNICODE -D__GNUWIN32__ -DwxUSE_COMBOBOX -I"/include" -I"/lib/gcc_dll/mswu" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/WxStub.o: /home/peter/Documents/Development/usbdm/usbdm-eclipse-makefiles-build/Shared/src/WxStub.cpp source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DTARGET=ARM -DuseWxWidgets -D__WXMSW__ -DUNICODE -D__GNUWIN32__ -DwxUSE_COMBOBOX -I"/include" -I"/lib/gcc_dll/mswu" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/low_level_usb.o: /home/peter/Documents/Development/usbdm/usbdm-eclipse-makefiles-build/Shared/src/low_level_usb.cpp source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DTARGET=ARM -DuseWxWidgets -D__WXMSW__ -DUNICODE -D__GNUWIN32__ -DwxUSE_COMBOBOX -I"/include" -I"/lib/gcc_dll/mswu" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


