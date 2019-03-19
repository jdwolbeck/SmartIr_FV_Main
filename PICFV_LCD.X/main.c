#include <xc.h>
#include "configuration_bits.h"
#include "initialization.h"
#include "system.h"
#include "main.h"
#include "lcd.h"
#include "keypad.h"

//Global Variables
int count = 0;

int main(void) {
    
    InitApp();
    
    while(1)
    {
        checkKeys();
    }
    return 0;
}
