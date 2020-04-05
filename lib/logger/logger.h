#ifndef LED_LIB_LOGGER_LOGGER_H_
#define LED_LIB_LOGGER_LOGGER_H_

typedef void TLogInfo(const char* info);

typedef struct {
    TLogInfo* LogInfo;
} TLogger;

TLogger* NewLogger(TLogInfo* logInfo);

#endif  // LED_LIB_LOGGER_LOGGER_H_
