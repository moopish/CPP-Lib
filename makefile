define \n


endef

SRC_DIRS=arr cont math util
MAKER=$(foreach DIR,$(patsubst %makefile,%,$(wildcard */makefile)),make -f makefile -C $(DIR) ${\n})
HEADERS=$(wildcard *.h)

build :
	@echo "============================"
	@echo " C++ Lib by Michael van Dyk "
	@echo "   ---- Version 0.01 ----   "
	@echo "============================\n"
	@echo "Builing VDLib...\n"
	@make -s libtest

libtest : $(HEADERS) make_each obj/main.o 
	@echo "Building test executable..."
	g++ -o libtest obj/*.o
	@echo "Done!\n"

obj/main.o : main.cpp $(HEADERS)
	@echo "Compiling main"
	g++ -o obj/main.o -c main.cpp

make_each :
	$(MAKER)

add :
	@echo "Adding to git..."
	$(foreach DIR,$(SRC_DIRS),@git add $(DIR)/* ${\n})
	@git add makefile
	@git add main.cpp
	@echo "Done!\n"

commit :
	@git commit -m ${m}

push :
	@git push

clean : 
	@echo "Cleaning..."
	rm obj/*.o libtest
	@echo "Done!\n"
