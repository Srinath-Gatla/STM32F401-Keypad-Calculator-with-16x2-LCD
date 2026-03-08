#ifndef STM32F401XX_H_
#define STM32F401XX_H_

#include <stdint.h>

#define __VO volatile

/* ==========================
   MEMORY BASE ADDRESSES
   ========================== */

#define FLASH_BASE_ADDRESS      0x08000000U
#define SRAM1_BASE_ADDRESS      0x20000000U
#define SRAM2_BASE_ADDRESS      0x2001C000U
#define ROM_BASE_ADDRESS        0x1FFF0000U

#define PERIPH_BASE_ADDRESS     0x40000000U
#define AHB1_BASE_ADDRESS       0x40020000U
#define AHB2_BASE_ADDRESS       0x50000000U
#define APB1_BASE_ADDRESS       PERIPH_BASE_ADDRESS
#define APB2_BASE_ADDRESS       0x40010000U


/* ==========================
   AHB1 PERIPHERALS
   ========================== */

#define GPIOA_BASE_ADDRESS      (AHB1_BASE_ADDRESS + 0x0000)
#define GPIOB_BASE_ADDRESS      (AHB1_BASE_ADDRESS + 0x0400)
#define GPIOC_BASE_ADDRESS      (AHB1_BASE_ADDRESS + 0x0800)
#define GPIOD_BASE_ADDRESS      (AHB1_BASE_ADDRESS + 0x0C00)
#define GPIOE_BASE_ADDRESS      (AHB1_BASE_ADDRESS + 0x1000)
#define GPIOH_BASE_ADDRESS      (AHB1_BASE_ADDRESS + 0x1C00)

#define RCC_BASE_ADDRESS        (AHB1_BASE_ADDRESS + 0x3800)


/* ==========================
   APB1 PERIPHERALS
   ========================== */

#define I2C1_BASE_ADDRESS       (APB1_BASE_ADDRESS + 0x5400)
#define I2C2_BASE_ADDRESS       (APB1_BASE_ADDRESS + 0x5800)
#define I2C3_BASE_ADDRESS       (APB1_BASE_ADDRESS + 0x5C00)

#define SPI2_BASE_ADDRESS       (APB1_BASE_ADDRESS + 0x3800)
#define SPI3_BASE_ADDRESS       (APB1_BASE_ADDRESS + 0x3C00)

#define USART2_BASE_ADDRESS     (APB1_BASE_ADDRESS + 0x4400)


/* ==========================
   APB2 PERIPHERALS
   ========================== */

#define SPI1_BASE_ADDRESS       (APB2_BASE_ADDRESS + 0x3000)
#define SPI4_BASE_ADDRESS       (APB2_BASE_ADDRESS + 0x3400)

#define USART1_BASE_ADDRESS     (APB2_BASE_ADDRESS + 0x1000)
#define USART6_BASE_ADDRESS     (APB2_BASE_ADDRESS + 0x1400)

#define EXTI_BASE_ADDRESS       (APB2_BASE_ADDRESS + 0x3C00)


/* ==========================
   GPIO REGISTER STRUCTURE
   ========================== */

typedef struct
{
    __VO uint32_t MODER;
    __VO uint32_t OTYPER;
    __VO uint32_t OSPEEDR;
    __VO uint32_t PUPDR;
    __VO uint32_t IDR;
    __VO uint32_t ODR;
    __VO uint32_t BSRR;
    __VO uint32_t LCKR;
    __VO uint32_t AFR[2];

} GPIO_RegDef_t;


/* ==========================
   RCC REGISTER STRUCTURE
   ========================== */

typedef struct
{
    __VO uint32_t CR;
    __VO uint32_t PLLCFGR;
    __VO uint32_t CFGR;
    __VO uint32_t CIR;

    __VO uint32_t AHB1RSTR;
    __VO uint32_t AHB2RSTR;
    __VO uint32_t RESERVED0[2];

    __VO uint32_t APB1RSTR;
    __VO uint32_t APB2RSTR;
    __VO uint32_t RESERVED1[2];

    __VO uint32_t AHB1ENR;
    __VO uint32_t AHB2ENR;
    __VO uint32_t RESERVED2[2];

    __VO uint32_t APB1ENR;
    __VO uint32_t APB2ENR;

    __VO uint32_t AHB1LPENR;
    __VO uint32_t AHB2LPENR;
    __VO uint32_t RESERVED3[2];

    __VO uint32_t APB1LPENR;
    __VO uint32_t APB2LPENR;
    __VO uint32_t RESERVED4[2];

    __VO uint32_t BDCR;
    __VO uint32_t CSR;
    __VO uint32_t RESERVED5[2];

    __VO uint32_t SSCGR;
    __VO uint32_t PLLI2SCFGR;
    __VO uint32_t RESERVED6;
    __VO uint32_t DCKCFGR;

} RCC_RegDef_t;


/* ==========================
   PERIPHERAL DEFINITIONS
   ========================== */

#define GPIOA   ((GPIO_RegDef_t*) GPIOA_BASE_ADDRESS)
#define GPIOB   ((GPIO_RegDef_t*) GPIOB_BASE_ADDRESS)
#define GPIOC   ((GPIO_RegDef_t*) GPIOC_BASE_ADDRESS)
#define GPIOD   ((GPIO_RegDef_t*) GPIOD_BASE_ADDRESS)
#define GPIOE   ((GPIO_RegDef_t*) GPIOE_BASE_ADDRESS)
#define GPIOH   ((GPIO_RegDef_t*) GPIOH_BASE_ADDRESS)

#define RCC     ((RCC_RegDef_t*) RCC_BASE_ADDRESS)


/* ==========================
   CLOCK ENABLE MACROS
   ========================== */

#define GPIOA_PCLK_EN()   (RCC->AHB1ENR |= (1 << 0))
#define GPIOB_PCLK_EN()   (RCC->AHB1ENR |= (1 << 1))
#define GPIOC_PCLK_EN()   (RCC->AHB1ENR |= (1 << 2))
#define GPIOD_PCLK_EN()   (RCC->AHB1ENR |= (1 << 3))
#define GPIOE_PCLK_EN()   (RCC->AHB1ENR |= (1 << 4))
#define GPIOH_PCLK_EN()   (RCC->AHB1ENR |= (1 << 7))

#define GPIOA_PCLK_DI()   (RCC->AHB1ENR &= ~(1 << 0))
#define GPIOB_PCLK_DI()   (RCC->AHB1ENR &= ~(1 << 1))
#define GPIOC_PCLK_DI()   (RCC->AHB1ENR &= ~(1 << 2))
#define GPIOD_PCLK_DI()   (RCC->AHB1ENR &= ~(1 << 3))
#define GPIOE_PCLK_DI()   (RCC->AHB1ENR &= ~(1 << 4))
#define GPIOH_PCLK_DI()   (RCC->AHB1ENR &= ~(1 << 7))


/* ==========================
   GENERIC MACROS
   ========================== */

#define ENABLE      1
#define DISABLE     0

#define SET         ENABLE
#define RESET       DISABLE

#define GPIO_PIN_SET    SET
#define GPIO_PIN_RESET  RESET

#endif /* STM32F401XX_H_ */
