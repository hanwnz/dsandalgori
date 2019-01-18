/*
 * file name: test.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Mon 14 Jan 2019 05:32:19 PM CST
 */

//#include <self/adt.h>
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
	t->prints(t);
	putchar('\n');
	printf("Set size: %d, Set capacity: %d\n", t->__sz, t->__capacity);
	t->reverse(t);
	t->prints(t);
	putchar('\n');

	printf("-------------------------------------\n");
	/* Split line */
	t->prints(t);
	putchar('\n');
	int index = t->find(t, 5);
	printf("%d element's index is %d\n", 5, index);
	printf("Element %d at %d\n", index, t->locate(t, index)); 
	return 0;
}
