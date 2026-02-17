#ifndef ADC_H_
#define ADC_H_

#include <stdint.h>
#include "main.h"

typedef struct
{
    __IO uint32_t SR;  //!< ADC status register,						Address offset: 0x00
    __IO uint32_t CR1; //!< ADC control register 1,					Address offset: 0x04
    __IO uint32_t CR2; //!< ADC control register 2,					Address offset: 0x08
    __IO uint32_t SMPR1; //!< ADC sample time register 1,            Address offset: 0x0C
    __IO uint32_t SMPR2; //!< ADC sample time register 2,            Address offset: 0x10
    __IO uint32_t JOFR1; //!< ADC injected channel data offset register 1, Address offset: 0x14
    __IO uint32_t JOFR2; //!< ADC injected channel data offset register 2, Address offset: 0x18
    __IO uint32_t JOFR3; //!< ADC injected channel data offset register 3   , Address offset: 0x1C
    __IO uint32_t JOFR4; //!< ADC injected channel data offset register 4, Address offset: 0x20
    __IO uint32_t HTR;  //!< ADC watchdog higher threshold register, Address offset: 0x24
    __IO uint32_t LTR;  //!< ADC watchdog lower threshold register, Address offset: 0x28
    __IO uint32_t SQR1; //!< ADC regular sequence register 1, Address offset: 0x2C
    __IO uint32_t SQR2; //!< ADC regular sequence register 2, Address offset: 0x30
    __IO uint32_t SQR3; //!< ADC regular sequence register 3, Address offset: 0x34
    __IO uint32_t JSQR; //!< ADC injected sequence register, Address offset: 0x38
    __IO uint32_t JDR1; //!< ADC injected data register 1, Address offset: 0x3C
    __IO uint32_t JDR2; //!< ADC injected data register 2, Address offset: 0x40
    __IO uint32_t JDR3; //!< ADC injected data register 3, Address offset: 0x44
    __IO uint32_t JDR4; //!< ADC injected data register 4, Address offset: 0x48
    __IO uint32_t DR;   //!< ADC regular data register, Address offset: 0x4C
    __IO uint32_t CSR;  //!< ADC common status register, Address offset: 0x50
}ADC_TypeDef;



#define ADC1_OFFSET (0x2000UL)                    // 0x0001 2000
#define ADC1_BASE (APB2PERIPH_BASE + ADC1_OFFSET) // 0x0001 2000
#define ADC1 ((ADC_TypeDef *)ADC1_BASE)

#define ADC1EN (1U << 8)
#define ADC_CH1 (1U << 0)
#define ADC_SEQ_LEN_1 0x00
#define CR2_ADON (1U << 0)
#define CR2_SWSTART (1U << 30)
#define SR_EOC (1U << 1)

void pal_adc_init(void);
uint32_t adc_read(void);
void start_conversion(void);

#endif /* ADC_H_ */