// main.c file for STM32F4xx microcontrollers
#include <stdint.h>
#include "main.h"

int main(void)
{
    // 1. Enable clock access to GPIOA
    RCC->AHB1ENR |= GPIOAEN;

    // 2. Set PA0-5 as output pin
    GPIOA->MODER &= ~(0xFFF << 0); // Clear mode bits for PA0-5 
    GPIOA->MODER |= (1U << 0);  // Set PA0 as output
    GPIOA->MODER |= (1U << 2);  // Set PA1 as output
    GPIOA->MODER |= (1U << 4);  // Set PA2 as output
    GPIOA->MODER |= (1U << 6);  // Set PA3 as output
    GPIOA->MODER |= (1U << 8);  // Set PA4 as output
    GPIOA->MODER |= (1U << 10); // Set PA5 as output

    // Set PA5 as push-pull output
    GPIOA->OTYPER &= ~(31U << 0);   // Set PA0-5 as push-pull

    while (1)
    {
        // 3. Set PA0-5 high
        GPIOA->ODR |= (PIN0 | PIN1 | PIN2 | PIN3 | PIN4 | LED_PIN);
        for (int i = 0; i < 250000; i++)
            ;

        GPIOA->ODR &= ~(PIN0 | PIN1 | PIN2 | PIN3 | PIN4 | LED_PIN);
        for (int i = 0; i < 250000; i++)
            ;
    }
}