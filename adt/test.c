/*
 * file name: test.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Mon 14 Jan 2019 05:32:19 PM CST
 */

#include "adt.h"

void print(adtset_t t);

int main(void)
{
	adtset_t t;
	int i;
	t = adt_new(10);
	adt_member_init(t);
	printf("%d\n", t->size(t));
	if (t->isempty(t)) {
		printf("Set is null\n");
	}
	for (i = 0; i < 10; i++) 
		t->insert(t, i, i+1);
	t->insert(t, i, i+1);
	t->push(t, 111);
	t->print(t);
	putchar('\n');
	printf("Set size: %d, Set capacity: %d\n", t->__sz, t->__capacity);

	return 0;
}
