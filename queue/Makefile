#######################################################################
# file name: Makefile
# author   : Yu Liu
# email    : <ilhanwnz@hotmail.com>
# time     : Mon 14 Jan 2019 06:08:55 PM CST
#######################################################################

OBJ := exception.o queue.o 
CC   = gcc
AR   = ar
ARFLAGS = crv 
LIB  = libqueue.a
USRDIR = /usr/include/self
USRLIBDIR = /usr/lib/selflib
INCLUDEDIR = /usr/include
LIBDIR 	   = /usr/lib
HEADER := allocate.h exception.h queue.h
CFLAGS += -I../include
vpath %.h ../include
vpath exception.c ../common
$(LIB): $(OBJ)
	$(AR) $(ARFLAGS) $@ $(OBJ)
	ranlib $@
$(OBJ): exception.c queue.c

test: $(OBJ)
install: $(LIB) 
	if [ -e "$(USRDIR)" ] && [ -e "$(USRLIBDIR)" ];  \
	then 			         \
		cp $(LIB) $(USRLIBDIR); \
		cp $(HEADER) $(USRDIR); \
	else 			         \
		if [ -w "$(INCLUDEDIR)" ] && [ -w "$(LIBDIR)" ];  	\
		then 			 \
			mkdir $(USRDIR); \
			mkdir $(USRLIBDIR);  \
			cp $(LIB) $(USRLIBDIR); \
			cp $(HEADER) $(USRDIR); \
		else 				 \
		echo -e "\n\nPermission denied: Please use root account!" || exit 1;    \
		fi 				 \
	fi   				 
	
clean:
	rm -rf $(OBJ) $(LIB)
