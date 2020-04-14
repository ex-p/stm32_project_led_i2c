# stm32_project_led_i2c
This is a project for STM32 which is going to be implemented in the heating system later on.

The code in main.c is automatically generated in STM32CubeMX, the code should be written in the so called "USER CODE" section for it not to be rewritten after the peripherals are changed.

# Usage
```bash
$ compiler lib/core/core.c lib/controller/controller.c lib/controller/display.c lib/logger/logger.c lib/logger/stdlogger.c lib/stm32/display/display.c -o main.o
$ ./main.o

$ # example
$ clang main.c lib/core/core.c lib/controller/controller.c lib/controller/display.c lib/logger/logger.c lib/logger/stdlogger.c lib/stm32/display/display.c -o main.o && ./main.o
```
