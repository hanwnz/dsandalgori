/*
 * file name: general.h
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Mon 14 Jan 2019 06:42:27 PM CST
 */

#include <stdlib.h>
#include <string.h>
typedef int 	gentype;

gentype *doubleset(gentype *target, int size)
{
	int n = sizeof(gentype) * size * 2;
	gentype *result = (gentype*) malloc(n);
	memcpy(result, target, n / 2);
	return result;
}

void swap(gentype *a, gentype *b)
{
	gentype tmp;
	tmp = *a;
	*a  = *b;
	*b  = tmp;
}
