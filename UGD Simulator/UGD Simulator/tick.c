#include <stdio.h>
#include "tick.h"

void tick() {
	while (1)
	{
        clock_t last_time = clock();

        while (1) {
            clock_t current_time = clock();
            double elapsed_time = (double)(current_time - last_time) * 1000 / CLOCKS_PER_SEC;

            if (elapsed_time >= TICK) {
                printf("%d\r", ticks);
                ticks++;
                last_time = current_time;
            }
        }
	}
}