#include <stdio.h>
typedef enum{
    LOG_EMERGENCY = 0,
    LOG_ALERT,
    LOG_CRITICAL,
    LOG_ERROR,
    LOG_WARNING,
    LOG_NOTICE,
    LOG_INFO,
    LOG_DEBUG
} logLevel;

void loggerInit(logLevel level, const char* filename);
void loggerClose(void);
void loggerSetLevel(logLevel level);
void loggerMessageInternal(logLevel level, const char* filename,int line,const char* format,... );

#define log_message(level,format,...) \
    loggerMessageInternal(level,__FILE__,__LINE__,format,##__VA_ARGS__)
