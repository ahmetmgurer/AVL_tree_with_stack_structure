all: derle calistir

derle:
	g++ -I ./include -o ./lib/Avl.o -c ./src/Avl.cpp
	g++ -I ./include -o ./lib/Kisi.o -c ./src/Kisi.cpp
	g++ -I ./include -o ./lib/Stack.o -c ./src/Stack.cpp
	g++ -I ./include -o ./lib/Utils.o -c ./src/Utils.cpp
	g++ -I ./include -o ./bin/proje ./lib/Avl.o ./lib/Kisi.o ./lib/Stack.o ./lib/Utils.o ./src/Main.cpp
	
calistir:
	./bin/proje
