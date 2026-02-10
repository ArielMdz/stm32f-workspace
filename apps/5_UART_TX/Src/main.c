// main.c file for STM32F4xx microcontrollers
#include <stdint.h>
#include "main.h"
#include "uart.h"

int main(void)
{
    uart2_tx_init();
    while (1)
    {
        uart2_write('B');
        uart2_write('\n');
        for (int i = 0; i < 1000000; i++);      // Simple delay loop
    }
}