#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdbool.h>

#define btnOne LATAbits.LATA4
#define btnTwo LATAbits.LATA3
#define btnThree LATAbits.LATA2
#define btnFour LATAbits.LATA1

void checkKeys(void);
void LCD_keypadUpdate(int, bool);
