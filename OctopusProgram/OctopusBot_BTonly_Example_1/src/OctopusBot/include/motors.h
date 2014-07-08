/*
 * motors.h
 *
 *
 * DeepSea Developments
 *
 * Developed for the OctopusBot BTonly version. Open Source
 *
 * Created: 25/07/2013 11:32:22 p.m.
 *  Author: Nick
 */ 

#include "../OctopusBot.h"

#ifndef MOTORS_H_
#define MOTORS_H_


/* For default Dir A of every motor is set. If the motor supose to go forward but go backwards,
the corresponding motor_dir should be change to dir B */

#define MOTOR_1_DIR_A
//#define MOTOR_1_DIR_B

//#define MOTOR_2_DIR_A
#define MOTOR_2_DIR_B

//#define MOTOR_3_DIR_A
#define MOTOR_3_DIR_B

//#define MOTOR_4_DIR_A
#define MOTOR_4_DIR_B



#define MOTOR_FREQUENCY 10000

const struct pwm_config pwm_mot1;
const struct pwm_config pwm_mot2;
const struct pwm_config pwm_mot3;
const struct pwm_config pwm_mot4;


#ifdef MOTOR_1_DIR_A
//#define MOTOR_1_PWM_INIT pwm_init(&pwm_mot1, PWM_TCE0, PWM_CH_C, MOTOR_FREQUENCY);
#define MOTOR1_A IOPORT_CREATE_PIN(PORTE, 2)
#define MOTOR1_B IOPORT_CREATE_PIN(PORTA, 6)
#endif /*MOTOR_1_DIR_A*/

#ifdef MOTOR_1_DIR_B
#define MOTOR1_B IOPORT_CREATE_PIN(PORTE, 2)
#define MOTOR1_A IOPORT_CREATE_PIN(PORTA, 6)
#endif /*MOTOR_1_DIR_B*/

#ifdef MOTOR_2_DIR_A
#define MOTOR2_A IOPORT_CREATE_PIN(PORTE, 1)
#define MOTOR2_B IOPORT_CREATE_PIN(PORTA, 5)
#endif /*MOTOR_2_DIR_A*/

#ifdef MOTOR_2_DIR_B
#define MOTOR2_B IOPORT_CREATE_PIN(PORTE, 1)
#define MOTOR2_A IOPORT_CREATE_PIN(PORTA, 5)
#endif /*MOTOR_2_DIR_B*/

#ifdef MOTOR_3_DIR_A
#define MOTOR3_A IOPORT_CREATE_PIN(PORTE, 1)
#define MOTOR3_B IOPORT_CREATE_PIN(PORTA, 7)
#endif /*MOTOR_3_DIR_A*/

#ifdef MOTOR_3_DIR_B
#define MOTOR3_B IOPORT_CREATE_PIN(PORTE, 1)
#define MOTOR3_A IOPORT_CREATE_PIN(PORTA, 7)
#endif /*MOTOR_3_DIR_B*/

#ifdef MOTOR_4_DIR_A
#define MOTOR4_A IOPORT_CREATE_PIN(PORTE, 0)
#define MOTOR4_B IOPORT_CREATE_PIN(PORTA, 4)
#endif /*MOTOR_4_DIR_A*/

#ifdef MOTOR_4_DIR_B
#define MOTOR4_B IOPORT_CREATE_PIN(PORTE, 0)
#define MOTOR4_A IOPORT_CREATE_PIN(PORTA, 4)
#endif /*MOTOR_4_DIR_B*/

void motors_init(void);
void motor1_vel(int vel);
void motor2_vel(int vel);
void motor3_vel(int vel);
void motor4_vel(int vel);

#endif /* MOTORS_H_ */