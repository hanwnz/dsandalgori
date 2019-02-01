/*
 * file name: avltree.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Thu 31 Jan 2019 09:04:13 PM CST
 */

#include "avltree.h"
#include "exception.h"
#include "mmath.h"
#include "allocate.h"

#define T	AVLTree

struct T {
	dtype_t elem;
	T	left;
	T	right;
	int 	height;
};

static T single_rotate_left(T k2);
static T single_rotate_right(T k1);
static T double_rotate_left(T k3);
static T double_rotate_right(T k3);
static int AVL_height(T pos);


T AVL_make_empty(T t)
{
	
}

T AVL_getmin(T t)
{
	if (t == NULL)
		return NULL;
	else if (t->left == NULL)
		return t;
	else 
		return AVL_getmin(t->left);
}

T AVL_getmax(T t)
{
	if (t == NULL)
		return NULL;
	else if (t->right == NULL)
		return t;
	else 
		return AVL_getmax(t->right);
}

T AVL_search(T t, dtype_t x)
{
	if (t == NULL)
		return NULL;
	if (x > t->elem)
		return AVL_search(t->right, x);
	else if (x < t->elem)
		return AVL_search(t->left, x);
	else
		return t;
}

dtype_t AVL_retrieve(T t)
{
	return t->elem;
}	
T AVL_insert(T t, dtype_t x)
{
	if (t == NULL) {
		t = NEW(t);
		if (t == NULL)
			raise_exception(MEMORY_EXCEPTION,
					"Allocate error");
		else {
			t->elem = x;
			t->height = 0;
			t->left = t->right = NULL;
		}
	} else if (x > t->elem) {
		t->right = AVL_insert(t->right, x);
		if (AVL_height(t->right) - AVL_height(t->left) == 2) {
			if (x > t->right->elem)
				t = single_rotate_right(t);
			else 
				t = double_rotate_right(t);
		}
	} else if (x < t->elem) {
		t->left = AVL_insert(t->left, x);
		if (AVL_height(t->left) - AVL_height(t->right) == 2) {
			if (x < t->left->elem)
				t = single_rotate_left(t);
			else 
				t = double_rotate_left(t);
		}
	}
	t->height = MAX(AVL_height(t->left), AVL_height(t->right)) + 1;
	return t;
}

static T single_rotate_left(T k2)
{
	T k1;
	k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;
	
	k2->height = MAX(AVL_height(k2->left), AVL_height(k1->right)) + 1;
	k1->height = MAX(k2->height, AVL_height(k1->left)) + 1;

	return k1;
}

static T single_rotate_right(T k2)
{
	T k1;
	k1 = k2->right;
	k2->right = k1->left;
	k1->left = k2;

	k2->height = MAX(AVL_height(k2->left), AVL_height(k2->right)) + 1;
	k1->height = MAX(k2->height, AVL_height(k1->right)) + 1;

	return k1;
}

static T double_rotate_left(T k3)
{
	k3->left = single_rotate_right(k3->left);
	return single_rotate_left(k3);
}

static T double_rotate_right(T k3)
{
	k3->right = single_rotate_left(k3->right);
	return single_rotate_right(k3);
}

static int AVL_height(T pos)
{
	if (pos == NULL)
		return -1;
	return pos->height;
}

void AVL_inprints(T t)
{
	if (t != NULL) {
		AVL_inprints(t->left);
		printf("%d ", t->elem);
		AVL_inprints(t->right);
	}
}

void AVL_preprints(T t)
{
	if (t != NULL) {
		printf("%d ", t->elem);
		AVL_preprints(t->left);
		AVL_preprints(t->right);
	}
}

void AVL_sufprints(T t)
{
	if (t != NULL) {
		AVL_sufprints(t->left);
		AVL_sufprints(t->right);
		printf("%d ", t->elem);
	}
}
