#include <iostream>
#include <cstring>
using namespace std;

#include "../include/Catalogue.h"
#include "../include/TripList.h"

Catalogue::Catalogue () {
  #ifdef MAP
      cout << "Appel au constructeur de <Catalogue>" << endl;
  #endif

  tripList = NULL;
}

void Catalogue::Display() const {
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
  if (tripList == NULL)
    return 0;

  return tripList->GetListSize();
}

void Catalogue::AddTrip(const Trip & trip) {
  if (tripList == NULL)
    tripList = new TripList();

  tripList->AddTripAlpha(trip);
}

void Catalogue::SearchTrip(const char * startCity, const char * finishCity) {
  if (tripList == NULL) {
    cout << "Le catalogue ne contient aucun trajet" << endl;
    return;
  }

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

  tripsIterator = foundTrips.CreateIterator();
  while ((currentTrip = tripsIterator->Next()) != NULL) {
    cout << "- ";
    currentTrip->Display();
  }
  delete tripsIterator;
}


Catalogue::~Catalogue () {
  #ifdef MAP
      cout << "Appel au destructeur de <Catalogue>" << endl;
  #endif

  delete tripList;
}
