#include <stdio.h>
#include "tick.h"
#include "base.h"

clock_t last_time;
clock_t current_time;
double elapsed_time;

void start_tick() {
    last_time = clock();
    create_content_properties();
    create_user_properties();

    tick();

    clean_users();
}

void tick() {
    while (1) {
        current_time = clock();
        elapsed_time = (double)(current_time - last_time) * 10000 / CLOCKS_PER_SEC;

        if (elapsed_time >= TICK) {
            update_users(ticks);
            //TODO: Updatehandler: Another file which calls other functions at once.
            logn_a("Every user has been updated at tick: ", (char* []) { to_string(&ticks, INT), NULL });
            ticks++;
            last_time = current_time;
        }
    }
}