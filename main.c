#include "lib/controller/controller.h"
#include "lib/core/core.h"
#include "lib/logger/stdlogger.h"

#include <stdlib.h> 

int main() {
    TLogger* logger = NewStdLogger();
    TController* controller = NewController(logger);

    RunSomething(controller);

    // don't forget to free
    free(logger);
    free(controller);

    return 0;
}
