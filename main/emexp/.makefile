emexp : enter $(patsubst %.cpp,../obj/emexp_%.o,$(wildcard *.cpp)) 
	@echo

enter :
	@echo "EmExp"

../obj/emexp_Boolean.o : Boolean.cpp Boolean.h EmExp.h Type.h
	@echo " -> Boolean compiled"
	gcc -o ../obj/emexp_Boolean.o -c Boolean.cpp

../obj/emexp_EmExp.o : EmExp.cpp EmExp.h
	@echo " -> EmExp compiled"
	gcc -o ../obj/emexp_EmExp.o -c EmExp.cpp

../obj/emexp_Type.o : Type.cpp Type.h EmExp.h
	@echo " -> Type compiled"
	gcc -o ../obj/emexp_Type.o -c Type.cpp
