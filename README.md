# stm32_project_led_i2c
This is a project for STM32 which is going to be implemented in the heating system later on

# Usage
```bash
$ compiler lib/core/core.c lib/controller/controller.c lib/logger/logger.c lib/logger/stdlogger.c -o main.o
$ ./main.o

$ # example
$ clang main.c lib/core/core.c lib/controller/controller.c lib/logger/logger.c lib/logger/stdlogger.c -o main.o && ./main.o
```
