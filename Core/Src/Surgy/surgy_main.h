/*
 * surgy_main.h
 *
 *  Created on: Oct 25, 2021
 *      Author: fil
 */

#ifndef SRC_SURGY_SURGY_MAIN_H_
#define SRC_SURGY_SURGY_MAIN_H_


#define 	TRIES_BUFFERS 		__attribute__((section(".tries_buffers")))

typedef struct _SystemFlagsDef
{
	uint8_t		surgy_flags;
	uint16_t 	current_brightness;
	uint8_t 	battery_counter;
	uint8_t 	tick_counter;
	uint8_t 	work_counter;
	uint8_t 	initial_blank_counter;
	uint8_t 	stored_work_counter;
	uint8_t 	splash_counter;
	uint16_t 	powerdown_counter;
	uint16_t 	powerdown_loop_counter;
	uint16_t 	poweroff_counter;
	uint8_t 	button_plus_debounce;
	uint8_t 	button_minus_debounce;
	uint8_t 	button_on_debounce;
	uint8_t 	button_on_work_counter;
	uint8_t		buttons_on_work_flags;
	uint8_t		buttons_flags;
	float	 	battery_value;
	uint16_t 	motor_value;
	uint8_t		motor_flags;
	uint8_t		pwdown_posx , pwdown_posy;
	uint16_t 	digit_color;
}SystemFlagsDef;

/* surgy_flags definitions */
#define	TICK_FLAG				0x80
#define	SEC1_FLAG				0x40
#define	COUNTER_ACTIVE_FLAG		0x20
#define	COUNTER_PAUSED_FLAG		0x10
#define	COUNTER_EXPIRED_FLAG	0x08
#define	POWEWRDOWN_FLAG			0x02

/* buttons_flags definitions */
#define	BUTTON_PRESSED_FLAG		0x80
#define	PLUS_PRESSED_FLAG		0x40
#define	MINUS_PRESSED_FLAG		0x20
#define	ON_PRESSED_FLAG			0x10

/* motor_flags */
#define	MOTOR_ON_FLAG			0x80

/* buttons_on_work_flags */
#define	SET_PAUSE_FLAG		0x80
#define	CLEAR_PAUSE_FLAG	0x01

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
#define	BATTERY_POSITIONX	0
#define	BATTERY_POSITIONY	60
#define	COUNTER_POSITIONX	50
#define	COUNTER_POSITIONY	30
#define	REMAINING_POSITIONX	120
#define	REMAINING_POSITIONY	60

/* those are in 100 mSec unit */
#define	INI_BLANK_COUNTER	20
#define	SPLASH_COUNTER		50
#define	BATTERY_COUNTER		20
#define	POWERDOWN_COUNTER	300
#define	POWEROFF_COUNTER	1200
#define	WORK_COUNTER		30
#define	DBG_WORK_COUNTER	10
#define	MAX_WORK_COUNTER	180

#define	MOTOR_ACCELERATION_K	50
#define	IDLE_COLOR				ST7735_BLUE
#define	MORE30_COLOR			ST7735_WHITE
#define	MORE10_COLOR			ST7735_YELLOW
#define	LESS10_COLOR			ST7735_RED
#define	BATTERY_COLOR			ST7735_GREEN
#define	PWDOWN_COLOR			ST7735_GREY
#define	REMAINING_COLOR			ST7735_YELLOW
#define	CNTROFF_COLOR			ST7735_BLACK

#define FLASH_USER_END_ADDR     (FLASH_BASE + FLASH_SIZE)   /* End @ of user Flash area */
#define	WRITEABLE_ADDRESS		(FLASH_USER_END_ADDR - FLASH_PAGE_SIZE)
#define	MAX_NUMBER_OF_OPS		16

extern	void tim100msec_callback(void);
extern	void SurgyMainLoop(void);
extern	void SurgyInit(void);
extern	void adc_dma_callback(void);
extern	void on_callback(void);
extern	void plus_callback(void);
extern	void minus_callback(void);
extern	void SurgyPWM_Callback(void);

#endif /* SRC_SURGY_SURGY_MAIN_H_ */
