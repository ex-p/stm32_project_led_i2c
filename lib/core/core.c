#include "core.h"

void RunSomething(const TController* controller) {
    controller->Logger->LogInfo("Starting...");

    // We don't know which logger we call, cuz it doesn't matter
    // We can add other properties, like controller->Display
    // We can add interface Display->Show at controller
    // We can add stm32 display at lib/stm32/display.h 
    //    and when we create NewController we can provide NewStm32Display
    // And here we can call this func like controller->Display->Show("Some text")
    // Or we can add lib/whatever/display.h and set it in NewController without chaning this func

    controller->Logger->LogInfo("Ending...");
}
