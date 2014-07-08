/*
 * motors.c
 *
 * Created: 12/08/2013 02:37:44 p.m.
 *  Author: Nick
 */ 

#include "../include/motors.h"

void motors_init(void)
{
	pwm_init(&pwm_mot1, PWM_TCE0, PWM_CH_C, MOTOR_FREQUENCY);
	pwm_init(&pwm_mot2, PWM_TCE0, PWM_CH_B, MOTOR_FREQUENCY);
	pwm_init(&pwm_mot3, PWM_TCE0, PWM_CH_D, MOTOR_FREQUENCY);
	pwm_init(&pwm_mot4, PWM_TCE0, PWM_CH_A, MOTOR_FREQUENCY);
	
	pwm_start(&pwm_mot1,0);
	pwm_start(&pwm_mot2,0);
	pwm_start(&pwm_mot3,0);
	pwm_start(&pwm_mot4,0);
	
	//ioport_set_pin_dir(MOTOR1_A, IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(MOTOR1_B, IOPORT_DIR_OUTPUT);
	//ioport_set_pin_dir(MOTOR2_A, IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(MOTOR2_B, IOPORT_DIR_OUTPUT);
	//ioport_set_pin_dir(MOTOR3_A, IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(MOTOR3_B, IOPORT_DIR_OUTPUT);
	//ioport_set_pin_dir(MOTOR4_A, IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(MOTOR4_B, IOPORT_DIR_OUTPUT);
	
}

void motor1_vel(int vel)
{
	if(vel>0)
	{
		ioport_set_pin_dir(MOTOR1_B,0);
		
		tc_write_cc_buffer(pwm_mot1.tc, pwm_mot1.channel,
		(uint16_t)(((double)pwm_mot1.period *
		(double)vel) / 100));
	}
	else
	{
		
	}
}