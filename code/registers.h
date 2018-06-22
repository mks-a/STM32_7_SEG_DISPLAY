#include "memory_mapping.h"

// reset and clock cotrol registers
#define RCC_CR (RCC + 0x00)					// clock control register
#define RCC_CFGR (RCC + 0x04)				// clock configuration register
#define RCC_CIR (RCC + 0x08)				// clock interrupt register
#define RCC_APB2RSTR (RCC + 0x0C)			// APB2 peripherial reset register (APB - advanced peripherial bus)
#define RCC_APB1RSTR (RCC + 0x10)			// APB1 peripherial reset register
#define RCC_AHBENR (RCC + 0x14)				// AHB peripherial clock enable register (AHB - advanced high performance bus)
#define RCC_APB2ENR (RCC + 0x18)			// APB2 peripherial clock enable register
#define RCC_APB1ENR (RCC + 0x1C)			// APB1 peripherial clock enable register
#define RCC_BDCR (RCC + 0x20)				// backup domain control register	
#define RCC_CSR (RCC + 0x24)				// control/status register

// GPIO port C registers
#define GPIOC_CRL PORT_C					// port C control register low
#define GPIOC_CRH (PORT_C + 0x04)			// port C control register high
#define GPIOC_IDR (PORT_C + 0x08)			// port C input data register
#define GPIOC_ODR (PORT_C + 0x0C)			// port C output data register
#define GPIOC_BSRR (PORT_C + 0x10)			// port C bit set/reset register
#define GPIOC_BRR (PORT_C + 0x14)			// port C bit reset register (16 bit)
#define GPIOC_LCKR (PORT_C + 0x18)			// port C configuration lock register
