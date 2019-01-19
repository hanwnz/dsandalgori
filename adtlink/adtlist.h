/*
 * file name: adtlist.h
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Sat 19 Jan 2019 08:13:35 AM CST
 */

#ifndef _ADTLIST_H
#define _ADTLIST_H

typedef int adtval_t;
typedef struct node *node;

struct node {
	node 	 (*mkempty) 	(node t);
	int      (*isempty) 	(node t);
	node     (*find)    	(node t, adtval_t x);
	void     (*remove_val)	(node t, adtval_t x);
	void     (*remove_idx)  (node t, int index);
	node     (*getprevnode) (node t, adtval_t x);
	void     (*insert)      (node t, adtval_t x);
	void     (*print)       (node t);
	adtval_t nodeval;
	node     next;
};

extern void     adtlink_member_init(node t);
extern node     adtlink_new();
extern node 	adtlink_mkempty(node t);
extern int  	adtlink_isempty(node t);
extern node     adtlink_find(node t, adtval_t x);
extern void     adtlink_remove_val(node t, adtval_t x);
extern void     adtlink_remove_idx(node t, int index);
extern node     adtlink_getprevnode(node t, adtval_t x);
extern void     adtlink_insert(node t, adtval_t x);
extern void     adtlink_print(node t);

#endif
