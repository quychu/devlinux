#include "config.h"
const char* GetLedStateString(LedState_t state);
void spws_Init( SystemSettings_t *setting, SystemState_t *state);
void Process(SystemSettings_t *setting,
             SystemState_t *state,
             SensorData_t *data);