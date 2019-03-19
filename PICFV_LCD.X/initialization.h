#include <xc.h> // include processor files - each processor file is guarded.  

#define freq 4000000
#define baud_rate 9600

void InitApp(void);
void InitGPIO(void);
void InitTimer(void);
void InitUART(void);
void InitLCD(void);
void InitKPad(void);
