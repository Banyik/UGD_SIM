#include <stdio.h>
#include "tick.h"
#include "base.h"

void tick() {
    clock_t last_time = clock();
    create_user_properties();

    while (1) {
        clock_t current_time = clock();
        double elapsed_time = (double)(current_time - last_time) * 1000 / CLOCKS_PER_SEC;

        if (elapsed_time >= TICK) {
            update_users();
            logn_a("Every user has been updated at tick: ", (char* []) { to_string(ticks), NULL });
            ticks++;
            last_time = current_time;
        }
    }
    clean_users();
}