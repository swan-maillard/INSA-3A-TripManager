main: main.o Trajet.o
	g++ -o main main.o Trajet.o

main.o: main.cpp
	g++ -c -g main.cpp

Trajet.o: Trajet.cpp
	g++ -c -g -DMAP Trajet.cpp
