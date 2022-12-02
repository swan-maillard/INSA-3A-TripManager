using namespace std;

#include <iostream>
#include <cstring>

#include "../include/Trajetsimple.h"


Trajetsimple::Trajetsimple(const char* depart, const char* arrivee, const char* transport): Trajet() {
  #ifdef MAP
      cout << "Appel au constructeur de <Trajetsimple>" << endl;
  #endif

  char * depart_copy = new char(strlen(depart));
  strcpy(depart_copy, depart);
  this->depart = depart_copy;

  char * arrivee_copy = new char(strlen(arrivee));
  strcpy(arrivee_copy, arrivee);
  this->arrivee = arrivee_copy;

  char * transport_copy = new char(strlen(transport));
  strcpy(transport_copy, transport);
  this->transport = transport_copy;
}

Trajetsimple::Trajetsimple(const Trajetsimple & trajet): Trajetsimple(trajet.depart, trajet.arrivee, trajet.transport) {
  #ifdef MAP
      cout << "Appel au constructeur de copie de <Trajetsimple>" << endl;
  #endif
}

const Trajetsimple * Trajetsimple::copy() const {
  return new Trajetsimple(*this);
}

Trajetsimple::~Trajetsimple () {
  #ifdef MAP
      cout << "Appel au destructeur de <Trajetsimple>" << endl;
  #endif

  delete [] depart;
  delete [] arrivee;
  delete [] transport;
}


void Trajetsimple::Affichage() const {
  cout << GetStart() << " à " << GetEnd() << " en " << transport << endl;
}


const char* Trajetsimple::GetTransport() const{
  #ifdef MAP
      cout << "Appel au Get Transport du Trajet" << endl;
  #endif

  return transport;
}


const char* Trajetsimple::GetStart() const{
  #ifdef MAP
      cout << "Appel au Get Transport du Trajet" << endl;
  #endif

  return depart;
}


const char* Trajetsimple::GetEnd() const{
  #ifdef MAP
      cout << "Appel au Get Transport du Trajet" << endl;
  #endif

  return arrivee;
}
