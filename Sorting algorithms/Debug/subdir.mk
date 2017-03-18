################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../InsertionSort.cpp \
../LinkedList.cpp \
../ListSorter.cpp \
../MergeSort.cpp \
../QuickSortMalik.cpp \
../QuickSortOptimal.cpp \
../QuickSortSuboptimal.cpp \
../QuickSorter.cpp \
../SelectionSort.cpp \
../ShellSortOptimal.cpp \
../ShellSortSuboptimal.cpp \
../SortTests.cpp \
../Sorter.cpp \
../VectorSorter.cpp 

OBJS += \
./InsertionSort.o \
./LinkedList.o \
./ListSorter.o \
./MergeSort.o \
./QuickSortMalik.o \
./QuickSortOptimal.o \
./QuickSortSuboptimal.o \
./QuickSorter.o \
./SelectionSort.o \
./ShellSortOptimal.o \
./ShellSortSuboptimal.o \
./SortTests.o \
./Sorter.o \
./VectorSorter.o 

CPP_DEPS += \
./InsertionSort.d \
./LinkedList.d \
./ListSorter.d \
./MergeSort.d \
./QuickSortMalik.d \
./QuickSortOptimal.d \
./QuickSortSuboptimal.d \
./QuickSorter.d \
./SelectionSort.d \
./ShellSortOptimal.d \
./ShellSortSuboptimal.d \
./SortTests.d \
./Sorter.d \
./VectorSorter.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


