#######################################################################
# file name: Makefile
# author   : Yu Liu
# email    : <ilhanwnz@hotmail.com>
# time     : Mon 14 Jan 2019 06:08:55 PM CST
#######################################################################

OBJ := vector.o 
CC   = gcc
AR   = ar
ARFLAGS = crv 
LIB  = libvector.a
USRDIR = /usr/include/self
USRLIBDIR = /usr/lib/selflib
INCLUDEDIR = /usr/include
LIBDIR 	   = /usr/lib

$(LIB): $(OBJ)
	$(AR) $(ARFLAGS) $@ $(OBJ)
$(OBJ): vector.c 

install: $(LIB) 
	if [ -e "$(USRDIR)" ] && [ -e "$(USRLIBDIR)" ];  \
	then 			         \
		echo -e "\n\nYours system already exists directories, create failed" || exit 1; \
	else 			         \
		if [ -w "$(INCLUDEDIR)" ] && [ -w "$(LIBDIR)" ];  	\
		then 			 \
			mkdir $(USRDIR); \
			mkdir $(USRLIBDIR);  \
			cp $(LIB) $(USRLIBDIR); \
		else 				 \
		echo -e "\n\nPermission denied: Please use root account!" || exit 1;    \
		fi 				 \
	fi   				 
	
clean:
	rm -rf $(OBJ) $(LIB)
