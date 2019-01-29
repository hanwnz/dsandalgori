/*
 * file name: adt.h
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Mon 14 Jan 2019 05:04:57 PM CST
 */

#ifndef _VECTOR_H
#define _VECTOR_H

#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define UNDEFINED	-((int)'k')	/* Magic number */
typedef int 		vec_t;
#define bool 	_Bool 
typedef struct Vector *Vector;

struct Vector {
	/* member functions */
	int      (*isempty) (Vector t);
	int      (*size)    (Vector t);
	int 	 (*capacity)(Vector t);
	void     (*insert)  (Vector t, int index, vec_t x);
	void     (*push)    (Vector t, vec_t x);
	vec_t (*pop)     (Vector t);
	void     (*reverse) (Vector t);
	void     (*print)   (Vector t, int index);
	void     (*prints)  (Vector t);
	void     (*iterate) (Vector t, int (*func) ());
	void     (*remove)  (Vector t, int index);
	int      (*find)    (Vector t, vec_t x);
	vec_t (*locate)  (Vector t, int index);
	/* data elements */
	int       __sz;
	int       __capacity; 
	vec_t *__set;
};

extern void     vec_member_init(Vector t);
extern Vector vec_new(int size);
extern int      vec_isempty(Vector t);
extern int      vec_size(Vector t);
extern int      vec_capacity(Vector t);
extern void     vec_insert(Vector t, int index, vec_t x);
extern void     vec_push(Vector, vec_t x);
extern vec_t vec_pop(Vector);
extern void     vec_reverse(Vector t);
extern void     vec_print(Vector t, int index);
extern void     vec_prints(Vector t);
extern void     vec_iterate(Vector t, int (*func) ());
extern void     vec_remove(Vector t, int index);
extern int      vec_find(Vector t, vec_t x);
extern vec_t vec_locate(Vector t, int index);

/* function of adt */
#define vec_alloc(size, pointer)	\
	pointer = (__typeof(pointer)) malloc(sizeof(__typeof(*pointer)) * size);
#define vec_foreach(sz, v, pointer) \
{				 \
	for (int i = 0; i < sz; i++) { \
		*(pointer + i) = v;       \
	}			       \
}

#endif
