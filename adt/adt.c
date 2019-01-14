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
void adt_push(adtset_t t, adtval_t x)
{
	if (t->__sz > t->__capacity)
		t->__set = doubleset(t->__set, t->__capacity);
	adt_insert(t, t->__sz, x);
}
void adt_print(adtset_t t)
{
	int i;
	for (i = 0; i < t->__sz; i++) {
		printf("%d ", t->__set[i]);
	}
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
	t->push     = adt_push;
	t->print    = adt_print;
	t->iterate  = adt_iterate;
}

