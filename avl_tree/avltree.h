/*
 * file name: avltree.h
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Thu 31 Jan 2019 09:00:45 PM CST
 */

#ifndef _AVLTREE_H
#define _AVLTREE_H

#define T	AVLTree
typedef int dtype_t;
typedef struct T *T;

extern T	AVL_make_empty(T t);
extern T	AVL_search(T t, dtype_t x);
extern T	AVL_getmin(T t);
extern T	AVL_getmax(T t);
extern T	AVL_insert(T t, dtype_t x);
extern T	AVL_delete(T t, dtype_t x);
extern dtype_t 	AVL_retrieve(T pos);
extern void     AVL_inprints(T t);
extern void     AVL_preprints(T t);
extern void     AVL_sufprints(T t);
/* special functional */

#endif
