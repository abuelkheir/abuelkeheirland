################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_pro.c \
../DIO_Prog.c \
../GPT_prog.c \
../LCD_Prog.c \
../PWM_prog.c \
../main.c 

OBJS += \
./ADC_pro.o \
./DIO_Prog.o \
./GPT_prog.o \
./LCD_Prog.o \
./PWM_prog.o \
./main.o 

C_DEPS += \
./ADC_pro.d \
./DIO_Prog.d \
./GPT_prog.d \
./LCD_Prog.d \
./PWM_prog.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


