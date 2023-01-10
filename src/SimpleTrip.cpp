/*************************************************************************
    SimpleTrip  -  Trajet simple allant d'une ville d'arrivée à une ville de
                   départ avec un moyen de transport.
                   Cette classe hérite de Trip.
                             -------------------
    début                : 13/12/2022
    copyright            : (C) 2022 par MALARD Sarah & MAILLARD Swan
    e-mail               : sarah.malard@insa-lyon.fr & swan.maillard@insa-lyon.fr
*************************************************************************/


//---------- Réalisation de la classe <SimpleTrip> (fichier SimpleTrip.cpp) ------------


//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
#include <string>

//-------------------------------------------------------- Include personnel
#include "../include/SimpleTrip.h"


//----------------------------------------------------------------- PUBLIC

SimpleTrip::SimpleTrip(const char* startCity, const char* finishCity, const char* transport): Trip() {
  #ifdef MAP
      cout << "Construction de <SimpleTrip>" << endl;
  #endif

  char * startCityCopy= new char(strlen(startCity) + 1);
  strcpy(startCityCopy, startCity);
  this->startCity = startCityCopy;

  char * finishCityCopy = new char(strlen(finishCity) + 1);
  strcpy(finishCityCopy, finishCity);
  this->finishCity = finishCityCopy;

  char * transport_copy = new char(strlen(transport) + 1);
  strcpy(transport_copy, transport);
  this->transport = transport_copy;
}

SimpleTrip::SimpleTrip(const SimpleTrip & simpleTrip): SimpleTrip(simpleTrip.startCity, simpleTrip.finishCity, simpleTrip.transport) {
  #ifdef MAP
      cout << "Construction par copie de <SimpleTrip>" << endl;
  #endif
}

const SimpleTrip * SimpleTrip::Copy() const {
  return new SimpleTrip(*this);
}

SimpleTrip::~SimpleTrip () {
  #ifdef MAP
      cout << "Destruction de <SimpleTrip>" << endl;
  #endif

  delete [] startCity;
  delete [] finishCity;
  delete [] transport;
}


void SimpleTrip::Display() const {
  #ifdef MAP
      cout << "Exécution de Display de <SimpleTrip>" << endl;
  #endif

  cout << startCity << " à " << finishCity << " en " << transport << endl;
}


const char* SimpleTrip::GetTransport() const {
  #ifdef MAP
      cout << "Exécution de GetTransport de <SimpleTrip>" << endl;
  #endif

  return transport;
}


const char* SimpleTrip::GetStartCity() const {
  #ifdef MAP
      cout << "Exécution de GetStartCity de <SimpleTrip>" << endl;
  #endif

  return startCity;
}


const char* SimpleTrip::GetFinishCity() const {
  #ifdef MAP
      cout << "Exécution de GetFinishCity de <SimpleTrip>" << endl;
  #endif

  return finishCity;
}


const string SimpleTrip::ToFileFormat() const {
  #ifdef MAP
      cout << "Exécution de ToFileFormat de <SimpleTrip>" << endl;
  #endif

  return (string(startCity) + ";" + string(finishCity) + ";" + string(transport) + ";\n");
}

const string SimpleTrip::GetClass() const{
  return "SimpleTrip";
}
