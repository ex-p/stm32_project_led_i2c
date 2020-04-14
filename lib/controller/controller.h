#ifndef LED_LIB_CONTROLLER_CONTROLLER_H_
#define LED_LIB_CONTROLLER_CONTROLLER_H_

#include "display.h"

#include "../logger/logger.h"

typedef struct {
    TLogger* Logger;
    TDisplay* Display;
} TController;

TController* NewController(TLogger* logger, TDisplay* display);

#endif  // LED_LIB_CONTROLLER_CONTROLLER_H_
