util : enter $(patsubst %.c,../obj/utl_%.o,$(wildcard *.c)) 
	@echo

enter :
	@echo "Util"

../obj/utl_bit.o : bit.c util.h
	@echo " -> bit compiled"
	gcc -o ../obj/utl_bit.o -c bit.c
