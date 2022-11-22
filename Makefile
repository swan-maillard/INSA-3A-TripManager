main: main.o Trajet.o Trajetsimple.o ElementListe.o ListeTrajets.o
	g++ -o main main.o Trajet.o Trajetsimple.o

main.o: main.cpp
	g++ -c -g -DMAP main.cpp

Trajet.o: Trajet.cpp
	g++ -c -g -DMAP Trajet.cpp

Trajetsimple.o: Trajetsimple.cpp
	g++ -c -g -DMAP Trajetsimple.cpp

ElementListe.o: ElementListe.cpp
	g++ -c -g -DMAP ElementListe.cpp

ListeTrajets.o: ListeTrajets.cpp
	g++ -c -g -DMAP ListeTrajets.cpp
