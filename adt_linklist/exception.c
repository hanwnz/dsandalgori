/*
 * file name: exception.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Wed 30 Jan 2019 09:17:28 AM CST
 */

#include "exception.h"

void raise_exception(enum exception e, const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	do_exception(e, fmt, ap); 
	va_end(ap);
}

void do_exception(enum exception e, const char *fmt, va_list ap)
{
	char buf[MAXBUF];
	vsnprintf(buf, MAXBUF - 1, fmt, ap);
	if (e)
		snprintf(buf + strlen(buf), MAXBUF - 1, 
				"%s", get_exception_err(e));
	strcat(buf, "\n");
	fflush(stdout);
	fputs(buf, stderr);
	fflush(stdout);
}

char *get_exception_err(enum exception e)
{
	char *buf = NEW(buf);
	switch (e) {
	case MEMORY_EXCEPTION:
		buf = "Memory allocate exception\n";
		break;
	default:
		buf = "Unknown's exception\n";
		break;
	}
	return buf;
}
