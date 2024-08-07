#include <time.h>
#include "UserHandler.h"


#define TICK 1

static short tickLoop = 1;

static unsigned long ticks = 0;
void start_tick();
void stop_tick();
void tick();
