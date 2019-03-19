#include <xc.h>
#include <stdbool.h>
#include "lcd.h"
#include "system.h"

void LCD_begin(void)
{
    //Function Set: (Command, -, -, 1, 8-bit, 2-line, 5x8, -, -)
    LCD_write(0,0,0,1,1,1,0,0,0);
    delay(5);
    
    //Display/Cursor: (Command, - , -, -, -, 1, DisplayOn, CursorOn, BlinkingOn)
    LCD_write(0,0,0,0,0,1,1,1,1);
    delay(1);
    
    //Entry Mode: (Command, -, -, -, -, -, 1, Increment(Right), No Shift))
    LCD_write(0,0,0,0,0,0,1,1,0);
    delay(1);
}

void LCD_clear(void)
{
    //Clear Display
    LCD_write(0,0,0,0,0,0,0,0,1);
    delay(1);
}

void LCD_home(void)
{
    //Return Home
    LCD_write(0,0,0,0,0,0,0,1,0);
}

void LCD_firstLine(void)
{
    LCD_write(0,1,0,0,0,0,0,0,0);
}

void LCD_secondLine(void)
{
    LCD_write(0,1,1,0,0,0,0,0,0);
}

void LCD_blink(bool state)
{
    if(state) //Display ON, Blinking ON
        LCD_write(0,0,0,0,0,1,1,1,1);
    else //Display ON, Cursor OFF
        LCD_write(0,0,0,0,0,1,1,0,0);
}

void LCD_display(char str[])
{       
    bool d7, d6, d5, d4, d3, d2, d1, d0;
    
    int i = 0;
    while(str[i] != '\0')
    {
        d7 = str[i] & 0x80;
        d6 = str[i] & 0x40;
        d5 = str[i] & 0x20;
        d4 = str[i] & 0x10;
        d3 = str[i] & 0x08;
        d2 = str[i] & 0x04;
        d1 = str[i] & 0x02;
        d0 = str[i++] & 0x01;
        LCD_write(1,d7,d6,d5,d4,d3,d2,d1,d0);
    }
}

void LCD_write(bool rs, bool d7, bool d6, bool d5, bool d4, bool d3, bool d2, bool d1, bool d0)
{
    RS = rs;
    RW = 0;
    D7 = d7;
    D6 = d6;
    D5 = d5;
    D4 = d4;
    D3 = d3;
    D2 = d2;
    D1 = d1;
    D0 = d0;
    
    EN = 1;
    EN = 0;
}

void LCD_read(bool rs, bool d7, bool d6, bool d5, bool d4, bool d3, bool d2, bool d1, bool d0)
{
    RS = rs;
    RW = 1;
    D7 = d7;
    D6 = d6;
    D5 = d5;
    D4 = d4;
    D3 = d3;
    D2 = d2;
    D1 = d1;
    D0 = d0;
    
    EN = 1;
    EN = 0;
}

void LCD_mainMenu(void)
{
    LCD_clear();
    LCD_display("1.Water   2.Data");
    LCD_secondLine();
    LCD_display("3.WiFi    4.More");
    LCD_blink(0);
}

void LCD_waterMenu1(void)
{
    LCD_clear();
    LCD_display("WATERFAM");
}