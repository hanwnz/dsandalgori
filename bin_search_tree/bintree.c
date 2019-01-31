/*
 * file name: bintree.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Thu 31 Jan 2019 10:02:36 AM CST
 */

#include "bintree.h"
#include "allocate.h"
#include "exception.h"

#define T	BinSearchTree

struct T {
	dtype_t elem;
	T	left;
	T 	right;
};

T BST_make_empty(T bst)
{
	if (bst != NULL) {
		BST_make_empty(bst->left);
		BST_make_empty(bst->right);
		free(bst);
	}
	return NULL;
}

T BST_insert(T bst, dtype_t x)
{
	if (bst == NULL) {
		bst = NEW(bst);
		if (bst == NULL)
			raise_exception(MEMORY_EXCEPTION,
					"allocate error");
		bst->elem = x;
		bst->left = bst->right = NULL;
	} else {
		if (x > bst->elem)
			bst->right = BST_insert(bst->right, x);
		else if (x < bst->elem)
			bst->left = BST_insert(bst->left, x);
	}
	return bst;
}

T BST_delete(T bst, dtype_t x)
{
	T tmpnode;
	if (bst == NULL)
		return NULL;
	else if (x > bst->elem)
		bst->right = BST_delete(bst->right, x);
	else if (x < bst->elem)
		bst->left = BST_delete(bst->left, x);
	else if (bst->left && bst->right) {
		tmpnode = BST_getmin(bst->right);
		bst->elem = tmpnode->elem;
		bst->right = BST_delete(bst->right, bst->elem);
	} else {
		tmpnode = bst;
		if (bst->left == NULL)
			bst = bst->right;
		else if (bst->right == NULL)
			bst = bst->left;
		free(tmpnode);
	}
}
T BST_search(T bst, dtype_t x)
{
	if (bst == NULL)
		return NULL;
	if (x > bst->elem)
		return BST_search(bst->right, x);
	else if (x < bst->elem)
		return BST_search(bst->left, x);
	else
		return bst;
}

T BST_getmin(T bst)
{
	if (bst == NULL)
		return NULL;
	else if (bst->left == NULL)
		return bst;
	else 
		return BST_getmin(bst->left);
}

T BST_getmax(T bst)
{
	if (bst == NULL)
		return NULL;
	else if (bst->right == NULL)
		return bst;
	else
		return BST_getmax(bst->right);
}

dtype_t BST_retrieve(T bst)
{
	if (bst == NULL)
		raise_exception(TREE_EXCEPTION,
				"Tree is empty");
	return bst->elem;
}

void BST_inprint(T bst)
{
	if (bst != NULL) {
		BST_inprint(bst->left);
		printf("%d ", bst->elem);
		BST_inprint(bst->right);
	}
}

void BST_preprint(T bst)
{
	if (bst != NULL) {
		printf("%d ", bst->elem);
		BST_preprint(bst->left);
		BST_preprint(bst->right);
	}
}

void BST_sufprint(T bst)
{
	if (bst != NULL) {
		BST_sufprint(bst->left);
		BST_sufprint(bst->right);
		printf("%d ", bst->elem);
	}
}
