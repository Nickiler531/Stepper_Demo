/*
 * OctopusBot.h
 *
 * Created: 3/30/2013 5:49:54 PM
 *  Author: Nick
 */ 


#ifndef OCTOPUSBOT_H_
#define OCTOPUSBOT_H_

#include <asf.h>
#include <stdio.h>
#include "include/bluetooth.h"
#include "include/leds.h"
#include "include/motors.h"
#include "include/switch.h"
#include "include/usb_serial.h"
#include "include/PWM.h"

enum{
	FALSE=0,
	TRUE
	};

#define FORWARD 1
#define BACKWARD 2

#define IO_1 IOPORT_CREATE_PIN(PORTA, 0)
#define IO_2 IOPORT_CREATE_PIN(PORTA, 1)
#define IO_3 IOPORT_CREATE_PIN(PORTA, 2)
#define IO_4 IOPORT_CREATE_PIN(PORTA, 3)
#define IO_5 IOPORT_CREATE_PIN(PORTB, 0)
#define IO_6 IOPORT_CREATE_PIN(PORTB, 1)
#define IO_7 IOPORT_CREATE_PIN(PORTB, 2)
#define IO_8 IOPORT_CREATE_PIN(PORTB, 3)



// Definifiones antiguas. Con la nueva configuración se puede cambiar la direccion de los motores
// #define MOTOR1_A IOPORT_CREATE_PIN(PORTE, 2)
// #define MOTOR1_B IOPORT_CREATE_PIN(PORTE, 3)
// #define MOTOR2_A IOPORT_CREATE_PIN(PORTE, 1)
// #define MOTOR2_B IOPORT_CREATE_PIN(PORTE, 0)
// #define MOTOR3_A IOPORT_CREATE_PIN(PORTA, 6)
// #define MOTOR3_B IOPORT_CREATE_PIN(PORTA, 7)
// #define MOTOR4_A IOPORT_CREATE_PIN(PORTA, 5)
// #define MOTOR4_B IOPORT_CREATE_PIN(PORTA, 4)





void blink(void);
void forward(void);

void forward_1(void);
void forward_2(void);
void forward_3(void);
void forward_4(void);
void forward_5(void);

void backward_1(void);
void backward_2(void);
void backward_3(void);
void backward_4(void);
void backward_5(void);

void turn_right_1(void);
void turn_right_2(void);
void turn_right_3(void);
void turn_right_4(void);
void turn_right_5(void);

void turn_left_1(void);
void turn_left_2(void);
void turn_left_3(void);
void turn_left_4(void);
void turn_left_5(void);

void turn_left(void);
void turn_right(void);
void backward(void);
void move_motor_1(int dir, int vel);
void init_motors(void);

void init_servo(int servo_num);
void update_servo(int servo_num,double duty);

void init_bluetooth(void);
void init_virtual_comm(void);
void init_bluetooth_interrupt(void);
void init_octopus(void);
void stop(void);

#endif /* OCTOPUSBOT_H_ */