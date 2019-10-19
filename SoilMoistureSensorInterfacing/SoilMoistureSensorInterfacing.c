/*
 * SensorInterfacing.c
 *
 * Created: 10-Oct-19 10:13:47 PM
 * Modified: 19-Oct-19 2:52:12 PM
 * Author: Debdut
 * Modifier: Debdut
 */ 

#define F_CPU 14745600UL
//#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "lcd.h"
#include "sm.h"

void port_init();
void init_devices(void);

//Function to initialize PORTS
void port_init()
{
	lcd_init();
	sm_init(); //call FC-28 initialization
}

//Function to initialize all devices
void init_devices (void)
{
	cli(); //Clears the global interrupts
	port_init();
	sei();   //Enables the global interrupts
}

int main(void)
{
	init_devices();
	adc_init(); //call ADC initialization
	
	lcd_cursor(1,3);
	lcd_string("HACTOBER-2K19");
	lcd_cursor(2,4);
	lcd_string("OPENSOURCE");
	_delay_ms(2000);
	lcd_clear();
	
	lcd_cursor(1,2);
	lcd_string("SOIL MOISTURE");
	lcd_cursor(2,10);
	lcd_string("%");
	
    while(1)
    {
		lcd_print(2,7,moistureReading(),3); //call moistureReading function as val parameter
		_delay_ms(100);
    }
}