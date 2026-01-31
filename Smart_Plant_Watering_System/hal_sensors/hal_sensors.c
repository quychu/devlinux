#include "hal_sensors.h"
#include "stdio.h"
#include <stdlib.h>

float rawDataMoisture(){
    return (float)(60 + ( rand()%3100 )/100.0f);
}

float rawDataTemperature(){
    return (float)(30 + ( rand()%1100 )/100.0f);
}

void readDataSensor(SensorData_t *data){
    float sumMoi = 0;
    float sumTemp = 0;
    
    for( int i = 0; i < 10; i++){
        sumMoi += rawDataMoisture();
        sumTemp += rawDataTemperature();
    }

    data->soilMoisturePercent = sumMoi / 10;
    data->airTemperatureCelsius = sumTemp /10;
}