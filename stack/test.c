/*
 * file name: test.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Wed 30 Jan 2019 03:32:47 PM CST
 */

#include "stack.h"
#include <stdio.h>

int main(void)
{
	Stack s = STK_new();
	STK_push(s, 10);
	STK_push(s, 12);
	STK_prints(s);
	putchar('\n');
	printf("%d\n", STK_pop(s));
	STK_make_empty(s);
	STK_prints(s);
	STK_pop(s);
	return 0;
}
