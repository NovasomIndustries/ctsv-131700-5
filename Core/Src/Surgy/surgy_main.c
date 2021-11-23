/*
 * surgy_main.c
 *
 *  Created on: Oct 25, 2021
 *      Author: fil
 */
#include "main.h"
#include "surgy_main.h"
#include "Drivers/fonts.h"
#include "Drivers/st7735.h"
#include "Drivers/Lcd.h"
SystemFlagsDef	SystemFlags;

void on_callback(void)
{
	if ( (SystemFlags.surgy_flags & POWEWRDOWN_FLAG ) == POWEWRDOWN_FLAG)
		return;
	if ( SystemFlags.button_on_debounce == 0 )
	{
		SystemFlags.buttons_flags |= (ON_PRESSED_FLAG | BUTTON_PRESSED_FLAG);
		SystemFlags.button_on_debounce = 3;
	}
}

void plus_callback(void)
{
	if (( SystemFlags.surgy_flags & ( COUNTER_ACTIVE_FLAG ) ) == COUNTER_ACTIVE_FLAG)
		return;
	if ( (SystemFlags.surgy_flags & BUTTONS_ENABLE_FLAG ) == 0)
		return;
	if ( SystemFlags.button_plus_debounce == 0 )
	{
		SystemFlags.buttons_flags |= (PLUS_PRESSED_FLAG | BUTTON_PRESSED_FLAG);
		SystemFlags.button_plus_debounce = 3;
	}
}

void minus_callback(void)
{
	if (( SystemFlags.surgy_flags & ( COUNTER_ACTIVE_FLAG ) ) == COUNTER_ACTIVE_FLAG)
		return;
	if ( (SystemFlags.surgy_flags & BUTTONS_ENABLE_FLAG ) == 0)
		return;
	if ( SystemFlags.button_minus_debounce == 0 )
	{
		SystemFlags.buttons_flags |= (MINUS_PRESSED_FLAG | BUTTON_PRESSED_FLAG);
		SystemFlags.button_minus_debounce = 3;
	}
}

void tim100msec_callback(void)
{
	SystemFlags.surgy_flags |= TICK_FLAG;
	if ( SystemFlags.button_on_debounce != 0 )
		SystemFlags.button_on_debounce--;
	if ( SystemFlags.button_plus_debounce != 0 )
		SystemFlags.button_plus_debounce--;
	if ( SystemFlags.button_minus_debounce != 0 )
		SystemFlags.button_minus_debounce--;

	SystemFlags.tick_counter++;

	if ( SystemFlags.tick_counter > 9 )
	{
		SystemFlags.surgy_flags |= SEC1_FLAG;
		SystemFlags.tick_counter = 0;
	}
}

uint16_t	analog_buffer[16];

void adc_dma_callback(void)
{
}


void SurgyPWM_Callback(void)
{
	if ( (SystemFlags.motor_flags & MOTOR_ON_FLAG ) == MOTOR_ON_FLAG)
	{
		if ( SystemFlags.motor_value <= 10000 )
		{
			SystemFlags.motor_value += MOTOR_ACCELERATION_K;
			MOTOR_TIMER.Instance->CCR1 = SystemFlags.motor_value;
		}
	}
}

static void SurgyStartPWM(void)
{
	SystemFlags.motor_flags |= MOTOR_ON_FLAG;
	SystemFlags.motor_value = 0;
	MOTOR_TIMER.Instance->CCR1 = SystemFlags.motor_value;
}

static void SurgyStopPWM(void)
{
	SystemFlags.motor_value = 0;
	MOTOR_TIMER.Instance->CCR1 = SystemFlags.motor_value;
	SystemFlags.motor_flags &= ~MOTOR_ON_FLAG;
}

void SurgyInit(void)
{
	LcdInit();
	HAL_TIM_Base_Start_IT(&TICK_TIMER);
	SystemFlags.splash_counter = SPLASH_COUNTER;
	SystemFlags.battery_counter = BATTERY_COUNTER;
	SystemFlags.work_counter = 30;
	SystemFlags.surgy_flags = 0;
	SystemFlags.motor_value = 0;
	SystemFlags.powerdown_counter = POWERDOWN_COUNTER;
	ST7735_WriteString(SPLASH_POSITIONX,SPLASH_POSITIONY,"Surgy",USED_FONT,ST7735_CYAN,ST7735_BLACK);
	HAL_ADC_Start_DMA(&ADC_CHANNEL, (uint32_t *)analog_buffer, 4);
	HAL_TIM_Base_Start(&ADC_TIMER);
	SystemFlags.motor_value = 0;
	HAL_TIM_PWM_Start_IT(&MOTOR_TIMER, TIM_CHANNEL_1);
	MOTOR_TIMER.Instance->CCR1 = SystemFlags.motor_value;
}

void SurgyUpdateCounter(uint16_t color)
{
char	line[8];

	sprintf(line,"%d  ",SystemFlags.work_counter);
	ST7735_WriteString(COUNTER_POSITIONX,COUNTER_POSITIONY,line,USED_FONT,color,ST7735_BLACK);
	SystemFlags.powerdown_counter = POWERDOWN_COUNTER;
	SystemFlags.surgy_flags &= ~POWEWRDOWN_FLAG;
}

static uint8_t	cleared = 0;
static void SurgyManageButtons(void)
{
	if ( (SystemFlags.surgy_flags & POWEWRDOWN_FLAG ) == POWEWRDOWN_FLAG)
	{
		if ((( SystemFlags.buttons_flags & ( PLUS_PRESSED_FLAG ) ) == PLUS_PRESSED_FLAG) || (( SystemFlags.buttons_flags & ( MINUS_PRESSED_FLAG  ) ) == MINUS_PRESSED_FLAG))
		{
			LcdSetBrightness(FULL_BRIGHTNESS);
			SystemFlags.powerdown_counter |= POWERDOWN_COUNTER;
			SystemFlags.buttons_flags = 0;
			SystemFlags.surgy_flags &= ~POWEWRDOWN_FLAG;
			return;
		}
	}

	if (( SystemFlags.buttons_flags & ( PLUS_PRESSED_FLAG ) ) == PLUS_PRESSED_FLAG)
	{
		if ( SystemFlags.work_counter < 180 )
		{
			SystemFlags.work_counter += 10;
			SurgyUpdateCounter(IDLE_COLOR);
			SystemFlags.buttons_flags &= ~PLUS_PRESSED_FLAG;
		}
	}
	if (( SystemFlags.buttons_flags & ( MINUS_PRESSED_FLAG  ) ) == MINUS_PRESSED_FLAG)
	{
		if ( SystemFlags.work_counter > 30 )
		{
			SystemFlags.work_counter -= 10;
			SurgyUpdateCounter(IDLE_COLOR);
			SystemFlags.buttons_flags &= ~MINUS_PRESSED_FLAG;
		}
	}
	if (( SystemFlags.buttons_flags & ( ON_PRESSED_FLAG ) ) == ON_PRESSED_FLAG)
	{
		if ( cleared == 0 )
			ST7735_WriteString(SPLASH_POSITIONX,SPLASH_POSITIONY,"Surgy",USED_FONT,ST7735_BLACK,ST7735_BLACK);
		cleared++;

		if (( SystemFlags.surgy_flags & ( COUNTER_ACTIVE_FLAG ) ) == COUNTER_ACTIVE_FLAG)
		{
			if (( SystemFlags.surgy_flags & ( COUNTER_PAUSED_FLAG ) ) == 0)
			{
				SystemFlags.surgy_flags |= COUNTER_PAUSED_FLAG;
				SurgyStopPWM();
			}
			else
			{
				SystemFlags.surgy_flags &= ~COUNTER_PAUSED_FLAG;
				SurgyStartPWM();
			}
		}
		else
		{
			SystemFlags.tick_counter = 0;
			SystemFlags.surgy_flags |= COUNTER_ACTIVE_FLAG;
			SystemFlags.stored_work_counter = SystemFlags.work_counter;
			SystemFlags.surgy_flags &= ~SEC1_FLAG ;
			SurgyUpdateCounter(MORE30_COLOR);
			SurgyStartPWM();
		}
		SystemFlags.buttons_flags &= ~ON_PRESSED_FLAG;
	}
}

static void SurgyManageCounter(void)
{
	if (( SystemFlags.surgy_flags & ( COUNTER_PAUSED_FLAG ) ) == 0)
	{
		SystemFlags.work_counter--;
		if ( SystemFlags.work_counter == 0 )
		{
			SystemFlags.surgy_flags &= ~(COUNTER_ACTIVE_FLAG | COUNTER_PAUSED_FLAG);
			SystemFlags.surgy_flags |= COUNTER_EXPIRED_FLAG;
			cleared = 0;
		}
		else
		{
			if ( SystemFlags.work_counter < 10 )
				SurgyUpdateCounter(LESS10_COLOR);
			else if ( SystemFlags.work_counter < 30 )
				SurgyUpdateCounter(MORE10_COLOR);
			else
				SurgyUpdateCounter(MORE30_COLOR);
		}
	}
}

void	SurgyPowerOFF(void)
{
#ifdef	ROM_VERSION
	  __disable_irq();
	  HAL_Delay(50);
#endif
	  HAL_GPIO_WritePin(POWER_ON_GPIO_Port, POWER_ON_Pin, GPIO_PIN_RESET);
#ifdef	ROM_VERSION
	  while(1);
#endif
}

int		uu;
char	line[8];

void SurgyMainLoop(void)
{
	if ( (SystemFlags.surgy_flags & TICK_FLAG ) == TICK_FLAG)
	{
		if ( SystemFlags.splash_counter != 0 )
		{
			SystemFlags.splash_counter--;
			if ( SystemFlags.splash_counter == 0 )
			{
				ST7735_WriteString(SPLASH_POSITIONX,SPLASH_POSITIONY,"Surgy",USED_FONT,ST7735_BLACK,ST7735_BLACK);
				ST7735_WriteString(BATTERY_POSITIONX,BATTERY_POSITIONY,line,Font_11x18,ST7735_BLACK,ST7735_BLACK);
				SurgyUpdateCounter(IDLE_COLOR);
				SystemFlags.surgy_flags |= BUTTONS_ENABLE_FLAG;

			}
			if ( SystemFlags.battery_counter != 0 )
			{
				SystemFlags.battery_counter --;
				if ( SystemFlags.battery_counter == 0 )
				{
					SystemFlags.surgy_flags |= BATTERY_FLAG;
				}
			}
		}
		if ( SystemFlags.powerdown_counter != 0 )
		{
			SystemFlags.powerdown_counter--;
		}
		else
		{
			LcdSetBrightness(ZERO_BRIGHTNESS);
			SystemFlags.surgy_flags |= POWEWRDOWN_FLAG;
			SystemFlags.surgy_flags |= BUTTONS_ENABLE_FLAG;
			SurgyPowerOFF();
		}
		SystemFlags.surgy_flags &= ~TICK_FLAG;
	}

	if (( SystemFlags.surgy_flags & BATTERY_FLAG) == BATTERY_FLAG)
	{
		SystemFlags.battery_value  = (float )analog_buffer[0]+(float )analog_buffer[2];
		uu = (int )((SystemFlags.battery_value / 1255.0F)*1000.0F);
		sprintf(line,"%d mV",uu);
		ST7735_WriteString(BATTERY_POSITIONX,BATTERY_POSITIONY,line,Font_11x18,BATTERY_COLOR,ST7735_BLACK);
		SystemFlags.surgy_flags &= ~BATTERY_FLAG;
	}

	if (( SystemFlags.surgy_flags & COUNTER_ACTIVE_FLAG) == COUNTER_ACTIVE_FLAG)
	{
		if (( SystemFlags.surgy_flags & SEC1_FLAG ) == SEC1_FLAG)
		{
			SurgyManageCounter();
			SystemFlags.surgy_flags &= ~SEC1_FLAG ;
		}
	}
	if ( (SystemFlags.surgy_flags & COUNTER_EXPIRED_FLAG ) == COUNTER_EXPIRED_FLAG)
	{
		SystemFlags.work_counter = SystemFlags.stored_work_counter;
		SystemFlags.surgy_flags &= ~COUNTER_EXPIRED_FLAG;
		SurgyUpdateCounter(IDLE_COLOR);
		SurgyStopPWM();
	}
	if (( SystemFlags.buttons_flags & BUTTON_PRESSED_FLAG ) == BUTTON_PRESSED_FLAG)
	{
		SurgyManageButtons();
		SystemFlags.buttons_flags &= ~BUTTON_PRESSED_FLAG;
	}
}
