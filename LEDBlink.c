#include <stm32f10x_gpio.h>
#include <stm32f10x_rcc.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include "stm32f10x_i2c.h"
#include "LiquidCrystal_I2C.h"
#include "delay.h"
#include "I2C.h"

char buf[32];

struct Node
{
	// struct Node* left; // to be used later in the binary tree
	// struct Node* right;//
    char* String[20];
};

void InitNode(struct Node* node)
{
	// Node->left = NULL;
	// Node->right = NULL;
    for(int i = 0 ; i < sizeof(node->String) ; ++i)
	{
		node->String[i] = NULL;
	}
}

char* DoItoa(int value)
{
	for (int i = 0; i < strlen(buf); ++i)
	{
		buf[i] = 0;
	}
	return itoa(value, buf, 10);
}

int main()
{
	struct Node main_screen;
	InitNode(&main_screen);
	
	main_screen.String[0] = (char*) "Temperature is:";
	main_screen.String[1] = DoItoa(50);
	main_screen.String[2] = (char*) " degrees";
	for (int i = 0; i < sizeof (main_screen.String); ++i)
	{
		if (main_screen.String[i] == NULL)
		{
			printf("\n");  // Only if the terminal is used
			break;
		}
		printf("%s", (char *) main_screen.String[i]);
	}
//	LCDI2C_init(0x27, 16, 2);
//	for (int i = 0; i < 3; ++i)
//	{
//		LCDI2C_backlight();
//		Delay(250);
//		LCDI2C_noBacklight();
//		Delay(250);
//	}
//	LCDI2C_backlight();
//	LCDI2C_clear();
//	LCDI2C_setCursor(0, 0);
//	LCDI2C_write_String("Hello World!");
//	
//	Delay(5000);
//	
////	LCDI2C_setCursor(0, 0);
////	LCDI2C_write_String(main_screen.first_string);
////	LCDI2C_setCursor(0,1);
////	LCDI2C_write_String(main_screen.second_string);
//	
//	
//	
//	GPIO_InitTypeDef GPIO_InitStructure;
//  
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
//
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; // Should be PC9
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_Init(GPIOC, &GPIO_InitStructure);
//	
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0; //Button is connected to PA0
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; // No pullup
//	GPIO_Init(GPIOA, &GPIO_InitStructure);
//	
//	if (!GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0))
//	{
//		for (;;)
//		{
//			GPIO_WriteBit(GPIOC, GPIO_Pin_9, Bit_SET);
//			Delay(10000);
//			GPIO_WriteBit(GPIOC, GPIO_Pin_9, Bit_RESET);
//			Delay(10000);
//		}
//	}	
}
