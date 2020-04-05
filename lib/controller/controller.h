#ifndef LED_LIB_CONTROLLER_CONTROLLER_H_
#define LED_LIB_CONTROLLER_CONTROLLER_H_

#include "../logger/logger.h"

typedef struct {
    TLogger* Logger;
} TController;

TController* NewController(TLogger* logger);

#endif  // LED_LIB_CONTROLLER_CONTROLLER_H_
