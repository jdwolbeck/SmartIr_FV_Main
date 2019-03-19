#include <xc.h>
#include "initialization.h"
#include "lcd.h"
#include "keypad.h"

void InitApp(void)
{
    InitGPIO();
    InitUART();
    InitLCD();
    InitKPad();
}

void InitGPIO(void)
{
    LATB = 0;
    //Set direction of RB pins (1 = input | 0 = output)
    TRISB = 0xFFFF;
    TRISA = 0xFFFF;
    TRISBbits.TRISB6 = 0; //EXTERNAL LED
    //Set pins as digital input pins
    ANSB = 0;
    ANSA = 0;
}

void InitTimer(void)
{
    
}

void InitUART(void)
{
    TRISBbits.TRISB7 = 0;
    Nop();
    TRISBbits.TRISB2 = 1;
    Nop();
    
    U1MODE = 0;
    U1STA = 0;
    
    IFS0bits.U1RXIF = 0;
    IPC2bits.U1RXIP = 3;
    IEC0bits.U1RXIE = 1;
    U1BRG = (((freq)/baud_rate)/16)-1;
    
    U1MODEbits.UARTEN = 1;
    U1STAbits.UTXEN = 1;
    while(U1STAbits.TRMT == 0);
}

void InitLCD(void)
{
    //LCD D7-D0
    TRISBbits.TRISB15 = 0;
    TRISBbits.TRISB14 = 0;
    TRISBbits.TRISB13 = 0;
    TRISBbits.TRISB12 = 0;
    TRISBbits.TRISB11 = 0;
    TRISBbits.TRISB10 = 0;
    TRISBbits.TRISB9 = 0;
    TRISBbits.TRISB8 = 0;
    
    //LCD RS
    TRISBbits.TRISB5 = 0;
    
    //LCD RW
    TRISBbits.TRISB3 = 0;
    
    //LCD EN
    TRISAbits.TRISA0 = 0;
    
    LCD_begin();
    Nop();
    LCD_clear();
}

void InitKPad()
{
    //Keypad 1-4 (Input)
    TRISAbits.TRISA4 = 1;
    TRISAbits.TRISA3 = 1;
    TRISAbits.TRISA2 = 1;
    TRISAbits.TRISA1 = 1;
    Nop();
    LCD_mainMenu();
}