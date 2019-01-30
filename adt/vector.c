/*
 * file name: adt.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Mon 14 Jan 2019 05:08:56 PM CST
 */

#include "vector.h"
#include "alloc.h"
#include "general.h"

Vector vec_new(int size, vec_t val)
{
	Vector t;
	NEW(t);
	vec_alloc(size, t->__set);
	vec_foreach(size, val, t->__set);
	t->__sz = size;
	t->__capacity = size;
	return t;
}
int vec_isempty(Vector t)
{
	return t->__sz == 0;
}

int vec_size(Vector t)
{
	return t->__sz;
}

int vec_capacity(Vector t)
{
	return t->__capacity;
}

void vec_make_empty(Vector t)
{
	int i;
	for (i = 0; i < t->__capacity; i++)
		vec_remove(t, 0);
}
void vec_insert(Vector t, int index, vec_t x)
{
	int i;
	assert(t);
	assert(t->__capacity > 0);
	assert(index >= 0);
	assert(index < t->__capacity);
	t->__sz++;
	if (t->__sz > t->__capacity) {
		t->__set = doubleset(t->__set, t->__capacity);
		t->__capacity *= 2;
	}
	for (i = t->__capacity - 1; i >= index; i--) {
		t->__set[i + 1] = t->__set[i];
	}
	t->__set[i + 1] = x;

}

void vec_remove(Vector t, int index)
{
	/* Exception of adt remove function */
	assert(index >= 0 || index < t->__sz);

	int i;
	for (i = index; i < t->__sz; i++) {
		t->__set[i] = t->__set[i + 1];
	}

	t->__set[i - 1] = UNDEFINED;
	t->__sz--;
}

void vec_push(Vector t, vec_t x)
{
	if (t->__sz > t->__capacity)
		t->__set = doubleset(t->__set, t->__capacity);
	vec_insert(t, t->__sz, x);
}

void vec_reverse(Vector t)
{
	/* reverse the adt */
	int i;
	/* O(n / 2) */
	for (i = 0; i < t->__capacity / 2; i++) {
		swap(&t->__set[i], &t->__set[t->__capacity - i - 1]);
	}
}

vec_t vec_pop(Vector t)
{
	vec_t tmp = t->__set[t->__sz];
	t->__set[t->__sz] = UNDEFINED;
	t->__sz--;
	return tmp;
}

void vec_print(Vector t, int index)
{
	assert(index < t->__capacity);
	if (t->__set[index] == UNDEFINED)
		printf("undefined");
	else 
		printf("%d", t->__set[index]);
}

void vec_prints(Vector t)
{
	int i;
	putchar('[');
	for (i = 0; i < t->__capacity; i++) {
		if (t->__set[i] == UNDEFINED)
			printf("undefined,");
		else 
			printf("%d,", t->__set[i]); 
	}
	putchar(']');
}

int vec_find(Vector t, vec_t x)
{
	assert(t);
	int i;
	for (i = 0; i < t->__sz; i++) {
		if (t->__set[i] == x)
			return i;
	}
	return -1;
}

vec_t vec_locate(Vector t, int index)
{
	assert(t && index > -1 && index < t->__capacity);
	return t->__set[index];
}
void vec_iterate(Vector t, int (*func) ())
{
	/* Not implementation */
}

Vector vec_resize(Vector t, int size)
{
	Vector tmp;
	NEW(tmp);
	vec_alloc(size, tmp->__set);
	memcpy(tmp->__set, t->__set, size);
	tmp->__capacity = size;
	tmp->__sz       = t->__sz;
	free(t);
	return tmp;
}
void vec_member_init(Vector t)
{
	t->size     = vec_size;
	t->isempty  = vec_isempty;
	t->capacity = vec_capacity;
	t->make_empty = vec_make_empty;
	t->insert   = vec_insert;
	t->remove   = vec_remove;
	t->push     = vec_push;
	t->pop      = vec_pop;
	t->reverse  = vec_reverse;
	t->prints   = vec_prints;
	t->print    = vec_print;
	t->find     = vec_find;	
	t->locate   = vec_locate;	
	t->iterate  = vec_iterate;
	t->resize   = vec_resize;
}

