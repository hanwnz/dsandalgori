/*
 * file name: hash_sep.h
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Fri 01 Feb 2019 07:17:32 PM CST
 */

#ifndef _HASH_SEP_H
#define _HASH_SEP_H

#include <string.h>
typedef const char *dtype_t;
#define T	HashTable
typedef struct T *T; 

#define TL	ListNode
typedef struct TL *TL;

extern T	HASH_new(int tblsize);
extern void     HASH_free(T h);
extern TL	HASH_search(T h, dtype_t t);
extern void 	HASH_insert(T h, dtype_t t);
extern dtype_t 	HASH_retrieve(TL pos);
extern void     HASH_prints(T h);

#undef T
#undef TL 
#endif
