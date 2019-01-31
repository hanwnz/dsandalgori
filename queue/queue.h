/*
 * file name: queue.h
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Thu 31 Jan 2019 08:20:25 AM CST
 */

#ifndef _QUEUE_H
#define _QUEUE_H

typedef int 	dtype_t;

#define T	Queue
typedef struct T *T;

extern T  	 Q_new();
extern int	 Q_is_empty(T q);
extern void 	 Q_enqueue(T q, dtype_t x);
extern dtype_t 	 Q_dequeue(T q);
extern dtype_t   Q_get_front(T q);
extern void 	 Q_prints(T q);
#undef T

#endif 
