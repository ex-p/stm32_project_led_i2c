#ifndef LIB_CONTROLLER_DISPLAY_H_
#define LIB_CONTROLLER_DISPLAY_H_

#include <stdint.h>

typedef void FShow(const char* text, uint16_t width);
typedef void FInit(void);

typedef struct {
	FShow* Show;
	uint16_t Width;
	FInit* Init;
} TDisplay;

TDisplay* NewDisplay(FShow* show, uint16_t width, FInit* init);

#endif // LIB_CONTROLLER_DISPLAY_H_
