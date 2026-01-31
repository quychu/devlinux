#include "hal_actuators.h"
#include <stdio.h>

void TurnPumpOn(void) {
    printf("[ACT] PUMP -> ON\n");
}

void TurnPumpOff(void) {
    printf("[ACT] PUMP -> OFF\n");
}


void UpdateLedColor(LedState_t color) {
    switch(color) {
        case LED_NORMAL:
            printf("[ACT] LED -> GREEN\n");
            break;
        case LED_WATERING:
            printf("[ACT] LED -> YELLOW\n");
            break;
        case LED_LOW_MOISTURE_ALERT:
            printf("[ACT] LED -> RED BLINKING\n");
            break;
        default:
            printf("[ACT] LED -> OFF/ERROR\n");
            break;
    }
}