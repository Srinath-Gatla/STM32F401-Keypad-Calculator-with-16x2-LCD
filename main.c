#include "STM32F401_LCD.h"
#include "STM32F401_KEYPAD.h"

/* Keypad Configuration */
Keypad_Handle_t MyKeypad =
{
    .Rp = GPIOB,
    .Cp = GPIOC,
    .rows = {12,13,14,15},
    .cols = {0,1,2,3},
};

int main()
{
    LCD_Handle_t LCD;

    /* LCD DATA PINS CONFIGURATION (PA0–PA7) */
    for(uint32_t i = 0; i < 8; i++)
    {
        LCD.data[i].pGPIOx = GPIOA;
        LCD.data[i].GPIO_config.GPIO_PinNumber = i;
        LCD.data[i].GPIO_config.GPIO_PinMode = GPIO_MODE_OUT;
        LCD.data[i].GPIO_config.GPIO_PinSpeed = GPIO_SPEED_HIGH;
        LCD.data[i].GPIO_config.GPIO_Pinpupdcontrol = GPIO_NO_PUPD;
        LCD.data[i].GPIO_config.GPIO_PinOptype = GPIO_OP_TYPE_PP;
    }

    /* LCD CONTROL PINS */

    /* EN */
    LCD.EN.pGPIOx = GPIOB;
    LCD.EN.GPIO_config.GPIO_PinNumber = GPIO_PIN_0;
    LCD.EN.GPIO_config.GPIO_PinMode = GPIO_MODE_OUT;
    LCD.EN.GPIO_config.GPIO_PinSpeed = GPIO_SPEED_HIGH;
    LCD.EN.GPIO_config.GPIO_Pinpupdcontrol = GPIO_NO_PUPD;
    LCD.EN.GPIO_config.GPIO_PinOptype = GPIO_OP_TYPE_PP;

    /* RS */
    LCD.RS.pGPIOx = GPIOB;
    LCD.RS.GPIO_config.GPIO_PinNumber = GPIO_PIN_1;
    LCD.RS.GPIO_config.GPIO_PinMode = GPIO_MODE_OUT;
    LCD.RS.GPIO_config.GPIO_PinSpeed = GPIO_SPEED_HIGH;
    LCD.RS.GPIO_config.GPIO_Pinpupdcontrol = GPIO_NO_PUPD;
    LCD.RS.GPIO_config.GPIO_PinOptype = GPIO_OP_TYPE_PP;

    /* RW */
    LCD.RW.pGPIOx = GPIOB;
    LCD.RW.GPIO_config.GPIO_PinNumber = GPIO_PIN_2;
    LCD.RW.GPIO_config.GPIO_PinMode = GPIO_MODE_OUT;
    LCD.RW.GPIO_config.GPIO_PinSpeed = GPIO_SPEED_HIGH;
    LCD.RW.GPIO_config.GPIO_Pinpupdcontrol = GPIO_NO_PUPD;
    LCD.RW.GPIO_config.GPIO_PinOptype = GPIO_OP_TYPE_PP;

    /* Initialize LCD and Keypad */
    InitLCD(&LCD);
    InitKeypad(&MyKeypad);

    /* Calculator Variables */
    char key;
    char op = 0;

    uint32_t num1 = 0;
    uint32_t num2 = 0;
    uint32_t result = 0;

    CmdLCD(&LCD,CLEAR_LCD);

    while(1)
    {
        key = Press_Key(&MyKeypad);

        if(key)
        {
            CharLCD(&LCD,key);

            /* NUMBER INPUT */
            if(key >= '0' && key <= '9')
            {
                if(op == 0)
                {
                    num1 = num1 * 10 + (key - '0');
                }
                else
                {
                    num2 = num2 * 10 + (key - '0');
                }
            }

            /* OPERATOR INPUT */
            else if(key=='+' || key=='-' || key=='*' || key=='/')
            {
                if(op != 0)
                {
                    switch(op)
                    {
                        case '+': num1 = num1 + num2; break;
                        case '-': num1 = num1 - num2; break;
                        case '*': num1 = num1 * num2; break;

                        case '/':
                            if(num2 != 0)
                                num1 = num1 / num2;
                            else
                            {
                                CmdLCD(&LCD,CLEAR_LCD);
                                StrLCD(&LCD,"Math Error");
                                num1 = num2 = 0;
                                op = 0;
                                continue;
                            }
                            break;
                    }

                    num2 = 0;
                }

                op = key;
            }

            /* EQUAL OPERATION */
            else if(key == '=')
            {
                switch(op)
                {
                    case '+': result = num1 + num2; break;
                    case '-': result = num1 - num2; break;
                    case '*': result = num1 * num2; break;

                    case '/':
                        if(num2 != 0)
                            result = num1 / num2;
                        else
                        {
                            CmdLCD(&LCD,CLEAR_LCD);
                            StrLCD(&LCD,"Math Error");
                            num1 = num2 = 0;
                            op = 0;
                            continue;
                        }
                        break;
                }

                CmdLCD(&LCD,CLEAR_LCD);
                NumLCD(&LCD,result);

                num1 = result;
                num2 = 0;
                op = 0;
            }

            /* CLEAR BUTTON */
            else if(key == 'c')
            {
                CmdLCD(&LCD,CLEAR_LCD);
                num1 = 0;
                num2 = 0;
                op = 0;
            }
        }
    }
}
