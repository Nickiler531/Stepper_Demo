/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
#include "./OctopusBot/OctopusBot.h"
#include <asf.h>

ISR(USARTD0_RXC_vect)
{
	int data = usart_getchar(BLUETOOTH);
	switch(data)
	{
		case '1':
			ioport_toggle_pin_level(LED1);
		break;
		case '2':
			ioport_toggle_pin_level(LED2);
		break;
		case '3':
			ioport_toggle_pin_level(LED3);
		break;
		case '4':
			ioport_toggle_pin_level(LED4);
		break;
		case '5':
			ioport_toggle_pin_level(LED5);
		break;
		case '6':
			ioport_toggle_pin_level(LED6);
		break;
	}
}

#define INIT_MAX 100
void initial_animation(void)
{
	volatile int i;
	for(i = 50;i<INIT_MAX;i+=15)
	{
		ioport_set_pin_level(LED1,1);
		delay_ms(i);
		ioport_set_pin_level(LED2,1);
		delay_ms(i);
		ioport_set_pin_level(LED3,1);
		delay_ms(i);
		ioport_set_pin_level(LED4,1);
		delay_ms(i);
		ioport_set_pin_level(LED5,1);
		delay_ms(i);
		ioport_set_pin_level(LED6,1);
		delay_ms(i);
		
		ioport_set_pin_level(LED1,0);
		delay_ms(i);
		ioport_set_pin_level(LED2,0);
		delay_ms(i);
		ioport_set_pin_level(LED3,0);
		delay_ms(i);
		ioport_set_pin_level(LED4,0);
		delay_ms(i);
		ioport_set_pin_level(LED5,0);
		delay_ms(i);
		ioport_set_pin_level(LED6,0);
		delay_ms(i);
	}
}

#define STEP IO_1
#define DIR IO_2
#define SLEEP IO_3
#define MS1 IO_6
#define MS2 IO_5
#define MS3 IO_4

void full_step()
{
	ioport_set_pin_level(MS1,0);
	ioport_set_pin_level(MS2,0);
	ioport_set_pin_level(MS3,0);
}
void half_step()
{
	ioport_set_pin_level(MS1,1);
	ioport_set_pin_level(MS2,0);
	ioport_set_pin_level(MS3,0);
}
void quarter_step()
{
	ioport_set_pin_level(MS1,0);
	ioport_set_pin_level(MS2,1);
	ioport_set_pin_level(MS3,0);
}
void either_step()
{
	ioport_set_pin_level(MS1,1);
	ioport_set_pin_level(MS2,1);
	ioport_set_pin_level(MS3,0);
}
void sixteen_step()
{
	ioport_set_pin_level(MS1,1);
	ioport_set_pin_level(MS2,1);
	ioport_set_pin_level(MS3,1);
}

#define DELAY_STEP 5
void move_stepper(int direction, int s1, int s2, int s3, int s4, int s5)
{
	ioport_set_pin_level(STEP,0);
	ioport_set_pin_level(DIR, direction);
	ioport_set_pin_level(SLEEP,1);
	int i=0;
	
	full_step();
	for(i=0;i<s1;i++)
	{
		ioport_set_pin_level(STEP,1);
		delay_ms(DELAY_STEP);
		ioport_set_pin_level(STEP,0);
		delay_ms(DELAY_STEP);
	}
	
	half_step();
	for(i=0;i<s2;i++)
	{
		ioport_set_pin_level(STEP,1);
		delay_ms(DELAY_STEP);
		ioport_set_pin_level(STEP,0);
		delay_ms(DELAY_STEP);
	}
	
	quarter_step();
	for(i=0;i<s3;i++)
	{
		ioport_set_pin_level(STEP,1);
		delay_ms(DELAY_STEP);
		ioport_set_pin_level(STEP,0);
		delay_ms(DELAY_STEP);
	}
	
	either_step();
	for(i=0;i<s4;i++)
	{
		ioport_set_pin_level(STEP,1);
		delay_ms(DELAY_STEP);
		ioport_set_pin_level(STEP,0);
		delay_ms(DELAY_STEP);
	}
	
	sixteen_step();
	for(i=0;i<s5;i++)
	{
		ioport_set_pin_level(STEP,1);
		delay_ms(DELAY_STEP);
		ioport_set_pin_level(STEP,0);
		delay_ms(DELAY_STEP);
	}
	ioport_set_pin_level(SLEEP,0);
}

int main (void)
{
	init_octopus();
	
	ioport_set_pin_dir(STEP,IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(DIR,IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(SLEEP,IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(MS1,IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(MS2,IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(MS3,IOPORT_DIR_OUTPUT);
	
	ioport_set_pin_level(STEP,0);
	ioport_set_pin_level(DIR,0);
	ioport_set_pin_level(SLEEP,0);
	ioport_set_pin_level(MS1,0);
	ioport_set_pin_level(MS2,0);
	ioport_set_pin_level(MS3,0);
	
	initial_animation();
	for (;;)
	{
		
		int direction;
		int step1;
		int step2;
		int step3;
		int step4;
		int step5;
		scanf("%1i%4x%4x%4x%4x%4x",&direction,&step1,&step2,&step3,&step4,&step5);
		move_stepper(direction,step1,step2,step3,step4,step5);
		
		if(switch_state(SW1) == 0)
		{
			ioport_set_pin_level(SLEEP,1);
			ioport_toggle_pin_level(DIR);
			full_step();
			for(int i=1;i<1000;i++)
			{
				ioport_toggle_pin_level(STEP);
				delay_ms(1);
			}
			ioport_set_pin_level(SLEEP,0);
			
			move_stepper(1,300,0,0,0,0);
			
// 			ioport_set_pin_level(LED1,1);
// 			delay_ms(200);
// 			ioport_set_pin_level(LED2,1);
// 			delay_ms(200);
// 			ioport_set_pin_level(LED3,1);
// 			delay_ms(200);
// 			ioport_set_pin_level(LED4,1);
// 			delay_ms(200);
// 			ioport_set_pin_level(LED5,1);
// 			delay_ms(200);
// 			ioport_set_pin_level(LED6,1);
// 			delay_ms(200);
		}
		if(switch_state(SW2) == 0)
		{
			move_stepper(1,120,60,10,5,5);
		}			
	}
}
