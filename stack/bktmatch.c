/*
 * file name: match.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Wed 30 Jan 2019 05:04:08 PM CST
 */

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	Stack stk = STK_new();
	char c;
	while ((c = getchar()) != '\n') {
		if (c == '(' || c == '[' ||
			c == '{')
			STK_push(stk, c);
		else {
			if (STK_is_empty(stk)) {
				fprintf(stderr, "Occured an error\n");
				exit(-1);
			}
			switch (c) {
			case ')':
				if (STK_pop(stk) != '(') {
					fprintf(stderr, "Occured an error\n");
					exit(-1);
				}
				break;
			case '}':
				if (STK_pop(stk) != '{') {
					fprintf(stderr, "Occured an error\n");
					exit(-1);
				}
				break;
			case ']':
				if (STK_pop(stk) != '[') {
					fprintf(stderr, "Occured an error\n");
					exit(-1);
				}
				break;
			default:
				break;
			}
		}
	}
	if (!STK_is_empty(stk)) {
		fprintf(stderr, "Occured an error\n");
		exit(-1);
	}
	printf("Bracket Matched\n");
	exit(0);
}
