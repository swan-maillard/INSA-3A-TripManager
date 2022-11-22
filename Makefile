main: main.o Trajet.o Trajetsimple.o
	g++ -o main main.o Trajet.o Trajetsimple.o

main.o: main.cpp
	g++ -c -g -DMAP main.cpp

Trajet.o: Trajet.cpp
	g++ -c -g -DMAP Trajet.cpp

Trajetsimple.o: Trajetsimple.cpp
	g++ -c -g -DMAP Trajetsimple.cpp
