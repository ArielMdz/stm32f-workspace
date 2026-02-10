#ifndef __UART_H
#define __UART_H

#include "main.h"
//* Define the base address for the APB1 peripheral bus
#define APB1PERIPH_BASE (PERIPH_BASE)

#define USART2_OFFSET (0x4400UL) // 0x0000 4400
#define USART2_BASE (APB1PERIPH_BASE + USART2_OFFSET)

#define USART2 ((USART_TypeDef *)USART2_BASE)

typedef struct
{
    __IO uint32_t SR;  //*< USART status register,						Address offset: 0x00
    __IO uint32_t DR;  //*< USART data register,						Address offset: 0x04
    __IO uint32_t BRR; //*< USART baud rate register,					Address offset: 0x08
    __IO uint32_t CR1; //*< USART control register 1,					Address offset: 0x0C
    __IO uint32_t CR2; //*< USART control register 2,					Address offset: 0x10
    __IO uint32_t CR3; //*< USART control register 3,					Address offset: 0x14
} USART_TypeDef;

#define UART1EN (1U << 4)
#define UART2EN (1U << 17)

#define CR1_UE (1U << 13)
#define CR1_TE (1U << 3)
#define CR1_PEIE (1U << 8)
#define SR_TXE (1U << 7)

#define UART_BAUDRATE 115200

#define PIN9 (1U << 9)
#define PIN2 (1U << 2)
#define PIN3 (1U << 3)

#define SYS_FREQ 16000000UL
#define APB1_CLK (SYS_FREQ) // APB1 typically runs at half the system clock
#define APB2_CLK SYS_FREQ        // APB2 typically runs at system clock

void uart2_tx_init(void);
void uart2_write(int ch);

#endif /* __UART_H */