#pragma once
#include<stdio.h>

void* new_array(void* type, unsigned int size);

void errlog(char *message);

void log_a(char *message, char** args);
void log(char* message);

void logn_a(char* message, char** args);
void logn(char* message);

char* to_string(int num);