/*
 * file name: queue.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Thu 31 Jan 2019 08:28:07 AM CST
 */

#include "queue.h"
#include "allocate.h"
#include "exception.h"

#define T	Queue

struct T {
	dtype_t elem;
	T	next;
};

T Q_new()
{
	T t;
	t = NEW(t);
	t->elem = 0;
	t->next = NULL;
	return t;
}
int Q_is_empty(T q)
{
	return q->next == NULL;
}

void Q_enqueue(T q, dtype_t elem)
{
	T t, pos;
	t = NEW(t);
	pos = q;
	t->elem = elem;
	t->next = NULL;
	while (pos->next != NULL)
		pos = pos->next;
	pos->next = t;
}

dtype_t Q_dequeue(T q)
{
	T tmpnode;
	dtype_t elem;
	if (Q_is_empty(q))
		raise_exception(QUEUE_EXCEPTION,
				"Queue is empty");
	tmpnode = q->next;
	q->next = q->next->next;
	elem = tmpnode->elem;
	free(tmpnode);
	return elem;
}

void Q_prints(T q)
{
	T pos;
	if (Q_is_empty(q))
		raise_exception(QUEUE_EXCEPTION,
				"Queue is empty");
	pos = q->next;
	while (pos != NULL) {
		printf("%d ", pos->elem);
		pos = pos->next;
	}
}

dtype_t Q_get_front(T q)
{
	if (Q_is_empty(q))
		raise_exception(QUEUE_EXCEPTION,
				"Queue is empty");
	return q->next->elem;
}
