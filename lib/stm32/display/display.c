#include "display.h"

void Show(const char* text, uint16_t width) {
	char first_part[strlen(text)];
	strcpy(first_part, text);
    char* second_part = strtok(first_part, "\n");
	second_part = strtok(NULL, "\n");

	if(second_part[0] == 0) {
		if(strlen(first_part) > (width - 3)) {
			first_part[width - 3] = '\0';
			strncat(first_part, "...", 3);
			second_part = &(text[width - 3]);
		}
	}

	lcd_clear();
	lcd_put_cur(0,0);
	lcd_send_string(first_part);
	lcd_put_cur(1,0);
	lcd_send_string(second_part);
}

void Init() {
	lcd_init();
}

TDisplay* NewI2cDisplay() {
    return NewDisplay(&Show, 16, &Init);
}
