#include "stdlogger.h"

#include <stdio.h>

void LogInfo(const char* info) {
    printf("%s\n", info);
}

TLogger* NewStdLogger() {
    return NewLogger(&LogInfo);
}
