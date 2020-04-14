#include "controller.h"

#include <stdlib.h>

TController* NewController(TLogger* logger, TDisplay* display) {
    TController* controller = (TController*)malloc(sizeof(TController));
    controller->Logger = logger;
    controller->Display = display;
    return controller;
}
