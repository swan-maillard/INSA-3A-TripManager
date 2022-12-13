/*************************************************************************
    Catalogue  -  Contient des trajets et permet d'effectuer des actions (affichage, recherche, ajout)
                             -------------------
    début                : 13/12/2022
    copyright            : (C) 2022 par MALARD Sarah & MAILLARD Swan
    e-mail               : sarah.malard@insa-lyon.fr & swan.maillard@insa-lyon.fr
*************************************************************************/


//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------


//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "../include/Catalogue.h"
#include "../include/TripList.h"


//----------------------------------------------------------------- PUBLIC

Catalogue::Catalogue () {
  #ifdef MAP
      cout << "Construction de <Catalogue>" << endl;
  #endif

  tripList = NULL;
}

Catalogue::~Catalogue () {
  #ifdef MAP
      cout << "Destruction de <Catalogue>" << endl;
  #endif

  delete tripList;
}

void Catalogue::Display() const {
  #ifdef MAP
      cout << "Exécution de Display de <Catalogue>" << endl;
  #endif

  if (tripList == NULL) {
    cout << "Notre catalogue est pour l'instant vide mais vous pouvez nous aider à le remplir !" << endl;
    return;
  }

  Iterator * tripsIterator = tripList->CreateIterator();
  const Trip * currentTrip;

  cout << "Notre catalogue propose " << GetTripsNumber() << " trajets :" << endl;

  while ((currentTrip = tripsIterator->Next()) != NULL) {
    cout << "- ";
    currentTrip->Display();
  }
  delete tripsIterator;
}

int Catalogue::GetTripsNumber() const {
  #ifdef MAP
    cout << "Exécution de GetTripsNumber de <Catalogue>" << endl;
  #endif

  if (tripList == NULL)
    return 0;

  return tripList->GetListSize();
}

void Catalogue::AddTrip(const Trip & trip) {
  #ifdef MAP
      cout << "Exécution de AddTrip de <Catalogue>" << endl;
  #endif

  if (tripList == NULL)
    tripList = new TripList();

  tripList->AddTripAlpha(trip);
}

void Catalogue::SearchTrip(const char * startCity, const char * finishCity) {
  #ifdef MAP
      cout << "Exécution de SearchTrip de <Catalogue>" << endl;
  #endif

  if (tripList == NULL) {
    cout << "Le catalogue ne contient aucun trajet" << endl;
    return;
  }

  // On itère sur les trajets du catalogue et on stocke ceux qui correspondent à la recherche dans foundTrips
  Iterator * tripsIterator = tripList->CreateIterator();
  const Trip * currentTrip;
  TripList foundTrips;
  while ((currentTrip = tripsIterator->Next()) != NULL) {
    if (strcmp(currentTrip->GetStartCity(), startCity) == 0 && strcmp(currentTrip->GetFinishCity(), finishCity) == 0) {
      foundTrips.AddTripInQueue(*currentTrip);
    }
  }
  delete tripsIterator;

  if (foundTrips.GetListSize() == 0)
    cout << "Aucun trajet allant de " << startCity << " à " << finishCity << " n'a été trouvé..." << endl;
  else if (foundTrips.GetListSize() == 1)
    cout << "1 trajet allant de " << startCity << " à " << finishCity << " a été trouvé :" << endl;
  else
    cout << foundTrips.GetListSize() << " trajets allant de " << startCity << " à " << finishCity << " ont été trouvés :" << endl;

  // On itère sur foundTrips (trajets correspondant à la recherche) et on les affiche
  tripsIterator = foundTrips.CreateIterator();
  while ((currentTrip = tripsIterator->Next()) != NULL) {
    cout << "- ";
    currentTrip->Display();
  }
  delete tripsIterator;
}

