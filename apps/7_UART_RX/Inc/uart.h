#ifndef UART_H_
#define UART_H_

#include <stdio.h>
#include <stdint.h>
#include "main.h"

#define APB1PERIPH_BASE (PERIPH_BASE)

#define USART2_OFFSET (0x4400UL) // 0x0000 4400
#define USART2_BASE (APB1PERIPH_BASE + USART2_OFFSET)

#define UART_BAUDRATE 115200

#define UART1EN (1U << 4)
#define UART2EN (1U << 17)

#define CR1_UE (1U << 13)
#define CR1_RE (1U << 2)
#define CR1_TE (1U << 3)
#define SR_RXNE (1U << 5)
#define SR_TXE (1U << 7)
#define CR1_PEIE (1U << 8)

typedef struct
{
    __IO uint32_t SR;  //!< USART status register,						Address offset: 0x00
    __IO uint32_t DR;  //!< USART data register,						Address offset: 0x04
    __IO uint32_t BRR; //!< USART baud rate register,					Address offset: 0x08
    __IO uint32_t CR1; //!< USART control register 1,					Address offset: 0x0C
    __IO uint32_t CR2; //!< USART control register 2,					Address offset: 0x10
    __IO uint32_t CR3; //!< USART control register 3,					Address offset: 0x14
} USART_TypeDef;

#define USART2 ((USART_TypeDef *)USART2_BASE)

void uart2_tx_init(void);
void uart2_init(void);
void uart2_write(int ch);
char uart2_read(void);

#endif /* UART_H_ */