:: --specs=nosys.specs - use spec with no system calls
:: https://gcc.gnu.org/onlinedocs/gcc/Option-Index.html 
:: http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.dui0553a/CIHJJEIH.html
:: http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.dui0552a/BABIFJFG.html - cortex-m3 vector table
cls
"D:\ARM_Toolchain\gcc-arm-none-eabi-6-2017-q2-update-win32\bin\arm-none-eabi-as" -c -mcpu=cortex-m3 .\code\startup.s -o .\tmp\startup.o
"D:\ARM_Toolchain\gcc-arm-none-eabi-6-2017-q2-update-win32\bin\arm-none-eabi-gcc" -mcpu=cortex-m3 --specs=nosys.specs .\code\main.c .\tmp\startup.o -T stm32f103c8t6_link_map.ld -static -nostartfiles -o .\tmp\main.elf
"D:\ARM_Toolchain\gcc-arm-none-eabi-6-2017-q2-update-win32\bin\arm-none-eabi-objcopy" -O binary .\tmp\main.elf main.bin

