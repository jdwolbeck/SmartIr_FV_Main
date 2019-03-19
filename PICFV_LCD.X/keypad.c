#include <xc.h>
#include <stdbool.h>
#include "lcd.h"
#include "keypad.h"

int btnPressed = 0;
bool btnEnable = true;

void checkKeys(void)
{
    if(btnOne == 1 && btnEnable)
    {
        LATBbits.LATB6= 1;
        btnPressed = 1;
        btnEnable = false;
    }
    else if(btnTwo == 1 && btnEnable)
    {
        btnPressed = 2;
        btnEnable = false;
    }
    else if(btnThree == 1 && btnEnable)
    {
        btnPressed = 3;
        btnEnable = false;
    }
    else if(btnFour == 1 && btnEnable)
    {
        btnPressed = 4;
        btnEnable = false;
    }
    LCD_keypadUpdate(btnPressed, btnEnable);
}

void LCD_keypadUpdate(int btnPressed, bool btnEnable)
{
    if(btnPressed != 0 && btnEnable != false)
    {
       if(btnPressed == 1)
           LCD_waterMenu1();
    }
}