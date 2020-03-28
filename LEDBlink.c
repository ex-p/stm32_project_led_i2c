#include <stm32f10x_gpio.h>
#include <stm32f10x_rcc.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <memory.h>
#include "stm32f10x_i2c.h"
#include "LiquidCrystal_I2C.h"
#include "delay.h"
#include "I2C.h"

char buf[256];

struct node
{
	struct node* left;
	struct node* right;
	void* first_string;
	void* second_string;
	
};

void init_node(struct node* node)
{
	node->left = NULL;
	node->right = NULL;
	node->first_string = NULL;
	node->second_string = NULL;
}

char * doitoa(int value)
{
	return itoa(value, buf, 10);
}

void Delay1()
{
	int i;
	for (i = 0; i < 1000000; i++)
		asm("nop");
}


int main()
{
	struct node main_screen;
	init_node(&main_screen);
	main_screen.first_string = "This is the main";
	main_screen.second_string = "screen";
	
	struct node temperature_screen;
	init_node(&temperature_screen);
	temperature_screen.first_string = "Temperature is:";
	temperature_screen.second_string = "15 degrees";
	
	LCDI2C_init(0x27, 16, 2);
	for (int i = 0; i < 3; ++i)
	{
		LCDI2C_backlight();
		Delay(250);
		LCDI2C_noBacklight();
		Delay(250);
	}
	LCDI2C_backlight();
	LCDI2C_clear();
	LCDI2C_setCursor(0, 0);
	LCDI2C_write_String("Hello World!");
	
	Delay(5000);
	
	LCDI2C_setCursor(0, 0);
	LCDI2C_write_String(main_screen.first_string);
	LCDI2C_setCursor(0,1);
	LCDI2C_write_String(main_screen.second_string);
	
	
	
	GPIO_InitTypeDef GPIO_InitStructure;
  
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; // Should be PC9
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0; //Button is connected to PA0
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; // No pullup
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	if (!GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0))
	{
		for (;;)
		{
			GPIO_WriteBit(GPIOC, GPIO_Pin_9, Bit_SET);
			Delay1();
			GPIO_WriteBit(GPIOC, GPIO_Pin_9, Bit_RESET);
			Delay1();
		}
	}	
}
