#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "config.h"
#include "hal_sensors.h"
#include "hal_actuators.h"
#include "hal_buttons.h"
#include "spws_controller.h"
#include <stdlib.h>

int main(void){
    srand(time(NULL));
    SensorData_t myData = {0,0};
    SystemSettings_t sysSettings = {0};
    SystemState_t sysState = {0};
    sysState.wateringTimeCounter = 0;

    spws_Init(&sysSettings,&sysState);

    readDataSensor(&myData);

while (1) {
    sleep(1);
    sysState.wateringTimeCounter++;
    Process(&sysSettings,&sysState,&myData);
}

}