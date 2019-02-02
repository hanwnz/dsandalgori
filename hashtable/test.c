/*
 * file name: test.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Sat 02 Feb 2019 09:46:40 AM CST
 */

#include "hash_sep.h"
#include <stdio.h>

int main(void)
{
	HashTable t;
	ListNode pos;
	t = HASH_new(10);
	HASH_insert(t, "a");
	HASH_insert(t, "b");
	HASH_insert(t, "c");
	HASH_insert(t, "d");
	HASH_insert(t, "e");
	
	HASH_insert(t, "f");
	HASH_insert(t, "cc");
	HASH_insert(t, "gg");
	HASH_insert(t, "aa");
	pos = HASH_search(t, "a");
	printf("%s\n", HASH_retrieve(pos));	
	HASH_prints(t);
	return 0;
}
