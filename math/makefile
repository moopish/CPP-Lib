math : enter $(patsubst %.cpp,../obj/mth_%.o,$(wildcard *.cpp)) 
	@echo

enter :
	@echo "Math"

../obj/mth_prime.o : prime.cpp math.h
	@echo " -> prime compiled"
	g++ -o ../obj/mth_prime.o -c prime.cpp
