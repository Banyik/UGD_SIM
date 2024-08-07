#include "base.h"
#include <stdlib.h>
#include <stdio.h>

char** to_string_arr = NULL;

void add_to_string_array(char* str) {
	if (to_string_arr == NULL) {
		to_string_arr = malloc(20 * sizeof(char*));
		for (size_t i = 0; i < 20; i++) {
			to_string_arr[i] = NULL;
		}
		to_string_arr[0] = str;
	}
	else {
		for (size_t i = 0; i < 20; i++)
		{
			if (to_string_arr[i] == NULL) {
				to_string_arr[i] = str;
				break;
			}
		}
	}
}

void free_to_string(char* str) {
	for (size_t i = 0; i < 20; i++)
	{
		if (to_string_arr[i] == str) {
			free(to_string_arr[i]);
			break;
		}
	}
}

int arr_size(void** arr) {
	int count = 0;
	while (arr[count] != NULL) {
		count++;
	}
	return count;
}

void errlog(char *message) {
	printf("%s\n", message);
	exit(1);
}

void log_a(char *message, char **args) {
	printf("%s", message);
	for (size_t i = 0; i < arr_size(args); i++)
	{
		printf("%s", args[i]);
		free_to_string(args[i]);
	}
}

void log(char* message) {
	printf("%s", message);
}

void logn_a(char* message, char **args) {
	printf("%s", message);
	for (size_t i = 0; i < arr_size(args); i++)
	{
		printf("%s", args[i]);
		free_to_string(args[i]);
	}
	printf("\n");
}

void logn(char* message) {
	printf("%s\n", message);
}

char* to_string(void* num, type t) {
	char* str = malloc(12);
	if (t == INT) {
		snprintf(str, 12, "%d", *(int*)num);
	}
	else {
		float f = *(float*)num;
		snprintf(str, 12, "%.6f", f);
	}
	add_to_string_array(str);
	return str;
}