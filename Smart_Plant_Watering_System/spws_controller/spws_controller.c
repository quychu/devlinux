#include"spws_controller.h"
#include "stdio.h"
#include"hal_sensors.h"
#include"hal_actuators.h"
#include"hal_buttons.h"

const char* GetLedStateString(LedState_t state) {
    switch (state) {
        case LED_NORMAL:
            return "GREEN (Normal)";
        case LED_WATERING:
            return "YELLOW (Watering)";
        case LED_LOW_MOISTURE_ALERT:
            return "RED (Alert - Low Moisture)";
        case LED_ERROR:
            return "RED (Error)";
        default:
            return "UNKNOWN";
    }
}


void spws_Init( SystemSettings_t *setting, SystemState_t *state){
    setting->maxWateringDuration_s = 5;
    setting->minMoistureThreshold = 75;
    setting->maxMoistureThreshold = 77;
    setting->sensorReadInterval_s = 2;

    state->currentMode = MODE_AUTO;
    state->pumpState = PUMP_OFF;
    state->wateringTimeCounter = 0;

}     


void Process(SystemSettings_t *setting,
             SystemState_t *state,
             SensorData_t  *data)
{
    if(state->currentMode == MODE_AUTO){
        if( (state->wateringTimeCounter % setting->sensorReadInterval_s) == 0){
            readDataSensor(data);
            if(data->soilMoisturePercent < setting->minMoistureThreshold){
                if(state->pumpState != PUMP_ON){
                    state->pumpState = PUMP_ON;
                    TurnPumpOn();
                }

            }
            else if(data->soilMoisturePercent > setting->maxMoistureThreshold){
                if(state->pumpState != PUMP_OFF){
                    state->pumpState = PUMP_OFF;
                    TurnPumpOff();
                }
            }
        }

        if(state->pumpState == PUMP_ON){
            state->ledState = LED_WATERING;
        }
        else if(data->soilMoisturePercent < setting->minMoistureThreshold){
            state->ledState = LED_LOW_MOISTURE_ALERT;
        }
        else{
            state->ledState = LED_NORMAL;
        }
        UpdateLedColor(state->ledState);
        printf("t = %ds | Soid = %.2f %% | Pump = %s | Led = %s\n",
            state->wateringTimeCounter,
            data->soilMoisturePercent,
            state->pumpState == PUMP_OFF ? "OFF" : "ON",
            GetLedStateString(state->ledState)
        );

    }else if(state->currentMode == MODE_MANUAL){

    }
}