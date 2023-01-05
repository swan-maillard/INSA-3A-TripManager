/*************************************************************************
    CompoundTrip  -  Trajets composés de plusieurs trajets simples
                             -------------------
    début                : 13/12/2022
    copyright            : (C) 2022 par MALARD Sarah & MAILLARD Swan
    e-mail               : sarah.malard@insa-lyon.fr & swan.maillard@insa-lyon.fr
*************************************************************************/


//---------- Réalisation de la classe <CompoundTrip> (fichier CompoundTrip.cpp) ------------


//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
#include <string>

//-------------------------------------------------------- Include personnel
#include "../include/CompoundTrip.h"
#include "../include/TripList.h"


//----------------------------------------------------------------- PUBLIC

CompoundTrip::CompoundTrip(): Trip() {
  #ifdef MAP
      cout << "Construction de <CompoundTrip>" << endl;
  #endif

  tripList = NULL;
}

CompoundTrip::CompoundTrip(const CompoundTrip & compoundTrip): Trip() {
  #ifdef MAP
      cout << "Construction par copie de <CompoundTrip>" << endl;
  #endif

  tripList = (compoundTrip.tripList == NULL ? NULL : new TripList(*compoundTrip.tripList));
}

CompoundTrip::~CompoundTrip() {
  #ifdef MAP
      cout << "Destruction de <CompoundTrip>" << endl;
  #endif

  delete tripList;
}

const CompoundTrip * CompoundTrip::Copy() const {
  #ifdef MAP
      cout << "Exécution de Copy de <CompoundTrip>" << endl;
  #endif

  return new CompoundTrip(*this);
}

void CompoundTrip::Display() const{
  #ifdef MAP
      cout << "Exécution de Display de <CompoundTrip>" << endl;
  #endif

  if (tripList == NULL)
    return;

  Iterator * tripsIterator = tripList->CreateIterator();
  const Trip * currentTrip;

  cout << GetStartCity() << " à " << GetFinishCity() << " avec "  << GetTripsNumber() - 1 << " correspondances :" << endl;

  while((currentTrip = tripsIterator->Next()) != NULL) {
    cout << "\t- ";
    currentTrip->Display();
  }
  delete tripsIterator;
}


const char* CompoundTrip::GetStartCity() const{
  #ifdef MAP
      cout << "Exécution de GetStartCity de <CompoundTrip>" << endl;
  #endif

  if (tripList == NULL)
    return "";

  return tripList->GetFirstTrip()->GetStartCity();
}

const char* CompoundTrip::GetFinishCity() const{
  #ifdef MAP
      cout << "Exécution de GetFinishCity de <CompoundTrip>" << endl;
  #endif

  if (tripList == NULL)
    return "";

  return tripList->GetLastTrip()->GetFinishCity();
}

int CompoundTrip::GetTripsNumber() const {
  #ifdef MAP
      cout << "Exécution de GetTripsNumber de <CompoundTrip>" << endl;
  #endif

  if (tripList == NULL)
    return 0;

  return tripList->GetListSize();
}

void CompoundTrip::AddTrip(const Trip & trip){
  #ifdef MAP
      cout << "Exécution de AddTrip de <CompoundTrip>" << endl;
  #endif

  if (tripList == NULL)
    tripList = new TripList();

  tripList->AddTripInQueue(trip);
}

const string CompoundTrip::ToFileFormat() const{

  string tripFormated = "";

  if (tripList == NULL)
    return tripFormated;

  tripFormated += "COMPOUND;" + string(GetStartCity()) + ";" + string(GetFinishCity()) + ";\n";

  Iterator * tripsIterator = tripList->CreateIterator();
  const Trip * currentTrip;
  while((currentTrip = tripsIterator->Next()) != NULL) {
    tripFormated += currentTrip->ToFileFormat();
  }
  delete tripsIterator;

  tripFormated += "END_COMPOUND;\n";

  return tripFormated;
}

const int CompoundTrip::GetType() const{
  return 2;
}
