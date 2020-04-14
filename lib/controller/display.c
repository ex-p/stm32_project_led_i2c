#include "display.h"

#include <stdlib.h>

TDisplay* NewDisplay(FShow* show, uint16_t width, FInit* init) {
	TDisplay* display = (TDisplay*)malloc(sizeof(TDisplay));
	display->Show = show;
	display->Width = width;
	display->Init = init;
	return display;
}
