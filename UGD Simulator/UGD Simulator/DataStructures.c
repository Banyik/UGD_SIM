#include "base.h"
#include "DataStructures.h"
#include <stdlib.h>

void new_array(Array* array, size_t typeSize, unsigned int size) {

	array->Add = add_to_array;
	array->Remove = remove_from_array;
	array->Get = get_data;
	array->Free = free_array;

	array->data = (void**)malloc(size * typeSize);
	array->size = 0;
	array->length = size;

	for (size_t i = 0; i < size; i++)
	{
		array->data[i] = NULL;
	}
}

void add_to_array(Array* array, void* element, int index) {
	array->data[index] = element;
	array->size++;
}

void remove_from_array(Array* array, int index) {
	array->data[index] = NULL;
	array->size--;
}

void** get_data(Array* array, int index) {
	return array->data[index];
}

void free_array(Array* array) {
	free(array->data);
	array->data = NULL;
}