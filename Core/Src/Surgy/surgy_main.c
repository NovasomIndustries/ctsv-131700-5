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

void SurgyUpdateCounter(uint16_t color);

uint32_t Page = 0, NbOfPages = 1;
uint32_t Address = 0, PageError = 0;
uint32_t operations;
TRIES_BUFFERS	__attribute__ ((aligned (16)))	uint32_t flash_operations = 0xffffffff;

static FLASH_EraseInitTypeDef EraseInitStruct = {0};

static uint32_t GetPage(uint32_t Addr)
{
  return (Addr - FLASH_BASE) / FLASH_PAGE_SIZE;;
}

uint32_t flash_number_of_ops;

uint32_t GetTries(void)
{
uint32_t number_of_ops;
uint32_t *addr;

	flash_number_of_ops = (uint32_t )&flash_operations;

	addr = (uint32_t * )WRITEABLE_ADDRESS;
	number_of_ops = *addr;
/*
	if ( number_of_ops > 1 )
		number_of_ops = 1;
*/
	if ( number_of_ops > MAX_NUMBER_OF_OPS )
		number_of_ops = MAX_NUMBER_OF_OPS;
	return number_of_ops;
}

uint64_t number_of_ops64;

uint32_t WriteTries(uint32_t local_number_of_ops)
{
	number_of_ops64 = (uint64_t )local_number_of_ops;
	HAL_FLASH_Unlock();
	Page = GetPage(WRITEABLE_ADDRESS);
	EraseInitStruct.TypeErase   = FLASH_TYPEERASE_PAGES;
	EraseInitStruct.Page        = Page;
	EraseInitStruct.NbPages     = NbOfPages;
	if (HAL_FLASHEx_Erase(&EraseInitStruct, &PageError) != HAL_OK)
		return 1;
	Address = WRITEABLE_ADDRESS;
	if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, Address, number_of_ops64) == HAL_OK)
	{
		HAL_FLASH_Lock();
		return 0;
	}
	return 1;
}

void HAL_GPIO_EXTI_Falling_Callback(uint16_t GPIO_Pin)
{
	switch(GPIO_Pin)
	{
	case	ON_Pin :
		if ( (SystemFlags.surgy_flags & POWEWRDOWN_FLAG ) == POWEWRDOWN_FLAG)
			return;
		if ( SystemFlags.button_on_debounce == 0 )
		{
			SystemFlags.buttons_flags |= (ON_PRESSED_FLAG | BUTTON_PRESSED_FLAG);
			SystemFlags.button_on_debounce = 3;
		}
		break;
	case	SPEED_MINUS_Pin :
		if ( (SystemFlags.surgy_flags & POWEWRDOWN_FLAG ) == 0)
		{
			if (( SystemFlags.surgy_flags & ( COUNTER_ACTIVE_FLAG ) ) == COUNTER_ACTIVE_FLAG)
				return;
		}
		if ( SystemFlags.button_minus_debounce == 0 )
		{
			SystemFlags.buttons_flags |= (MINUS_PRESSED_FLAG | BUTTON_PRESSED_FLAG);
			SystemFlags.button_minus_debounce = 3;
		}
		break;
	case	SPEED_PLUS_Pin :
		if ( (SystemFlags.surgy_flags & POWEWRDOWN_FLAG ) == 0)
		{
			if (( SystemFlags.surgy_flags & ( COUNTER_ACTIVE_FLAG ) ) == COUNTER_ACTIVE_FLAG)
				return;
		}
		if ( SystemFlags.button_plus_debounce == 0 )
		{
			SystemFlags.buttons_flags |= (PLUS_PRESSED_FLAG | BUTTON_PRESSED_FLAG);
			SystemFlags.button_plus_debounce = 3;
		}
		break;
	}
}

void on_callback(void)
{
#ifdef	USE_NO_CALLBACK
	if ( (SystemFlags.surgy_flags & POWEWRDOWN_FLAG ) == POWEWRDOWN_FLAG)
		return;
	if ( SystemFlags.button_on_debounce == 0 )
	{
		SystemFlags.buttons_flags |= (ON_PRESSED_FLAG | BUTTON_PRESSED_FLAG);
		SystemFlags.button_on_debounce = 3;
	}
#endif
}

void plus_callback(void)
{
#ifdef	USE_NO_CALLBACK
	if (( SystemFlags.surgy_flags & ( COUNTER_ACTIVE_FLAG ) ) == COUNTER_ACTIVE_FLAG)
		return;
	if ( SystemFlags.button_plus_debounce == 0 )
	{
		SystemFlags.buttons_flags |= (PLUS_PRESSED_FLAG | BUTTON_PRESSED_FLAG);
		SystemFlags.button_plus_debounce = 3;
	}
#endif
}

void minus_callback(void)
{
#ifdef	USE_NO_CALLBACK
	if (( SystemFlags.surgy_flags & ( COUNTER_ACTIVE_FLAG ) ) == COUNTER_ACTIVE_FLAG)
		return;
	if ( SystemFlags.button_minus_debounce == 0 )
	{
		SystemFlags.buttons_flags |= (MINUS_PRESSED_FLAG | BUTTON_PRESSED_FLAG);
		SystemFlags.button_minus_debounce = 3;
	}
#endif
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
		HAL_NVIC_DisableIRQ(EXTI0_1_IRQn);
		HAL_NVIC_DisableIRQ(EXTI2_3_IRQn);
		HAL_NVIC_DisableIRQ(EXTI4_15_IRQn);
		SystemFlags.motor_flags |= MOTOR_ON_FLAG;
		SystemFlags.motor_value = 0;
		MOTOR_TIMER.Instance->CCR1 = SystemFlags.motor_value;
}

static void SurgyStopPWM(void)
{
	SystemFlags.motor_value = 0;
	MOTOR_TIMER.Instance->CCR1 = SystemFlags.motor_value;
	SystemFlags.motor_flags &= ~MOTOR_ON_FLAG;
	HAL_NVIC_EnableIRQ(EXTI0_1_IRQn);
	HAL_NVIC_EnableIRQ(EXTI2_3_IRQn);
	HAL_NVIC_EnableIRQ(EXTI4_15_IRQn);
	HAL_Delay(100);
	SystemFlags.buttons_flags = 0;
}

void SurgyInit(void)
{
	HAL_GPIO_WritePin(POWER_ON_GPIO_Port, POWER_ON_Pin, GPIO_PIN_SET);

	HAL_NVIC_DisableIRQ(EXTI0_1_IRQn);
	HAL_NVIC_DisableIRQ(EXTI2_3_IRQn);
	HAL_NVIC_DisableIRQ(EXTI4_15_IRQn);
	HAL_NVIC_SetPriority(EXTI0_1_IRQn, 0, 0);
	HAL_NVIC_SetPriority(EXTI2_3_IRQn, 0, 0);
	HAL_NVIC_SetPriority(EXTI4_15_IRQn, 0, 0);
	LcdInit();
	HAL_TIM_Base_Start_IT(&TICK_TIMER);
	SystemFlags.splash_counter = SPLASH_COUNTER;
	SystemFlags.battery_counter = BATTERY_COUNTER;
	SystemFlags.work_counter = WORK_COUNTER;
	SystemFlags.surgy_flags = 0;
	SystemFlags.motor_value = 0;
	SystemFlags.buttons_flags = 0;
	SystemFlags.initial_blank_counter = 0;
	SystemFlags.powerdown_counter = POWERDOWN_COUNTER;
	SystemFlags.poweroff_counter = POWEROFF_COUNTER;
	SystemFlags.digit_color = IDLE_COLOR;
	ST7735_WriteString(SPLASH_POSITIONX,SPLASH_POSITIONY,"Surgy",USED_FONT,ST7735_CYAN,ST7735_BLACK);
	HAL_ADC_Start_DMA(&ADC_CHANNEL, (uint32_t *)analog_buffer, 4);
	HAL_TIM_Base_Start(&ADC_TIMER);
	SystemFlags.motor_value = 0;
	HAL_TIM_PWM_Start_IT(&MOTOR_TIMER, TIM_CHANNEL_1);
	MOTOR_TIMER.Instance->CCR1 = SystemFlags.motor_value;
	operations = GetTries();
	Page = GetPage(WRITEABLE_ADDRESS);
}

static uint8_t	cleared = 0;
//#define	DEBUG_RUN	1

static void SurgyManageButtons(void)
{
char	line[8];

	if ( (SystemFlags.surgy_flags & POWEWRDOWN_FLAG ) == POWEWRDOWN_FLAG)
	{
		if ((( SystemFlags.buttons_flags & ( PLUS_PRESSED_FLAG ) ) == PLUS_PRESSED_FLAG) || (( SystemFlags.buttons_flags & ( MINUS_PRESSED_FLAG  ) ) == MINUS_PRESSED_FLAG))
		{
			sprintf(line,"%d  ",SystemFlags.work_counter);
			ST7735_WriteString(SystemFlags.pwdown_posx,SystemFlags.pwdown_posy,line,USED_FONT,ST7735_BLACK,ST7735_BLACK);
			SystemFlags.pwdown_posx = COUNTER_POSITIONX;
			SystemFlags.pwdown_posy = COUNTER_POSITIONY;
			ST7735_WriteString(SystemFlags.pwdown_posx,SystemFlags.pwdown_posy,line,USED_FONT,SystemFlags.digit_color,ST7735_BLACK);
			LcdSetBrightness(FULL_BRIGHTNESS);
			SystemFlags.powerdown_counter = POWERDOWN_COUNTER;
			SystemFlags.poweroff_counter = POWEROFF_COUNTER;
			SystemFlags.buttons_flags = 0;
			SystemFlags.surgy_flags &= ~POWEWRDOWN_FLAG;
			return;
		}
	}
	else
	{
		if (( SystemFlags.buttons_flags & ( PLUS_PRESSED_FLAG ) ) == PLUS_PRESSED_FLAG)
		{
			if ( SystemFlags.work_counter < MAX_WORK_COUNTER )
			{
				SystemFlags.work_counter += 10;
				SurgyUpdateCounter(IDLE_COLOR);
				SystemFlags.buttons_flags &= ~PLUS_PRESSED_FLAG;
			}
		}
		if (( SystemFlags.buttons_flags & ( MINUS_PRESSED_FLAG  ) ) == MINUS_PRESSED_FLAG)
		{
#ifdef	DEBUG_RUN
			if ( SystemFlags.work_counter > DBG_WORK_COUNTER )
#else
			if ( SystemFlags.work_counter > WORK_COUNTER )
#endif
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
			if (( SystemFlags.surgy_flags & COUNTER_ACTIVE_FLAG) == 0)
			{
				operations --;
				if ( operations != 0 )
				{
					WriteTries(operations);
					SystemFlags.tick_counter = 0;
					SystemFlags.surgy_flags |= COUNTER_ACTIVE_FLAG;
					SystemFlags.stored_work_counter = SystemFlags.work_counter;
					SystemFlags.surgy_flags &= ~SEC1_FLAG ;
					SurgyUpdateCounter(MORE30_COLOR);
					SurgyStartPWM();
				}
				else
				{
					SurgyUpdateCounter(LESS10_COLOR);
					HAL_Delay(500);
					SurgyUpdateCounter(CNTROFF_COLOR);
					HAL_Delay(500);
					SurgyUpdateCounter(LESS10_COLOR);
					HAL_Delay(500);
					SurgyUpdateCounter(CNTROFF_COLOR);
					HAL_Delay(500);
					SurgyUpdateCounter(LESS10_COLOR);
					HAL_Delay(500);
					SurgyUpdateCounter(CNTROFF_COLOR);
					HAL_Delay(500);
					SurgyUpdateCounter(MORE30_COLOR);
				}
			}
			SystemFlags.buttons_flags &= ~ON_PRESSED_FLAG;
		}
		SystemFlags.powerdown_counter = POWERDOWN_COUNTER;
		SystemFlags.poweroff_counter = POWEROFF_COUNTER;
	}
}

void SurgyUpdateCounter(uint16_t color)
{
char	line[8];
	sprintf(line,"%d  ",SystemFlags.work_counter);
	SystemFlags.digit_color = color;
	ST7735_WriteString(COUNTER_POSITIONX,COUNTER_POSITIONY,line,USED_FONT,SystemFlags.digit_color,ST7735_BLACK);
	SystemFlags.powerdown_counter = POWERDOWN_COUNTER;
	SystemFlags.poweroff_counter = POWEROFF_COUNTER;
	SystemFlags.surgy_flags &= ~POWEWRDOWN_FLAG;
}

void SurgyUpdateRemaining(void)
{
char	line[8];
uint16_t	color;

	if ( operations > 8 )
		color = ST7735_GREEN;
	else
	{
		if ( operations > 1 )
			color = ST7735_YELLOW;
		else
			color = ST7735_RED;
	}
	sprintf(line,"%d  ",(int )(operations-1));
	ST7735_WriteString(REMAINING_POSITIONX,REMAINING_POSITIONY,line,Font_11x18,color,ST7735_BLACK);
}

static void SurgyManageCounter(void)
{
	if (( SystemFlags.motor_flags & MOTOR_ON_FLAG  ) == MOTOR_ON_FLAG)
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


char	line[8];
void SurgyManageSplashBattery(void)
{
int		uu;
	if ( SystemFlags.splash_counter != 0 )
	{
		SystemFlags.splash_counter--;
		if ( SystemFlags.splash_counter == BATTERY_COUNTER )
		{
			SystemFlags.battery_value  = (float )analog_buffer[0]+(float )analog_buffer[2];
			uu = (int )((SystemFlags.battery_value / 1255.0F)*1000.0F);
			sprintf(line,"%d mV",uu);
			ST7735_WriteString(BATTERY_POSITIONX,BATTERY_POSITIONY,line,Font_11x18,BATTERY_COLOR,ST7735_BLACK);
		}

		if ( SystemFlags.splash_counter == 0 )
		{
			while ( HAL_GPIO_ReadPin(ON_GPIO_Port, ON_Pin) == 0 )
				HAL_Delay(20);

			ST7735_WriteString(SPLASH_POSITIONX,SPLASH_POSITIONY,"Surgy",USED_FONT,ST7735_BLACK,ST7735_BLACK);
			ST7735_WriteString(BATTERY_POSITIONX,BATTERY_POSITIONY,line,Font_11x18,ST7735_BLACK,ST7735_BLACK);
			SurgyUpdateCounter(IDLE_COLOR);
			SurgyUpdateRemaining();
			__HAL_GPIO_EXTI_CLEAR_FALLING_IT(SPEED_PLUS_Pin);
			__HAL_GPIO_EXTI_CLEAR_FALLING_IT(SPEED_MINUS_Pin);
			__HAL_GPIO_EXTI_CLEAR_FALLING_IT(ON_Pin);
			HAL_NVIC_EnableIRQ(EXTI0_1_IRQn);
			HAL_NVIC_EnableIRQ(EXTI2_3_IRQn);
			HAL_NVIC_EnableIRQ(EXTI4_15_IRQn);
		}
	}
}

void SurgyManagePowerDown(void)
{
char	line[8];
	if ( SystemFlags.powerdown_counter != 0 )
	{
		SystemFlags.powerdown_counter--;
		SystemFlags.pwdown_posx = COUNTER_POSITIONX;
		SystemFlags.pwdown_posy = COUNTER_POSITIONY;
	}
	else
	{
		SystemFlags.powerdown_loop_counter++;
		if ( SystemFlags.powerdown_loop_counter > 9 )
		{
			SystemFlags.powerdown_loop_counter = 0;
			sprintf(line,"%d  ",SystemFlags.work_counter);
			ST7735_WriteString(SystemFlags.pwdown_posx,SystemFlags.pwdown_posy,line,USED_FONT,ST7735_BLACK,ST7735_BLACK);
			LcdSetBrightness(LOW_BRIGHTNESS);
			SystemFlags.surgy_flags |= POWEWRDOWN_FLAG;
			SystemFlags.pwdown_posy += 7;
			if ( SystemFlags.pwdown_posy > 53)
			{
				SystemFlags.pwdown_posy = 0;
				SystemFlags.pwdown_posx += 9;
				if ( SystemFlags.pwdown_posx > 110 )
					SystemFlags.pwdown_posx = 0;
			}
			ST7735_WriteString(SystemFlags.pwdown_posx,SystemFlags.pwdown_posy,line,USED_FONT,PWDOWN_COLOR,ST7735_BLACK);
		}
	}
}

void SurgyManagePowerOff(void)
{
	if ( SystemFlags.poweroff_counter != 0 )
	{
		SystemFlags.poweroff_counter --;
	}
	else
	{
		HAL_Delay(50);
		__disable_irq();
		while(1)
		{
			HAL_GPIO_WritePin(POWER_ON_GPIO_Port, POWER_ON_Pin, GPIO_PIN_RESET);
		}
	}
}

void SurgyMainLoop(void)
{
	if ( (SystemFlags.surgy_flags & TICK_FLAG ) == TICK_FLAG)
	{
		SurgyManageSplashBattery();
		SurgyManagePowerDown();
		SurgyManagePowerOff();

		if (( SystemFlags.surgy_flags & COUNTER_ACTIVE_FLAG) == COUNTER_ACTIVE_FLAG)
		{
			if (( SystemFlags.surgy_flags & SEC1_FLAG ) == SEC1_FLAG)
			{
				SurgyManageCounter();
				SystemFlags.surgy_flags &= ~SEC1_FLAG ;
			}
			if ( HAL_GPIO_ReadPin(ON_GPIO_Port, ON_Pin) == 0 )
			{
				SystemFlags.button_on_work_counter	++;
				if (( SystemFlags.surgy_flags & ( COUNTER_PAUSED_FLAG ) ) == 0)
				{
					if ( SystemFlags.button_on_work_counter == 5 )
					{
						SystemFlags.buttons_on_work_flags |= SET_PAUSE_FLAG;
						SystemFlags.buttons_on_work_flags &= ~CLEAR_PAUSE_FLAG;
						SurgyStopPWM();
					}
				}
				else
				{
					if ( SystemFlags.button_on_work_counter == 3 )
					{
						SystemFlags.buttons_on_work_flags |= CLEAR_PAUSE_FLAG;
						SystemFlags.buttons_on_work_flags &= ~SET_PAUSE_FLAG;
						SurgyStartPWM();
					}
				}
			}
			else
			{
				SystemFlags.button_on_work_counter = 0;
				if (( SystemFlags.buttons_on_work_flags & SET_PAUSE_FLAG ) == SET_PAUSE_FLAG)
					SystemFlags.surgy_flags |= COUNTER_PAUSED_FLAG;
				if (( SystemFlags.buttons_on_work_flags & CLEAR_PAUSE_FLAG ) == CLEAR_PAUSE_FLAG)
					SystemFlags.surgy_flags &= ~COUNTER_PAUSED_FLAG;
				SystemFlags.buttons_on_work_flags = 0;
			}
		}
		if (( SystemFlags.buttons_flags & BUTTON_PRESSED_FLAG ) == BUTTON_PRESSED_FLAG)
		{
			SurgyManageButtons();
			SystemFlags.buttons_flags &= ~BUTTON_PRESSED_FLAG;
		}
		SystemFlags.surgy_flags &= ~TICK_FLAG;
	}

	if ( (SystemFlags.surgy_flags & COUNTER_EXPIRED_FLAG ) == COUNTER_EXPIRED_FLAG)
	{
		SystemFlags.work_counter = SystemFlags.stored_work_counter;
		SystemFlags.surgy_flags &= ~COUNTER_EXPIRED_FLAG;
		SurgyUpdateCounter(IDLE_COLOR);
		SurgyStopPWM();
		SurgyUpdateRemaining();
	}
}
