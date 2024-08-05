#include "base.h"
#include <stdlib.h>
#define arrSize(x) (int)(sizeof(x) / sizeof((x)[0]))

void* new_array(void* type, unsigned int size) {
	type = malloc(size * sizeof(type));
	return type;
}

void errlog(char *message) {
	printf("%s\n", message);
	exit(1);
}

void log_a(char *message, char **args) {
	printf("%s", message);
	for (size_t i = 0; i < arrSize(args); i++)
	{
		printf("%s", args[i]);
	}
}

void log(char* message) {
	printf("%s", message);
}

void logn_a(char* message, char **args) {
	printf("%s", message);

	for (size_t i = 0; i < arrSize(args); i++)
	{
		printf("%s", args[i]);
	}
	printf("\n");
}

void logn(char* message) {
	printf("%s\n", message);
}

char* to_string(int num) {
	char *str = malloc(10);
	snprintf(str, sizeof(str), "%d", num);
	return str;
}