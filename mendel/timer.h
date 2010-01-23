#ifndef	_TIMER_H
#define	_TIMER_H

#include	<stdint.h>
#include	<avr/io.h>

// time-related constants
#define	US	* (F_CPU / 1000000)
#define	MS	* (F_CPU / 1000)

#define	DEFAULT_TICK	(100 US)
#define	WAITING_DELAY	(10 MS)

void setupTimerInterrupt(void);
uint8_t getTimerResolution(const uint32_t delay);
void setTimerResolution(uint8_t r);
uint16_t getTimerCeiling(const uint32_t delay);

void setTimer(uint32_t delay);

void delay(uint32_t delay);

void delay_ms(uint32_t delay);

#define	delay_us(d) delayMicrosecondsInterruptible(d)
void delayMicrosecondsInterruptible(unsigned int us);

#define enableTimerInterrupt()	do { TIMSK1 |= (1<<OCIE1A); } while (0)
#define disableTimerInterrupt() do { TIMSK1 &= ~(1<<OCIE1A); } while (0)

#define setTimerCeiling(c)		OCR1A = c

#endif	/* _TIMER_H */
