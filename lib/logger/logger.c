#include "logger.h"

#include <stdlib.h>

TLogger* NewLogger(TLogInfo* logInfo) {
    TLogger* logger = (TLogger*)malloc(sizeof(TLogger));
    logger->LogInfo = logInfo;
    return logger;
}
