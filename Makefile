main: main.o Trajet.o
	g++ -o main main.o Trajet.o Trajetsimple.o

main.o: main.cpp
	g++ -c -g main.cpp

Trajet.o: Trajet.cpp
	g++ -c -g -DMAP Trajet.cpp

Trajetsimple.o: Trajetsimple.cpp
	g++ -c -g -DMAP Trajetsimple.cpp
