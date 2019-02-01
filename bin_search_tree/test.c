/*
 * file name: test.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Thu 31 Jan 2019 01:39:50 PM CST
 */

#include "bintree.h"
#include <stdio.h>

int main(void)
{
	BinSearchTree bst = NULL;
	bst = BST_insert(bst, 3);
	bst = BST_insert(bst, 2);
	bst = BST_insert(bst, 1);
	bst = BST_insert(bst, 4);
	bst = BST_insert(bst, 0);
	BinSearchTree min, max;
	min = BST_getmin(bst);
	printf("This tree min is: %d\n", BST_retrieve(min));
	max = BST_getmax(bst);
	printf("This tree max is: %d\n", BST_retrieve(max));
	BST_inprint(bst);
	putchar('\n');
	BST_preprint(bst);
	putchar('\n');
	BST_sufprint(bst);
	putchar('\n');
	return 0;
}
