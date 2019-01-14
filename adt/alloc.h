/*
 * file name: alloc.h
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Mon 14 Jan 2019 05:30:32 PM CST
 */

#ifndef _ALLOC_H
#define _ALLOC_H

#define NEW(x)		x = (__typeof(x)) malloc(sizeof(__typeof(*x)));

#endif
