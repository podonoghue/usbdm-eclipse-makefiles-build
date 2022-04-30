################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/MemoryDumpApp.cpp \
../src/MemoryDumpDialogue.cpp \
../src/MemoryDumpDialogueSkeleton.cpp 

OBJS += \
./src/MemoryDumpApp.o \
./src/MemoryDumpDialogue.o \
./src/MemoryDumpDialogueSkeleton.o 

CPP_DEPS += \
./src/MemoryDumpApp.d \
./src/MemoryDumpDialogue.d \
./src/MemoryDumpDialogueSkeleton.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DTARGET=ARM -DuseWxWidgets -D__WXMSW__ -DUNICODE -D__GNUWIN32__ -DwxUSE_COMBOBOX -I"/include" -I"/lib/gcc_dll/mswu" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


