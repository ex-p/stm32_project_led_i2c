#include "controller.h"

#include <stdlib.h>

TController* NewController(TLogger* logger) {
    TController* controller = (TController*)malloc(sizeof(TController));
    controller->Logger = logger;
    return controller;
}
