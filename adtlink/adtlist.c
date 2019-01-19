/*
 * file name: adtlist.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Sat 19 Jan 2019 08:29:01 AM CST
 */

#include <stdlib.h>
#include <assert.h>
#include "general.h"
#include "adtlist.h"


node adtlink_new()
{
	node tmp;
	tmp = (node) malloc(sizeof(*tmp));
	tmp->next = NULL;
	tmp->nodeval = 0;
	return tmp;
}

node adtlink_mkempty(node t)
{
	return NULL;
}
int adtlink_isempty(node t)
{
	return t->next == NULL;
}

node adtlink_find(node t, adtval_t x)
{
	node p;
	p = t->next;
	while (p != NULL && p->nodeval != x)
		p = p->next;
	return p;
}

void adtlink_remove_val(node t, adtval_t x)
{
	assert(t);
	node p, tmp;
	p = adtlink_getprevnode(t, x);	
	if (p->next != NULL) {
		tmp = p->next;
		p->next = tmp->next;
		free(tmp);
	}
}

node adtlink_getprevnode(node t, adtval_t x)
{
	node p = t;
	while (p->next != NULL && p->next->nodeval != x)
		p = p->next;
	return p;
}

void adtlink_insert(node t, adtval_t x)
{
	node p = t;
	while (p->next != NULL)
		p = p->next;
	node tmpnode;
	tmpnode = malloc(sizeof(*tmpnode));
	if (tmpnode == NULL)
		exception("Memory allocate  failed");
	tmpnode->nodeval = x;
	tmpnode->next = p->next;
	p->next = tmpnode;
}
void adtlink_remove_idx(node t, int idx)
{

}
void adtlink_print(node t)
{
	node p = t->next;
	while (p != NULL) {
		printf("%d ", p->nodeval);
		p = p->next;
	}
}

void adtlink_member_init(node t)
{
	t->find = adtlink_find;
	t->getprevnode = adtlink_getprevnode;
	t->insert = adtlink_insert;
	t->isempty = adtlink_isempty;
	t->mkempty = adtlink_mkempty;
	t->print   = adtlink_print;
	t->remove_val = adtlink_remove_val;
	t->remove_idx = adtlink_remove_idx;
}
