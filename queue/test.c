/*
 * file name: test.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Thu 31 Jan 2019 08:44:25 AM CST
 */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(void)
{
	Queue q = Q_new();
	Q_enqueue(q, 10);
	Q_enqueue(q, 5);
	Q_enqueue(q, 2);
	Q_prints(q);
	putchar('\n');
	printf("%d\n", Q_get_front(q));
	printf("%d\n", Q_dequeue(q));
	printf("%d\n", Q_get_front(q));
	printf("%d\n", Q_dequeue(q));
	printf("%d\n", Q_dequeue(q));
	printf("%d\n", Q_dequeue(q));
	return 0;
}
