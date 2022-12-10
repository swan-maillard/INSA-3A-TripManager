using namespace std;

#include <iostream>
#include <cstring>

#include "../include/SimpleTrip.h"


SimpleTrip::SimpleTrip(const char* startCity, const char* finishCity, const char* transport): Trip() {
  #ifdef MAP
      cout << "Appel au constructeur de <SimpleTrip>" << endl;
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
      cout << "Appel au constructeur de copie de <SimpleTrip>" << endl;
  #endif
}

const SimpleTrip * SimpleTrip::Copy() const {
  return new SimpleTrip(*this);
}

SimpleTrip::~SimpleTrip () {
  #ifdef MAP
      cout << "Appel au destructeur de <SimpleTrip>" << endl;
  #endif

  delete [] startCity;
  delete [] finishCity;
  delete [] transport;
}


void SimpleTrip::Display() const {
  cout << startCity << " à " << finishCity << " en " << transport << endl;
}


const char* SimpleTrip::GetTransport() const{
  return transport;
}


const char* SimpleTrip::GetStartCity() const{
  return startCity;
}


const char* SimpleTrip::GetFinishCity() const{
  return finishCity;
}
