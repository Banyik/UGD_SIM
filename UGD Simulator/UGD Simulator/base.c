#include "base.h"

void errlog(char *message) {
	printf("%s\n", message);
	exit(1);
}

void log(char *message) {
	printf("%s\n", message);
}