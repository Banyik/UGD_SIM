#include <time.h>
#include "UserHandler.h"


#define TICK 1

static unsigned long ticks = 0;
void start_tick();
void tick();
