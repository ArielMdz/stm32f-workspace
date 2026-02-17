#ifndef __MAIN_H
#define __MAIN_H

// main.h file for STM32F4xx microcontrollers
#include <stdint.h>

#define PERIPH_BASE (0x40000000UL)

#define AHB1PERIPH_OFFSET (0x00020000UL)
#define AHB1PERIPH_BASE (PERIPH_BASE + AHB1PERIPH_OFFSET)

#define APB2PERIPH_OFFSET (0x00010000UL)
#define APB2PERIPH_BASE (PERIPH_BASE + APB2PERIPH_OFFSET)

#define GPIOA_OFFSET (0x0000UL) // 0x0000 0000
#define GPIOA_BASE (AHB1PERIPH_BASE + GPIOA_OFFSET)

#define RCC_OFFSET (0x3800UL)
#define RCC_BASE (AHB1PERIPH_BASE + RCC_OFFSET)

#define GPIOAEN (1U << 0)
#define PIN5 (1U << 5)
#define LED_PIN PIN5

#define __IO volatile

typedef struct
{
    __IO uint32_t CR;       //!< RCC clock control register,				Address offset: 0x00
    __IO uint32_t PLLCFGR;  //!< RCC PLL configuration register,			Address offset: 0x04
    __IO uint32_t CFGR;     //!< RCC clock configuration register,			Address offset: 0x08
    __IO uint32_t CIR;      //!< RCC clock interrupt register,				Address offset: 0x0C
    __IO uint32_t AHB1RSTR; //!< RCC AHB1 peripheral reset register,		Address offset: 0x10
    __IO uint32_t AHB2RSTR; //!< RCC AHB2 peripheral reset register,		Address offset: 0x14
    __IO uint32_t AHB3RSTR; //!< RCC AHB3 peripheral reset register,		Address offset: 0x18
    uint32_t RESERVED0;     //!< Reserved, 0x1C
    __IO uint32_t APB1RSTR; //!< RCC APB1 peripheral reset register,		Address offset: 0x20
    __IO uint32_t APB2RSTR; //!< RCC APB2 peripheral reset register,		Address offset: 0x24
    uint32_t RESERVED1[2];  //!< Reserved, 0x28-0x2C
    __IO uint32_t AHB1ENR;  //!< RCC AHB1 peripheral clock register,		Address offset: 0x30
    __IO uint32_t AHB2ENR;  //!< RCC AHB2 peripheral clock register,		Address offset: 0x34
    __IO uint32_t AHB3ENR;  //!< RCC AHB3 peripheral clock register,		Address offset: 0x38
    uint32_t RESERVED2;     //!< Reserved, 0x3C
    __IO uint32_t APB1ENR;  //!< RCC APB1 peripheral clock register,		Address offset: 0x40
    __IO uint32_t APB2ENR;  //!< RCC APB2 peripheral clock register,		Address offset: 0x44

} RCC_TypeDef;

typedef struct
{
    __IO uint32_t MODER;	//*< GPIO port mode register,					Address offset: 0x00
    __IO uint32_t OTYPER;	//*< GPIO port output type register,			Address offset: 0x04
    __IO uint32_t OSPEEDR;	//*< GPIO port output speed register,			Address offset: 0x08
    __IO uint32_t PUPDR;	//*< GPIO port pull-up/pull-down register,		Address offset: 0x0C
    __IO uint32_t IDR;		//*< GPIO port input data register,				Address offset: 0x10
    __IO uint32_t ODR;		//*< GPIO port output data register,			Address offset: 0x14
    __IO uint32_t BSRR;		//*< GPIO port bit set/reset register,			Address offset: 0x18
    __IO uint32_t LCKR;		//*< GPIO port configuration lock register,		Address offset: 0x1C
    __IO uint32_t AFR[2];	//*< GPIO port output type register,			Address offset: 0x20-0x24
}GPIO_TypeDef;

#define RCC ((RCC_TypeDef *)RCC_BASE)
#define GPIOA ((GPIO_TypeDef *)GPIOA_BASE)

#endif /* __MAIN_H */