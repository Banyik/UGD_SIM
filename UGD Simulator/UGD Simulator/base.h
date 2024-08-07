#pragma once
#include "DataStructures.h"
#include <stdio.h>
#include <stdlib.h>

typedef enum {
	INT,
	FLOAT
} type;



void add_to_string_array(char* str);
void free_to_string(char* str);

void errlog(char *message);

void log_a(char *message, char** args);
void log(char* message);

void logn_a(char* message, char** args);
void logn(char* message);
void logr_a(char* message, char** args);

char* to_string(void* num, type t);