/*
 * file name: adt.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Mon 14 Jan 2019 05:08:56 PM CST
 */

#include "adt.h"
#include "alloc.h"
#include "general.h"

adtset_t adt_new(int size)
{
	adtset_t t;
	NEW(t);
	adt_alloc(size, t->__set);
	adt_foreach(size, UNDEFINED, t->__set);
	t->__sz = 0;
	t->__capacity = size;
	return t;
}
int adt_isempty(adtset_t t)
{
	return t->__sz == 0;
}

int adt_size(adtset_t t)
{
	return t->__sz;
}

int adt_capacity(adtset_t t)
{
	return t->__capacity;
}

void adt_insert(adtset_t t, int index, adtval_t x)
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

void adt_remove(adtset_t t, int index)
{
	/* Exception of adt remove function */
	assert(index > 0 || index < t->__sz);

	int i;
	for (i = index; i < t->__sz; i++) {
		t->__set[i - 1] = t->__set[i];
	}
	t->__set[i - 1] = UNDEFINED;

}

void adt_push(adtset_t t, adtval_t x)
{
	if (t->__sz > t->__capacity)
		t->__set = doubleset(t->__set, t->__capacity);
	adt_insert(t, t->__sz, x);
}

void adt_reverse(adtset_t t)
{
	/* reverse the adt */
	int i;
	/* O(n / 2) */
	for (i = 0; i < t->__sz / 2; i++) {
		swap(&t->__set[i], &t->__set[t->__sz - i - 1]);
	}
}

adtval_t adt_pop(adtset_t t)
{
	adtval_t tmp = t->__set[t->__sz];
	t->__set[t->__sz] = UNDEFINED;
	return tmp;
}

void adt_print(adtset_t t, int index)
{
	printf("%d", t->__set[index]);
}

void adt_prints(adtset_t t)
{
	int i;
	for (i = 0; i < t->__sz; i++) {
		printf("%d ", t->__set[i]);
	}
}

int adt_find(adtset_t t, adtval_t x)
{
	assert(t);
	int i;
	for (i = 0; i < t->__sz; i++) {
		if (t->__set[i] == x)
			return i;
	}
	return -1;
}

adtval_t adt_locate(adtset_t t, int index)
{
	assert(t && index > -1);
	return t->__set[index];
}
void adt_iterate(adtset_t t, int (*func) ())
{
	/* Not implementation */
}

void adt_member_init(adtset_t t)
{
	t->size     = adt_size;
	t->isempty  = adt_isempty;
	t->capacity = adt_capacity;
	t->insert   = adt_insert;
	t->remove   = adt_remove;
	t->push     = adt_push;
	t->pop      = adt_pop;
	t->reverse  = adt_reverse;
	t->prints   = adt_prints;
	t->print    = adt_print;
	t->find     = adt_find;	
	t->locate   = adt_locate;	
	t->iterate  = adt_iterate;
}

