/*
 * file name: test.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Fri 01 Feb 2019 11:31:34 AM CST
 */

#include "avltree.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	AVLTree t = NULL, pos;
	t = AVL_insert(t, 3);
	t = AVL_insert(t, 2);
	t = AVL_insert(t, 1);
	t = AVL_insert(t, 4);
	t = AVL_insert(t, 5);
	t = AVL_insert(t, 6);
	t = AVL_insert(t, 7);
	AVL_inprints(t);
	putchar('\n');
	AVL_preprints(t);
	putchar('\n');
	pos = AVL_getmin(t);
	printf("%d\n", AVL_retrieve(pos));
	pos = AVL_getmax(t);
	printf("%d\n", AVL_retrieve(pos));
	
	pos = AVL_search(t, 10);
	if (pos)
		printf("%d\n", AVL_retrieve(pos));
	else
		printf("Not find this value\n");
	return 0;
}
