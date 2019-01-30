/*
 * file name: infix2suffix.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Wed 30 Jan 2019 08:50:50 PM CST
 */

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

enum optr_level {
	PLUS = 1, MINUS = 1,
	TIMES = 2, DIVIDE = 2,
	PAREN = 3,
};

int get_optr_level(char optr);
int main(void)
{
	Stack stk = STK_new();
	int c;
	
	while ((c = getchar()) != '\n') {
		if (isalnum(c)) {
			putchar(c);
		} else if (c == '(') {
			STK_push(stk, c);
		} else if (c == ')') {	
			int poped;
			do {
				poped = STK_pop(stk);
				if (poped != ')' && poped != '(')
					putchar(poped);
			} while (poped != '(');
		} else {
			if (STK_is_empty(stk)) 
				STK_push(stk, c);
			else {
				int top = STK_get_top(stk);
				while ((get_optr_level(top) >=
					get_optr_level(c))
					&& !STK_is_empty(stk)) {
					top = STK_get_top(stk);
					if (top != '(')
						putchar(STK_pop(stk));	
					else
						break;
				}
				STK_push(stk, c); 	
			}
		}
	}
	while (!STK_is_empty(stk))
		putchar(STK_pop(stk));
	putchar('\n');
	return 0;
}

int get_optr_level(char optr)
{
	switch (optr) {
	case '+':
		return PLUS;
	case '-':
		return MINUS;
	case '*':
		return TIMES;
	case '/':
		return DIVIDE;
	case '(':
	case ')':
		/* fall through */
		return PAREN;
	default:
		return -1;
	}
}
