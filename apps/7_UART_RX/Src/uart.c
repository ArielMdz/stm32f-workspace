#include "uart.h"

static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t BaudRate);
static uint16_t compute_uart_div(uint32_t PeriphClk, uint32_t BaudRate);

void uart2_init(void)
{
    // ****************Configure UART Gpio pin****************
    // Enable clock access to Gpioc
    RCC->AHB1ENR |= GPIOAEN;

    // Set PA2 mode to alternate function mode
    GPIOA->MODER |= (1U << 5);
    GPIOA->MODER &= ~(1U << 4);

    // Set PA2 output type to No-pull
    GPIOA->PUPDR &= ~(3U << 4);

    // Set PA2 output speed to low speed
    GPIOA->OSPEEDR &= ~(3U << 4);

    // Set PA2 alternate function type to UART_TX (AF07)
    GPIOA->AFR[0] |= (1U << 8);
    GPIOA->AFR[0] |= (1U << 9);
    GPIOA->AFR[0] |= (1U << 10);
    GPIOA->AFR[0] &= ~(1U << 11);

    // Set PA3 mode to alternate function mode
    GPIOA->MODER |= (1U << 7);
    GPIOA->MODER &= ~(1U << 6);

    // Set PA3 output type to No-pull
    GPIOA->PUPDR &= ~(3U << 6);

    // Set PA3 output speed to low speed
    GPIOA->OSPEEDR &= ~(3U << 6);

    // Set PA3 alternate function type to UART_RX (AF07)
    GPIOA->AFR[0] |= (1U << 12);
    GPIOA->AFR[0] |= (1U << 13);
    GPIOA->AFR[0] |= (1U << 14);
    GPIOA->AFR[0] &= ~(1U << 15);

    // ****************Configure UART module****************
    // Enable clock access to Uart2
    RCC->APB1ENR |= UART2EN;

    // Configure Baudrate
    uart_set_baudrate(USART2, APB1_CLK, UART_BAUDRATE);

    // Configure the transfer direction
    USART2->CR1 = (CR1_TE | CR1_RE);

    // Enable UART module
    USART2->CR1 |= CR1_UE;
}

void uart2_tx_init(void)
{
    // ****************Configure UART Gpio pin****************
    // Enable clock access to Gpioc
    RCC->AHB1ENR |= GPIOAEN;

    // Set PA2 mode to alternate function mode
    GPIOA->MODER |= (1U << 5);
    GPIOA->MODER &= ~(1U << 4);

    // Set PA2 output type to No-pull
    GPIOA->PUPDR &= ~(3U << 4);

    // Set PA2 output speed to low speed
    GPIOA->OSPEEDR &= ~(3U << 4);

    // Set PA2 alternate function type to UART_TX (AF07)
    GPIOA->AFR[0] |= (1U << 8);
    GPIOA->AFR[0] |= (1U << 9);
    GPIOA->AFR[0] |= (1U << 10);
    GPIOA->AFR[0] &= ~(1U << 11);

    // ****************Configure UART module****************
    // Enable clock access to Uart2
    RCC->APB1ENR |= UART2EN;

    // Configure Baudrate
    uart_set_baudrate(USART2, APB1_CLK, UART_BAUDRATE);

    // Configure the transfer direction
    USART2->CR1 |= CR1_TE;

    // Enable UART module
    USART2->CR1 |= CR1_UE;
}

void uart2_write(int ch)
{
    // Make sure the transmit data register is empty
    while (!(USART2->SR & SR_TXE))
    {
    }
    // Write to transmit data register
    USART2->DR = (ch & 0xFF);
}

char uart2_read(void)
{
    // Make sure the receive data register is not empty
    while (!(USART2->SR & SR_RXNE));

    // Read data
    return USART2->DR;
}

static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t BaudRate)
{
    USARTx->BRR = compute_uart_div(PeriphClk, BaudRate);
}

static uint16_t compute_uart_div(uint32_t PeriphClk, uint32_t BaudRate)
{
    return (PeriphClk + (BaudRate / 2U)) / BaudRate;
}