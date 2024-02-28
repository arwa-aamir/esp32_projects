#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "sdkconfig.h"

static const char *TAG = "example";

/* Use project configuration menu (idf.py menuconfig) to choose the GPIO to blink,
   or you can edit the following line and set a number here.
*/
#define PIN_A 15
#define PIN_B 16
#define PIN_C 17
#define PIN_D 18
#define PIN_E 8
#define PIN_F 20
#define PIN_G 21

static void configure_gpios(void)
{
    ESP_LOGI(TAG, "Example configured to display decimal counter on 7 Segment Display!");
    gpio_reset_pin(PIN_A);
    gpio_reset_pin(PIN_B);
    gpio_reset_pin(PIN_C);
    gpio_reset_pin(PIN_D);
    gpio_reset_pin(PIN_E);
    gpio_reset_pin(PIN_F);
    gpio_reset_pin(PIN_G);
    
    /* Set the GPIO as a push/pull output */
    gpio_set_direction(PIN_A, GPIO_MODE_OUTPUT);
    gpio_set_direction(PIN_B, GPIO_MODE_OUTPUT);
    gpio_set_direction(PIN_C, GPIO_MODE_OUTPUT);
    gpio_set_direction(PIN_D, GPIO_MODE_OUTPUT);
    gpio_set_direction(PIN_E, GPIO_MODE_OUTPUT);
    gpio_set_direction(PIN_F, GPIO_MODE_OUTPUT);
    gpio_set_direction(PIN_G, GPIO_MODE_OUTPUT);
}
static void display_digit(int i)
{
    switch(i)
    {
        case 0:
        {
            gpio_set_level(PIN_A,0);
            gpio_set_level(PIN_B,0);
            gpio_set_level(PIN_C,0);
            gpio_set_level(PIN_D,0);
            gpio_set_level(PIN_E,0);
            gpio_set_level(PIN_F,0);
            gpio_set_level(PIN_G,1);
            break;
        }
        case 1:
        {
            gpio_set_level(PIN_A,1);
            gpio_set_level(PIN_B,0);
            gpio_set_level(PIN_C,0);
            gpio_set_level(PIN_D,1);
            gpio_set_level(PIN_E,1);
            gpio_set_level(PIN_F,1);
            gpio_set_level(PIN_G,1);
            break;
        }
        case 2:
        {
            gpio_set_level(PIN_A,0);
            gpio_set_level(PIN_B,0);
            gpio_set_level(PIN_C,1);
            gpio_set_level(PIN_D,0);
            gpio_set_level(PIN_E,0);
            gpio_set_level(PIN_F,1);
            gpio_set_level(PIN_G,0);
            break;            
        }
        case 3:
        {
            gpio_set_level(PIN_A,0);
            gpio_set_level(PIN_B,0);
            gpio_set_level(PIN_C,0);
            gpio_set_level(PIN_D,0);
            gpio_set_level(PIN_E,1);
            gpio_set_level(PIN_F,1);
            gpio_set_level(PIN_G,0);
            break;              
        }
        case 4:
        {
            gpio_set_level(PIN_A,1);
            gpio_set_level(PIN_B,0);
            gpio_set_level(PIN_C,0);
            gpio_set_level(PIN_D,1);
            gpio_set_level(PIN_E,1);
            gpio_set_level(PIN_F,0);
            gpio_set_level(PIN_G,0);
            break;            
        }
        case 5:
        {
            gpio_set_level(PIN_A,0);
            gpio_set_level(PIN_B,1);
            gpio_set_level(PIN_C,0);
            gpio_set_level(PIN_D,0);
            gpio_set_level(PIN_E,1);
            gpio_set_level(PIN_F,0);
            gpio_set_level(PIN_G,0);
            break;             
        }
        case 6:
        {
            gpio_set_level(PIN_A,0);
            gpio_set_level(PIN_B,1);
            gpio_set_level(PIN_C,0);
            gpio_set_level(PIN_D,0);
            gpio_set_level(PIN_E,0);
            gpio_set_level(PIN_F,0);
            gpio_set_level(PIN_G,0);
            break;            
        }
        case 7:
        {
            gpio_set_level(PIN_A,0);
            gpio_set_level(PIN_B,0);
            gpio_set_level(PIN_C,0);
            gpio_set_level(PIN_D,1);
            gpio_set_level(PIN_E,1);
            gpio_set_level(PIN_F,1);
            gpio_set_level(PIN_G,1);
            break;              
        }
        case 8:
        {
            gpio_set_level(PIN_A,0);
            gpio_set_level(PIN_B,0);
            gpio_set_level(PIN_C,0);
            gpio_set_level(PIN_D,0);
            gpio_set_level(PIN_E,0);
            gpio_set_level(PIN_F,0);
            gpio_set_level(PIN_G,0);
            break;
        }
        case 9:
        {
            gpio_set_level(PIN_A,0);
            gpio_set_level(PIN_B,0);
            gpio_set_level(PIN_C,0);
            gpio_set_level(PIN_D,0);
            gpio_set_level(PIN_E,1);
            gpio_set_level(PIN_F,0);
            gpio_set_level(PIN_G,0);
            break;
        }
    }

}


void app_main(void)
{

    /* Configure the peripheral according to the LED type */
    configure_gpios();
    
    while (1) {
        display_digit(0);
        ESP_LOGI(TAG, "Displaying the digit %d!", 0);
        vTaskDelay(250);
        display_digit(1);
        ESP_LOGI(TAG, "Displaying the digit %d!", 1);
        vTaskDelay(250);
        display_digit(2);
        ESP_LOGI(TAG, "Displaying the digit %d!", 2);
        vTaskDelay(250);
        display_digit(3);
        ESP_LOGI(TAG, "Displaying the digit %d!", 3);
        vTaskDelay(250);
        display_digit(4);
        ESP_LOGI(TAG, "Displaying the digit %d!", 4);
        vTaskDelay(250);
        display_digit(5);
        ESP_LOGI(TAG, "Displaying the digit %d!", 5);
        vTaskDelay(250);
        display_digit(6);
        ESP_LOGI(TAG, "Displaying the digit %d!", 6);
        vTaskDelay(250);
        display_digit(7);
        ESP_LOGI(TAG, "Displaying the digit %d!", 7);
        vTaskDelay(250);
        display_digit(8);
        ESP_LOGI(TAG, "Displaying the digit %d!", 8);
        vTaskDelay(250);
        display_digit(9);
        ESP_LOGI(TAG, "Displaying the digit %d!", 9);
        vTaskDelay(250);
        
    }
}