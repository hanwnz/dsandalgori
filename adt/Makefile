#######################################################################
# file name: Makefile
# author   : Yu Liu
# email    : <ilhanwnz@hotmail.com>
# time     : Mon 14 Jan 2019 06:08:55 PM CST
#######################################################################

OBJ := adt.o test.o 
test: $(OBJ)
	$(CC) $(OBJ) -o $@
$(OBJ): adt.c test.c
clean:
	rm -rf $(OBJ) test
