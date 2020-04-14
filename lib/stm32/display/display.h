#ifndef LIB_STM32_DISPLAY_DISPLAY_H_
#define LIB_STM32_DISPLAY_DISPLAY_H_

#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "../Src/lib/controller/display.h"
#include "../Src/contrib/i2c-lcd.h"

TDisplay* NewI2cDisplay();

#endif // LIB_STM32_DISPLAY_DISPLAY_H_
