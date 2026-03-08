#include "STM32F401_GPIO.h"
// Initalize the GPIO pin
void GPIO_Init(GPIO_Handle_t * pGPIOHandle)
{
    uint32_t temp = 0;

    // MODE
    temp = (pGPIOHandle->GPIO_config.GPIO_PinMode << (2 * pGPIOHandle->GPIO_config.GPIO_PinNumber));
    pGPIOHandle->pGPIOx->MODER &= ~(0x3 << (2 * pGPIOHandle->GPIO_config.GPIO_PinNumber));
    pGPIOHandle->pGPIOx->MODER |= temp;

    // SPEED
    temp = (pGPIOHandle->GPIO_config.GPIO_PinSpeed << (2 * pGPIOHandle->GPIO_config.GPIO_PinNumber));
    pGPIOHandle->pGPIOx->OSPEEDR &= ~(0x3 << (2 * pGPIOHandle->GPIO_config.GPIO_PinNumber));
    pGPIOHandle->pGPIOx->OSPEEDR |= temp;

    // OUTPUT TYPE
    temp = (pGPIOHandle->GPIO_config.GPIO_PinOptype << pGPIOHandle->GPIO_config.GPIO_PinNumber);
    pGPIOHandle->pGPIOx->OTYPER &= ~(0x1 << pGPIOHandle->GPIO_config.GPIO_PinNumber);
    pGPIOHandle->pGPIOx->OTYPER |= temp;

    // PULL UP / PULL DOWN
    temp = (pGPIOHandle->GPIO_config.GPIO_Pinpupdcontrol << (2 * pGPIOHandle->GPIO_config.GPIO_PinNumber));
    pGPIOHandle->pGPIOx->PUPDR &= ~(0x3 << (2 * pGPIOHandle->GPIO_config.GPIO_PinNumber));
    pGPIOHandle->pGPIOx->PUPDR |= temp;
}
void GPIO_DeInit(GPIO_RegDef_t * pGPIOx)
{
	if(pGPIOx == GPIOA)
	{
		GPIOA_REG_RESET();
	}
	else if(pGPIOx ==GPIOB)
	{
		GPIOB_REG_RESET();
	}
	else if(pGPIOx ==GPIOC)
	{
		GPIOC_REG_RESET();
	}
	else if(pGPIOx ==GPIOD)
	{
		GPIOD_REG_RESET();
	}
	else if(pGPIOx ==GPIOE)
	{
		GPIOE_REG_RESET();
	}
	else if(pGPIOx ==GPIOH)
	{
		GPIOH_REG_RESET();
	}
}
// API to initialize the clock
void GPIO_PLLCLK_Init(GPIO_RegDef_t * pGPIOx, uint8_t ENorDI)
{
	if(ENorDI == ENABLE)
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_EN();
		}
		else if(pGPIOx == GPIOB)
		{
			GPIOB_PCLK_EN();
		}
		else if(pGPIOx == GPIOC)
		{
			GPIOC_PCLK_EN();
		}
		else if(pGPIOx == GPIOD)
		{
			GPIOD_PCLK_EN();
		}
		else if(pGPIOx == GPIOE)
		{
			GPIOE_PCLK_EN();
		}
		else if (pGPIOx == GPIOH)
		{
			GPIOH_PCLK_EN();
		}

	}
	else
	{

		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_DI();
		}
		else if(pGPIOx == GPIOB)
		{
			GPIOB_PCLK_DI();
		}
		else if(pGPIOx == GPIOC)
		{
			GPIOC_PCLK_DI();
		}
		else if(pGPIOx == GPIOD)
		{
			GPIOD_PCLK_DI();
		}
		else if(pGPIOx == GPIOE)
		{
			GPIOE_PCLK_DI();
		}
		else if (pGPIOx == GPIOH)
		{
			GPIOH_PCLK_DI();
		}

	}
}
// API for read and write the programs
uint16_t  GPIO_Read_Port(GPIO_RegDef_t * pGPIOx)
{
	return (pGPIOx->IDR);
}
uint8_t GPIO_Read_Pin(GPIO_RegDef_t * pGPIOx,uint8_t pinnumber)
{
	uint16_t value;
	value= (uint8_t) (pGPIOx->IDR >> pinnumber) & 0x1;
	return value;
}
void GPIO_Write_Port(GPIO_RegDef_t * pGPIOx,uint16_t value)
{
	pGPIOx->ODR=value;
}
void GPIO_Write_Pin(GPIO_RegDef_t * pGPIOx,uint8_t pinnumber,uint8_t value)
{
	if(value == GPIO_PIN_SET)
	{
		pGPIOx->ODR |= (1<<pinnumber);
	}
	else
	{
		pGPIOx->ODR &= ~(1<<pinnumber);
	}
}
//API for Toggling Output Pin
void GPIO_Toggle_Outputpin(GPIO_RegDef_t * pGPIOx, uint8_t pinnumber)
{
	pGPIOx->ODR ^= (1<<pinnumber);
}
// API for Interrupt handler
void GPIO_IRREQ(uint8_t IRQNumber,uint8_t IRQPriority , uint8_t IRQENorDI)
{

}
void GPIO_IRHandle(uint8_t pinnumber)
{

}
