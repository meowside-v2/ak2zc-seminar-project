
#include "list.h"
#include <stdio.h>
#include <stdlib.h>



bool _list_resize(List* const list, const size_t new_capacity, const size_t min_capacity) {
	const size_t effective_capacity = max(new_capacity, min_capacity);
	int* new_data = (int*)realloc(list->_data, sizeof(int) * effective_capacity);
	
	// Reallocation failed
	if (new_data == NULL) {
		return false;
	}
	
	list->_data = new_data;
	list->capacity = new_capacity;
	return true;
}



bool push_back(List* const list, const int value) {
	// Try to reallocate full list
	if (list->size >= list->capacity && !_list_resize(list, list->capacity * 2, 16)) {
		fprintf(stderr, "Error: Failed to grow the list.\n");
		return false;
	}

	list->_data[list->size] = value;
	list->size++;
	return true;
}

int pop_back(List* const list) {
	const int value = list->_data[list->size - 1];
	list->size--;

	// Try to shrink the list if array holds less than quarter of capacity
	if (list->size < list->capacity / 4 && !_list_resize(list, list->capacity / 2, 16)) {
		fprintf(stderr, "Error: Failed to shrink the list.\n");
	}

	return value;
}

int get_at(const List* const list, int* const index) {
	if (*index < 0 || *index >= list->size) {
		fprintf(stderr, "Error: Index out of bounds.\n");
		*index = -1;
		return 0;
	}

	return list->_data[*index];
}


List make_list(const size_t capacity) {
	// Assign default size for the list if the provided capacity is zero
	const size_t effective_capacity = max(capacity, 16);

	List list;
	list.size = 0;
	list._data = (int*)malloc(sizeof(int) * effective_capacity);
	if (list._data == NULL) {
		fprintf(stderr, "Error: Failed to allocate memory for the list.\n");
		list.capacity = 0;
	}
	else {
		list.capacity = effective_capacity;
	}

	return list;
}

void destroy_list(List* const list) {
	// Do nothing if the list is already empty
	if (list->_data == NULL) {
		return;
	}

	free(list->_data);
	list->_data = NULL;
	list->size = 0;
	list->capacity = 0;
}