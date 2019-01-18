/*
 * file name: adt.h
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Mon 14 Jan 2019 05:04:57 PM CST
 */

#ifndef _ADT_H
#define _ADT_H

#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define UNDEFINED	-((int)'k')	/* Magic number */
typedef int 		adtval_t;
#define bool 	_Bool 
typedef struct adtset_t *adtset_t;

struct adtset_t {
	/* member functions */
	int      (*isempty) (adtset_t t);
	int      (*size)    (adtset_t t);
	int 	 (*capacity)(adtset_t t);
	void     (*insert)  (adtset_t t, int index, adtval_t x);
	void     (*push)    (adtset_t t, adtval_t x);
	void     (*pop)     (adtset_t t);
	void     (*reverse) (adtset_t t);
	void     (*print)   (adtset_t t);
	void     (*iterate) (adtset_t t, int (*func) ());
	void     (*remove)  (adtset_t t, int index);
	void     (*find)    (adtset_t t, adtval_t x);
	/* data elements */
	int       __sz;
	int       __capacity; 
	adtval_t *__set;
};

extern void     adt_member_init(adtset_t t);
extern adtset_t adt_new(int size);
extern int      adt_isempty(adtset_t t);
extern int      adt_size(adtset_t t);
extern void     adt_insert(adtset_t t, int index, adtval_t x);
extern void     adt_print(adtset_t t);
extern void     adt_iterate(adtset_t t, int (*func) ());
extern void     adt_remove(adtset_t t, int index);
extern int      adt_find(adtset_t t, adtval_t x);

/* function of adt */
#define adt_alloc(size, pointer)	\
	pointer = (__typeof(pointer)) malloc(sizeof(__typeof(*pointer)) * size);
#define adt_foreach(sz, v, pointer) \
{				 \
	for (int i = 0; i < sz; i++) { \
		*(pointer + i) = v;       \
	}			       \
}

#endif
