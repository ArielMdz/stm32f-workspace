// main.c file for STM32F4xx microcontrollers
#include <stdint.h>
#include "main.h"
#include "uart.h"
#include <stdio.h>

int main(void)
{
    uart2_tx_init();
    while (1)
    {
        printf("Hello, UART!\r\n");
        for(volatile int i = 0; i < 1000000; i++); // Simple delay
    }
}