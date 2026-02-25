#include"logger.h"
#include"stdarg.h"
#include"time.h"
#include"string.h"

static const char* level_strings[] = {
    "EMERGENCY", "ALERT", "CRITICAL", "ERROR", 
    "WARNING", "NOTICE", "INFO", "DEBUG"
};

static logLevel currentLevel = LOG_INFO;
static FILE *plogFile = NULL;

void loggerSetLevel(logLevel level){
    currentLevel = level;
}

void loggerInit(logLevel level, const char* filename){
    currentLevel = level;
    if(filename == NULL){
        return;
    }

    plogFile =  fopen(filename,"a");
}

void loggerClose(void){
    if(plogFile != NULL){
        fclose(plogFile);
        plogFile = NULL;
    }
}

void loggerMessageInternal(logLevel level, const char* filename,int line,const char* format,... ){
    if(level > currentLevel){
        return;
    }

    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char timeStr[20];
    strftime(timeStr,sizeof(timeStr),"%Y-%m-%d %H:%M:%S",t);

    char message[1024];
    va_list args;
    va_start(args,format);
    vsnprintf(message,sizeof(message),format,args);
    va_end(args);

    FILE *out = (level <= LOG_ERROR) ? stderr : stdout;

    fprintf(out,"[%s] [%s] [%s:%d]: %s\n",
        timeStr,level_strings[level],filename,line,message);
    
    if(plogFile != NULL){
        fprintf(plogFile,"[%s] [%s] [%s:%d] - %s\n",
            timeStr,level_strings[level],filename,line,message);
        fflush(plogFile);
    }

}