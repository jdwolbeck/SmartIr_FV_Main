#include <xc.h>
#include "uart.h"
#include "lcd.h"
#include "main.h"
void uart(char RXchar)
{
    U1TXREG = RXchar;
    uart_print(":\r\n");
    switch(RXchar)
    {
        case 'c':
            uart_print("LCD_clear()\r\n");
            LCD_clear();
            break;
        case 'd':
            uart_print("LCD_display(\"Hello World!\")\r\n");
            LCD_display("Hello World!");
            break;
        case 'h':
            uart_print("LCD_home()\r\n");
            LCD_home();
            break;
        case '1':
            uart_print("LCD_firstLine()\r\n");
            LCD_firstLine();
            break;
        case '2':
            uart_print("LCD_secondLine()\r\n");
            LCD_secondLine();
            break;
        default:
            uart_print("Invalid Input\r\n");
            break;
    }
}

void uart_print(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        while(!U1STAbits.TRMT);
        U1TXREG = str[i++];
    }
}
