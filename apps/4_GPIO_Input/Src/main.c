// main.c file for STM32F4xx microcontrollers
#include <stdint.h>
#include "main.h"

int main(void)
{
    RCC->AHB1ENR |= GPIOAEN;
    RCC->AHB1ENR |= GPIOCEN;

    GPIOA->MODER |= (1U << 10);
    GPIOA->MODER &= ~(1U << 11);

    GPIOC->MODER &= ~(3U << 26);

    //GPIOC->PUPDR |= (1U << 27);
    GPIOC->PUPDR &= ~(3U << 26);
    while (1)
    {
        if (!(GPIOC->IDR & USER_BUTTON_PIN))
        {                          // Check if button is pressed
            GPIOA->BSRR = LED_PIN; // Set LED pin
        }
        else
        {
            GPIOA->BSRR = (1U << 21); // Reset LED pin
        }
    }
}
