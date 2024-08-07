#include <stdio.h>
#include <stdlib.h>

#include "CommandHandler.h"
#include "tick.h"
#include "base.h"

#ifdef _WIN32
#include <conio.h>
#else
#include <fcntl.h>
#include <termios.h>
#endif

void setup_io() {
    #ifdef _WIN32
    #else
        struct termios new_termios;
        tcgetattr(STDIN_FILENO, &new_termios);
        new_termios.c_lflag &= ~ICANON;
        new_termios.c_lflag &= ~ECHO;
        tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);

        int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
        fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);
    #endif
}

void check_input() {
    char ch;
#ifdef _WIN32
    if (_kbhit()) {
        ch = _getch();
#else
    if (read(STDIN_FILENO, &ch, 1) > 0) {
#endif
        switch (ch)
        {
        case 'l':
            enable_log();
            break;
        case 'q':
            if (is_log_enabled() == 0) {
                enable_log();
            }
            logn("Closing session...");
            stop_tick();
            break;
        default:
            break;
        }
    }
}