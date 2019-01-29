/*
 * file name: adt.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Mon 14 Jan 2019 05:08:56 PM CST
 */

#include "vector.h"
#include "alloc.h"
#include "general.h"

Vector vec_new(int size)
{
	Vector t;
	NEW(t);
	vec_alloc(size, t->__set);
	vec_foreach(size, UNDEFINED, t->__set);
	t->__sz = 0;
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

void vec_insert(Vector t, int index, vec_t x)
{
	int i;
	assert(t);
	assert(t->__capacity > 0);
	assert(index >= 0);
	if (index > t->__capacity - 1) {
		t->__set = doubleset(t->__set, t->__capacity);
		t->__capacity *= 2;
	}
	for (i = t->__sz; i >= index; i--) {
		t->__set[i + 1] = t->__set[i];
	}
	t->__set[index] = x;
	t->__sz++;
}

void vec_remove(Vector t, int index)
{
	/* Exception of adt remove function */
	assert(index > 0 || index < t->__sz);

	int i;
	for (i = index; i < t->__sz; i++) {
		t->__set[i - 1] = t->__set[i];
	}
	t->__set[i - 1] = UNDEFINED;

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
	for (i = 0; i < t->__sz / 2; i++) {
		swap(&t->__set[i], &t->__set[t->__sz - i - 1]);
	}
}

vec_t vec_pop(Vector t)
{
	vec_t tmp = t->__set[t->__sz];
	t->__set[t->__sz] = UNDEFINED;
	return tmp;
}

void vec_print(Vector t, int index)
{
	printf("%d", t->__set[index]);
}

void vec_prints(Vector t)
{
	int i;
	for (i = 0; i < t->__sz; i++) {
		printf("%d ", t->__set[i]);
	}
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
	assert(t && index > -1);
	return t->__set[index];
}
void vec_iterate(Vector t, int (*func) ())
{
	/* Not implementation */
}

void vec_member_init(Vector t)
{
	t->size     = vec_size;
	t->isempty  = vec_isempty;
	t->capacity = vec_capacity;
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
}

