/*
 * leds.h
 *
 * DeepSea Developments
 *
 * Developed for the OctopusBot BTonly version. Open Source
 *
 * Created: 25/07/2013 11:34:40 p.m.
 *  Author: Nick
 */ 


#ifndef LEDS_H_
#define LEDS_H_

#define LED1 IOPORT_CREATE_PIN(PORTC, 4)
#define LED2 IOPORT_CREATE_PIN(PORTC, 5)
#define LED6 IOPORT_CREATE_PIN(PORTC, 6)
#define LED3 IOPORT_CREATE_PIN(PORTC, 7)
#define LED4 IOPORT_CREATE_PIN(PORTR, 1)
#define LED5 IOPORT_CREATE_PIN(PORTR, 0)

#define ANIMATION_MAX 100
enum{
	OFF,
	ON,
	TOGGLE
};


void leds_init(void);
void led1(int state);
void led2(int state);
void led3(int state);
void led4(int state);
void led5(int state);
void led6(int state);
void leds_state(int leds);
void animation();


#endif /* LEDS_H_ */