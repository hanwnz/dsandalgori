/*
 * file name: suffix.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Wed 30 Jan 2019 05:38:50 PM CST
 */

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
	Stack stk = STK_new();
	int c;
	int left, right;
	while ((c = getchar()) != '\n') {
		if (isdigit(c)) {
			STK_push(stk, c - '0');
		} else {
			right = STK_pop(stk);
			left  = STK_pop(stk);
			switch (c) {
			case '+':
				STK_push(stk, left + right);
				break;
			case '*':
				STK_push(stk, left * right);
				break;
			case '-':
				STK_push(stk, left - right);
				break;
			case '/':
				STK_push(stk, left / right);
				break;
			}
		}
	}
	int ret = STK_pop(stk);
	printf("%d\n", ret);
	return 0;
}
