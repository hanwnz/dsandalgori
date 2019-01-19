/*
 * file name: test.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Sat 19 Jan 2019 09:35:00 AM CST
 */

#include "adtlist.h"
#include <stdio.h>

int main(void)
{
	node t;
	t = adtlink_new();
	adtlink_member_init(t);
	t->insert(t, 0);
	t->insert(t, 1);
	t->insert(t, 2);
	t->print(t);
	putchar('\n');
	return 0;
}
