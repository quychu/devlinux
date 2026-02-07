#include <stdio.h>
#include <stdint.h>
#include "led_driver.h"

int main() {

    led_init(10);
    const uint32_t* buffer = led_get_buffer();
    size_t num = led_get_pixel_count();
    int clean = 1;
    for (int i = 0; i < num; i++) {
        if (buffer[i] != 0) {
            clean = 0;
            break;
        }
    }
    
    if (clean){
        printf("Buffer cleared to 0.\n");
    }
    else {
        printf("ERROR: Buffer not cleared!\n");
    }

    led_set_pixel_color(0, 255, 0, 0);
    printf("Set pixel 0: RED (255, 0, 0)\n");

    led_set_pixel_color(4, 255, 255, 255);
    printf("Set pixel 4: WHITE (255, 255, 255)\n");

    led_set_pixel_color(9, 0, 0, 255);
    printf("Set pixel 9: BLUE (0, 0, 255)\n");

    printf("Pixel 0 (Red)   : 0x%08X\n", buffer[0]);
    printf("Pixel 4 (White) : 0x%08X\n", buffer[4]);
    printf("Pixel 9 (Blue)  : 0x%08X\n", buffer[9]);

    led_fill(0, 255, 0);
    int fill_ok = 1;
    for (int i = 0; i < num; i++) {
        if (buffer[i] != 0x00FF0000) {
            fill_ok = 0;
            printf("Error at pixel %d: Value is 0x%08X\n", i, buffer[i]);
        }
    }
    
    if (fill_ok){
        printf("-> OK: All pixels filled with GREEN (0x00FF0000).\n");
    }
    else{
        printf("-> ERROR: Incorrect color fill.\n");
    }

    led_shutdown();
    
    if (led_get_buffer() == NULL) {
        printf("LED driver shutdown successfully.\n");
    }
    return 0;
}