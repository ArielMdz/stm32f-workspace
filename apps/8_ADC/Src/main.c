#include <stdint.h>
#include <stdio.h>
#include "main.h"
#include "uart.h"
#include "adc.h"

uint32_t adc_value = 0;

int main(void)
{
    uart2_tx_init();
    pal_adc_init();

    printf("Hello, UART!\r\n");
    
    while (1)
    {
        start_conversion();
        for(volatile int i = 0; i < 100000; i++); // Simple delay
        adc_value = adc_read();
        printf("ADC Value: %lu\r\n", adc_value);
    }
}

