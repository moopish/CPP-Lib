util : enter $(patsubst %.c,../objects/utl_%.o,$(wildcard *.c)) 
	@echo

enter :
	@echo "Util"

../obj/utl_basic.o : basic.c util.h
	@echo " -> basic compiled"
	gcc -o ../objects/utl_basic.o -c basic.c
