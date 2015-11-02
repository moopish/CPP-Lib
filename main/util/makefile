util : enter $(patsubst %.c,../obj/utl_%.o,$(wildcard *.c)) 
	@echo

enter :
	@echo "Util"

../obj/utl_bit.o : bit.c util.h
	@echo " -> bit compiled"
	gcc -o ../obj/utl_bit.o -c bit.c

../obj/utl_int_qll.o : int_qll.c util.h
	@echo " -> int quick linked list compiled"
	gcc -o ../obj/utl_int_qll.o -c int_qll.c
