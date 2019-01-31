/*
 * file name: bintree.h
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Thu 31 Jan 2019 10:00:18 AM CST
 */

#ifndef _BINTREE_H
#define _BINTREE_H

typedef int dtype_t;
#define T BinSearchTree
typedef struct T *T;


extern T	 BST_make_empty(T bst);
extern T 	 BST_insert(T bst, dtype_t x);
extern T 	 BST_delete(T bst, dtype_t x);
extern T	 BST_search(T bst, dtype_t x);
extern T	 BST_getmax(T bst);
extern T	 BST_getmin(T bst);
extern void 	 BST_inprint(T bst);
extern void 	 BST_preprint(T bst);
extern void 	 BST_sufprint(T bst);
extern dtype_t 	 BST_retrieve(T pos);

#undef T

#endif
