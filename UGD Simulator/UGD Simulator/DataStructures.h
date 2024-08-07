#pragma once
#include<stdio.h>
#include <stdlib.h>

typedef struct Array{
	void** data;
	size_t size;
	size_t length;
	void (*Add)(struct Array*, void*, int);
	void (*Remove)(struct Array*, int);
	void** (*Get)(struct Array*, int);
	void (*Free)(struct Array*);
} Array;

void new_array(Array* array, size_t typeSize, unsigned int size);
void add_to_array(Array* array, void* element, int index);
void remove_from_array(Array* array, int index);
void** get_data(Array* array, int index);
void free_array(Array* array);