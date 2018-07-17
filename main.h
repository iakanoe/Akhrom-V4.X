#define MAIN_H
#include <xc.h>

#pragma config PLLDIV = 5, CPUDIV = OSC1_PLL2, USBDIV = 2, FOSC = HSPLL_HS, FCMEN = OFF, IESO = OFF, PWRT = OFF
#pragma config BOR = OFF, BORV = 0, VREGEN = OFF, WDT = OFF, WDTPS = 32768, CCP2MX = ON
#pragma config PBADEN = OFF, LPT1OSC = OFF, MCLRE = OFF, STVREN = OFF, LVP = OFF, XINST = OFF
#pragma config CP0 = OFF, CP1 = OFF, CP2 = OFF, CP3 = OFF, CPB = OFF, CPD = OFF
#pragma config WRT0 = OFF, WRT1 = OFF, WRT2 = OFF, WRT3 = OFF, WRTC = OFF, WRTB = OFF, WRTD = OFF
#pragma config EBTR0 = OFF, EBTR1 = OFF, EBTR2 = OFF, EBTR3 = OFF, EBTRB = OFF

#define TRIS_BTN_1  TRISBbits.RB0
#define TRIS_BTN_2  TRISBbits.RB1
#define TRIS_BTN_L  TRISAbits.RA5
#define PORT_BTN_1  PORTBbits.RB0
#define PORT_BTN_2  PORTBbits.RB1
#define PORT_BTN_L  PORTAbits.RA5

#define TRIS_LED_R  TRISBbits.RB2
#define TRIS_LED_A  TRISBbits.RB3
#define TRIS_LED_V  TRISBbits.RB4
#define LAT_LED_R   LATBbits.LB2
#define LAT_LED_A   LATBbits.LB3
#define LAT_LED_V   LATBbits.LB4

#define TRIS_IR_1   TRISAbits.RA4
#define TRIS_IR_2   TRISAbits.RA3
#define TRIS_IR_3   TRISAbits.RA2
#define TRIS_IR_4   TRISBbits.RB5
#define TRIS_IR_5   TRISCbits.RC7
#define PORT_IR_1   PORTAbits.RA4
#define PORT_IR_2   PORTAbits.RA3
#define PORT_IR_3   PORTAbits.RA2
#define PORT_IR_4   PORTBbits.RB5
#define PORT_IR_5   PORTCbits.RC7

#define TRIS_CNY_1  TRISAbits.RA0
#define TRIS_CNY_2  TRISAbits.RA1
#define PORT_CNY_1  PORTAbits.RA0
#define PORT_CNY_2  PORTAbits.RA1

#define TRIS_DIR_D  TRISCbits.RC6
#define TRIS_DIR_I  TRISCbits.RC0
#define LAT_DIR_D   LATCbits.LC6
#define LAT_DIR_I   LATCbits.LC0

#define TRIS_PWM_D  TRISCbits.RC2
#define TRIS_PWM_I  TRISCbits.RC1
#define LAT_PWM_D   LATCbits.LC2
#define LAT_PWM_I   LATCbits.LC1

enum {
    OUTPUT,
    INPUT
};

#define BTNL 0

#define btn(n) (n == 1 ? !PORT_BTN_1 : (n == 2 ? !PORT_BTN_2 : (n == BTNL ? !PORT_BTN_L : 0)))
#define ir(n) (n == 1 ? !PORT_IR_1 : (n == 2 ? !PORT_IR_2 : (n == 3 ? !PORT_IR_3 : (n == 4 ? !PORT_IR_4 : (n == 5 ? !PORT_IR_5 : 0)))))
#define cny(n) (n == 1 ? !PORT_CNY_1 : (n == 2 ? !PORT_CNY_2 : 0))
#define limitar(x, min, max) (x > max ? max : (x < min ? min : x))
#define bState(n) estado=n;break

void setMotores(int dutyI, int dutyD);
unsigned long millis();

enum {
    MENU,
    LIMPIAR,
    ESPERA,
    ANALISIS,
    ATAQUE, 
    DER, 
    DERA,
    DERAV,
    IZQ, 
    IZQA,
    IZQAV,
    ATRAS,
    TEST_CNY
};