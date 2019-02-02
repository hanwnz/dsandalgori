/*
 * file name: hash_sep.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Fri 01 Feb 2019 07:22:49 PM CST
 */

#include "hash_sep.h"
#include "exception.h"
#include "allocate.h"

#define T	HashTable
#define TL	ListNode 

struct T;
struct TL;
struct T {
	int tbl_size;
	TL *list;	
};
struct TL {
	dtype_t elem;
	TL 	next;
};
static int get_prime(int tbl_size);
static int is_prime(int num);
static unsigned int hash(const char *key, int tbl_size);

T HASH_new(int tbl_size)
{
	T h;

	h = NEW(h);
	if (h == NULL)
		raise_exception(MEMORY_EXCEPTION,
				"Allocate error");
	h->tbl_size = get_prime(tbl_size);
	h->list = (__typeof(h->list)) malloc(sizeof(*(h->list)) * h->tbl_size);
	
	for (int i = 0; i < h->tbl_size; i++) {
		h->list[i] = malloc(sizeof(*(h->list[i])));
	}

	return h;
}

TL HASH_search(T h, dtype_t key)
{
	TL pos, l;
	l = h->list[hash(key, h->tbl_size)];
	pos = l->next;
	while (pos != NULL && 
		(strcmp(pos->elem, key) != 0))
		pos = pos->next;
	return pos;
}

void HASH_insert(T h, dtype_t key)
{
	TL l, pos;
	TL newnode;
	unsigned int hval = hash(key, h->tbl_size);
	l = h->list[hval];
	pos = l->next;
	while (pos != NULL &&
		(strcmp(pos->elem, key) != 0))
		pos = pos->next;
	
	if (pos == NULL) {
		newnode = NEW(newnode);
		if (newnode == NULL)
			raise_exception(MEMORY_EXCEPTION,
					"Allocate error");
		l = h->list[hash(key, h->tbl_size)];
		newnode->next = l->next;
		newnode->elem = key;
		l->next = newnode;
	}
}

dtype_t HASH_retrieve(TL pos)
{
	return pos->elem;
}

void HASH_prints(T h)
{
	int i;
	for (i = 0; i < h->tbl_size; i++) {
		TL pos = h->list[i]->next;
		printf("Bucket %-2d: ", i + 1);
		while (pos != NULL) {
			printf("%s->", pos->elem);
			pos = pos->next;
		}
		putchar('\n');
	}
}
static int is_prime(int num)
{
	int i;
	for (i = 2; i < num; i++) {
		if (num % i == 0)
			return 0;
	}
	return 1;
}
static int get_prime(int tbl_size)
{
	int i;

	for (i = tbl_size; ;i++) {
		if (is_prime(i))
			return i;
	}
}

static unsigned int hash(const char *key, int tbl_size)
{
	unsigned int hash_val = 0;

	while (*key != '\0')
		hash_val = (hash_val << 5) | *key++;
	return hash_val % tbl_size;
}
