/*
 * OctopusBot.c
 *
 * Created: 3/30/2013 6:38:02 PM
 *  Author: Nick
 */ 

#include "./../OctopusBot.h"
#include <asf.h>




void init_octopus(void)
{
	sysclk_init();
	ioport_init();
	leds_init();
	bluetooth_init();
	//bluetooth_init_interrupt();
	switch_init();
	usb_init();	
}






void init_motors(void)
{
	 
}

void init_virtual_comm(void)
{
	irq_initialize_vectors();
	cpu_irq_enable();
	udc_start();
	udc_attach();
}	

void move_motor_1(int dir, int vel)
{
	if(dir == FORWARD)
	{
		ioport_set_pin_level(MOTOR1_B,OFF);
		pwm_start(&pwm_mot1, vel);
	}
	else
	{
		ioport_set_pin_level(MOTOR1_B,ON);
		pwm_start(&pwm_mot1, 100-vel);
	}
	
}

void blink(void){
	ioport_set_pin_level(LED1,ON);
	ioport_set_pin_level(LED2,ON);
	delay_s(1);
	ioport_set_pin_level(LED1,OFF);
	ioport_set_pin_level(LED2,OFF);
	delay_s(1);
}

void forward(void)
{
	ioport_set_pin_level(MOTOR1_A,ON);
 	ioport_set_pin_level(MOTOR2_A,ON);
	ioport_set_pin_level(MOTOR3_A,ON);
 	ioport_set_pin_level(MOTOR4_A,ON);
	
	ioport_set_pin_level(MOTOR1_B,OFF);
 	ioport_set_pin_level(MOTOR2_B,OFF);
	ioport_set_pin_level(MOTOR3_B,OFF);
 	ioport_set_pin_level(MOTOR4_B,OFF);
}

#define DELAYGO_1 2
#define DELAYSTOP_1 13 

#define DELAYGO_2 5
#define DELAYSTOP_2 10

#define DELAYGO_3 7
#define DELAYSTOP_3 7

#define DELAYGO_4 10
#define DELAYSTOP_4 5

#define DELAYGO_5 14
#define DELAYSTOP_5 1

void forward_1(void)
{
	forward();
	delay_ms(DELAYGO_1);
	stop();
	delay_ms(DELAYSTOP_1);
	forward();
}

void forward_2(void)
{
	forward();
	delay_ms(DELAYGO_2);
	stop();
	delay_ms(DELAYSTOP_2);
	forward();
}

void forward_3(void)
{
	forward();
	delay_ms(DELAYGO_3);
	stop();
	delay_ms(DELAYSTOP_3);
	forward();
}
void forward_4(void)
{
	forward();
	delay_ms(DELAYGO_4);
	stop();
	delay_ms(DELAYSTOP_4);
	forward();
}
void forward_5(void)
{
	forward();
	delay_ms(DELAYGO_5);
	stop();
	delay_ms(DELAYSTOP_5);
	forward();
}

void backward_1(void)
{
	backward();
	delay_ms(DELAYGO_1);
	stop();
	delay_ms(DELAYSTOP_1);
	backward();
}

void backward_2(void)
{
	backward();
	delay_ms(DELAYGO_2);
	stop();
	delay_ms(DELAYSTOP_2);
	backward();
}

void backward_3(void)
{
	backward();
	delay_ms(DELAYGO_3);
	stop();
	delay_ms(DELAYSTOP_3);
	backward();
}
void backward_4(void)
{
	backward();
	delay_ms(DELAYGO_4);
	stop();
	delay_ms(DELAYSTOP_4);
	backward();
}
void backward_5(void)
{
	backward();
	delay_ms(DELAYGO_5);
	stop();
	delay_ms(DELAYSTOP_5);
	backward();
}

void turn_left_1(void)
{
	turn_left();
	delay_ms(DELAYGO_1);
	stop();
	delay_ms(DELAYSTOP_1);
	turn_left();
}

void turn_left_2(void)
{
	turn_left();
	delay_ms(DELAYGO_2);
	stop();
	delay_ms(DELAYSTOP_2);
	turn_left();
}

void turn_left_3(void)
{
	turn_left();
	delay_ms(DELAYGO_3);
	stop();
	delay_ms(DELAYSTOP_3);
	turn_left();
}

void turn_left_4(void)
{
	turn_left();
	delay_ms(DELAYGO_4);
	stop();
	delay_ms(DELAYSTOP_4);
	turn_left();
}

void turn_left_5(void)
{
	turn_left();
	delay_ms(DELAYGO_5);
	stop();
	delay_ms(DELAYSTOP_5);
	turn_left();
}

void turn_right_1(void)
{
	turn_right();
	delay_ms(DELAYGO_1);
	stop();
	delay_ms(DELAYSTOP_1);
	turn_right();
}

void turn_right_2(void)
{
	turn_right();
	delay_ms(DELAYGO_2);
	stop();
	delay_ms(DELAYSTOP_2);
	turn_right();
}

void turn_right_3(void)
{
	turn_right();
	delay_ms(DELAYGO_3);
	stop();
	delay_ms(DELAYSTOP_3);
	turn_right();
}

void turn_right_4(void)
{
	turn_right();
	delay_ms(DELAYGO_4);
	stop();
	delay_ms(DELAYSTOP_4);
	turn_right();
}

void turn_right_5(void)
{
	turn_right();
	delay_ms(DELAYGO_5);
	stop();
	delay_ms(DELAYSTOP_5);
	turn_right();
}


void backward(void)
{
	ioport_set_pin_level(MOTOR1_A,OFF);
	ioport_set_pin_level(MOTOR2_A,OFF);
	ioport_set_pin_level(MOTOR3_A,OFF);
	ioport_set_pin_level(MOTOR4_A,OFF);
	
	ioport_set_pin_level(MOTOR1_B,ON);
	ioport_set_pin_level(MOTOR2_B,ON);
	ioport_set_pin_level(MOTOR3_B,ON);
	ioport_set_pin_level(MOTOR4_B,ON);
}



void turn_left(void)
{
	ioport_set_pin_level(MOTOR1_A,OFF);
	ioport_set_pin_level(MOTOR2_A,ON);
	ioport_set_pin_level(MOTOR3_A,OFF);
	ioport_set_pin_level(MOTOR4_A,ON);
	
	ioport_set_pin_level(MOTOR1_B,ON);
	ioport_set_pin_level(MOTOR2_B,OFF);
	ioport_set_pin_level(MOTOR3_B,ON);
	ioport_set_pin_level(MOTOR4_B,OFF);
}
void turn_right(void)
{
	ioport_set_pin_level(MOTOR1_A,ON);
	ioport_set_pin_level(MOTOR2_A,OFF);
	ioport_set_pin_level(MOTOR3_A,ON);
	ioport_set_pin_level(MOTOR4_A,OFF);
	
	ioport_set_pin_level(MOTOR1_B,OFF);
	ioport_set_pin_level(MOTOR2_B,ON);
	ioport_set_pin_level(MOTOR3_B,OFF);
	ioport_set_pin_level(MOTOR4_B,ON);
}

void stop(void)
{
	ioport_set_pin_level(MOTOR1_A,OFF);
	ioport_set_pin_level(MOTOR2_A,OFF);
	ioport_set_pin_level(MOTOR3_A,OFF);
	ioport_set_pin_level(MOTOR4_A,OFF);
	
	ioport_set_pin_level(MOTOR1_B,OFF);
	ioport_set_pin_level(MOTOR2_B,OFF);
	ioport_set_pin_level(MOTOR3_B,OFF);
	ioport_set_pin_level(MOTOR4_B,OFF);
}
