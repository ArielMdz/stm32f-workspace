// main.c file for STM32F4xx microcontrollers
#include <stdint.h>
#include <stdio.h>
#include "main.h"
#include "uart.h"

int main(void)
{
    uart2_init();
    char letter = 'A';
    
    printf("Hello, UART!\r\n");
    for(volatile int i = 0; i < 1000000; i++); // Simple delay
    
    while (1)
    {
        letter = uart2_read();
        printf("You sent: %c\r\n", letter);
    }
}
