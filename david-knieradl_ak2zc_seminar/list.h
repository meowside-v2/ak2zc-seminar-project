
#ifndef __LIST_H__
#define	__LIST_H__

#include <stdbool.h>


typedef struct List
{
	int* _data;
	size_t size;
	size_t capacity;
} List;


List make_list(const size_t capacity);
void destroy_list(List* const list);

bool push_back(List* const list, const int value);
int pop_back(List* const list);
int get_at(const List* const list, int* const index);

#endif // !__LIST_H__
