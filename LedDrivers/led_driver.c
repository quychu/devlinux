#include "led_driver.h"
#include <stdlib.h>
#include <string.h>

static uint32_t *pLedBuffer = NULL;
static size_t pixelCount = 0;


int led_init(size_t num_pixels){
    if(pLedBuffer != NULL){
        free(pLedBuffer);
    }

    pLedBuffer = (uint32_t*)malloc(sizeof(uint32_t)*num_pixels);
   
    if(pLedBuffer == NULL){
        return -1;
    }

    memset(pLedBuffer,0,sizeof(uint32_t)*num_pixels);
    pixelCount = num_pixels;
    return 0;
}

void led_shutdown(){
    if(pLedBuffer != NULL){
        free(pLedBuffer);
        pLedBuffer = NULL;
        pixelCount = 0;
    }
}

void led_set_pixel_color(size_t index, uint8_t r, uint8_t g, uint8_t b){
    if (index >= pixelCount) {
        printf("Error: Pixel index %d is out of bounds.\n", index);
        return; 
    }
    uint32_t REG = 0;
    REG = (g << 16 ) | (r << 8 ) | (b << 0);
    pLedBuffer[index] = REG;
}

void led_fill(uint8_t r, uint8_t g, uint8_t b){
    uint32_t REG = 0;
    REG = (g << 16 ) | (r << 8 ) | (b << 0);
    for( int i = 0 ; i < pixelCount; i ++){
         pLedBuffer[i] = REG;
    }
}

void led_clear(){
    led_fill(0,0,0);
}

const uint32_t* led_get_buffer(){
    return pLedBuffer;
}

size_t led_get_pixel_count(){
    return pixelCount;
}