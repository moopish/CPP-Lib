big : enter $(patsubst %.c,../obj/big_%.o,$(wildcard *.c)) 
	@echo

enter :
	@echo "Big"

../obj/big_cint.o : cint.c bcint.h
	@echo " -> big C int compiled"
	gcc -o ../obj/big_cint.o -c cint.c

