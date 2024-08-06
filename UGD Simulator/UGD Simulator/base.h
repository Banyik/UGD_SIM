#pragma once
#include<stdio.h>
#include <stdlib.h>

void new_array(void** arr, size_t typeSize, unsigned int size);

void errlog(char *message);

void log_a(char *message, char** args);
void log(char* message);

void logn_a(char* message, char** args);
void logn(char* message);

char* to_string(int num);