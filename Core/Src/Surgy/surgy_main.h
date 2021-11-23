/*
 * surgy_main.h
 *
 *  Created on: Oct 25, 2021
 *      Author: fil
 */

#ifndef SRC_SURGY_SURGY_MAIN_H_
#define SRC_SURGY_SURGY_MAIN_H_

typedef struct _SystemFlagsDef
{
	uint8_t		surgy_flags;
	uint16_t 	current_brightness;
	uint8_t 	battery_counter;
	uint8_t 	tick_counter;
	uint8_t 	work_counter;
	uint8_t 	stored_work_counter;
	uint8_t 	splash_counter;
	uint16_t 	powerdown_counter;
	uint8_t 	button_plus_debounce;
	uint8_t 	button_minus_debounce;
	uint8_t 	button_on_debounce;
	uint8_t		buttons_flags;
	float	 	battery_value;
	uint16_t 	motor_value;
	uint8_t		motor_flags;
}SystemFlagsDef;

/* surgy_flags definitions */
#define	TICK_FLAG				0x80
#define	SEC1_FLAG				0x40
#define	COUNTER_ACTIVE_FLAG		0x20
#define	COUNTER_PAUSED_FLAG		0x10
#define	COUNTER_EXPIRED_FLAG	0x08
#define	BUTTONS_ENABLE_FLAG		0x04
#define	POWEWRDOWN_FLAG			0x02
#define	BATTERY_FLAG			0x01

/* buttons_flags definitions */
#define	BUTTON_PRESSED_FLAG		0x80
#define	PLUS_PRESSED_FLAG		0x40
#define	MINUS_PRESSED_FLAG		0x20
#define	ON_PRESSED_FLAG			0x10

/* motor_flags */
#define	MOTOR_ON_FLAG			0x80


extern	TIM_HandleTypeDef htim1;
extern	TIM_HandleTypeDef htim3;
extern	TIM_HandleTypeDef htim16;
extern	TIM_HandleTypeDef htim17;
extern	ADC_HandleTypeDef hadc1;

#define	MOTOR_TIMER			htim16
#define	ADC_TIMER			htim1
#define	BACKLIGHT_TIMER		htim3
#define	TICK_TIMER			htim17
#define	ADC_CHANNEL			hadc1

#define	USED_FONT			Font_16x26
//#define	USED_FONT			Font_11x18
#define	ADC_LEN				32
#define	SPLASH_POSITIONX	25
#define	SPLASH_POSITIONY	20
#define	BATTERY_POSITIONX	35
#define	BATTERY_POSITIONY	60
#define	COUNTER_POSITIONX	50
#define	COUNTER_POSITIONY	30

#define	SPLASH_COUNTER		50
#define	BATTERY_COUNTER		20
#define	POWERDOWN_COUNTER	300

#define	MOTOR_ACCELERATION_K	50
#define	IDLE_COLOR				ST7735_BLUE
#define	MORE30_COLOR			ST7735_WHITE
#define	MORE10_COLOR			ST7735_YELLOW
#define	LESS10_COLOR			ST7735_RED
#define	BATTERY_COLOR			ST7735_GREEN



extern	void tim100msec_callback(void);
extern	void SurgyMainLoop(void);
extern	void SurgyInit(void);
extern	void adc_dma_callback(void);
extern	void on_callback(void);
extern	void plus_callback(void);
extern	void minus_callback(void);
extern	void SurgyPWM_Callback(void);

#endif /* SRC_SURGY_SURGY_MAIN_H_ */
