// main.c file for STM32F4xx microcontrollers
#include <stdint.h>
#include "main.h"

int main(void)
{
    // 1. Enable clock access to GPIOA
    RCC->AHB1ENR |= GPIOAEN;

    // 2. Set PA5 as output pin
    GPIOA->MODER &= ~(3U << 10); 
    GPIOA->MODER |= (1U << 10);

    // Set PA5 as push-pull output
    GPIOA->OTYPER &= ~(3U << 10);

    GPIOA->OTYPER &= ~PIN5; // Set PA5 as push-pull output

    while (1)
    {
        // 3. Set PA5 high
        GPIOA->ODR |= LED_PIN;
        for (int i = 0; i < 500000; i++)
            ;

        GPIOA->ODR &= ~LED_PIN;
        for (int i = 0; i < 500000; i++)
            ;
    }
}