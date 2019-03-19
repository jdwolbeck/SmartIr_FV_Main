#include <xc.h>
#include <stdbool.h>

#define RS LATBbits.LATB5
#define RW LATBbits.LATB3
#define EN LATAbits.LATA0
#define D7 LATBbits.LATB15
#define D6 LATBbits.LATB14
#define D5 LATBbits.LATB13
#define D4 LATBbits.LATB12
#define D3 LATBbits.LATB11
#define D2 LATBbits.LATB10
#define D1 LATBbits.LATB9
#define D0 LATBbits.LATB8

void LCD_begin(void);
void LCD_clear(void);
void LCD_home(void);
void LCD_firstLine(void);
void LCD_secondLine(void);
void LCD_blink(bool);
void LCD_display(char[]);
void LCD_write(bool,bool,bool,bool,bool,bool,bool,bool,bool);
void LCD_read(bool,bool,bool,bool,bool,bool,bool,bool,bool);
void LCD_mainMenu(void);
void LCD_waterMenu1(void);