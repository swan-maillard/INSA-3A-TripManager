using namespace std;

#include <iostream>
#include <cstring>

#include "../include/CompoundTrip.h"
#include "../include/TripList.h"


CompoundTrip::CompoundTrip(): Trip() {
  #ifdef MAP
      cout << "Appel au constructeur de <CompoundTrip>" << endl;
  #endif

  tripList = NULL;
}

CompoundTrip::CompoundTrip(const CompoundTrip & compoundTrip): Trip() {
  #ifdef MAP
      cout << "Appel au constructeur de copie de <CompoundTrip>" << endl;
  #endif

  tripList = (compoundTrip.tripList == NULL ? NULL : new TripList(*compoundTrip.tripList));
}

const CompoundTrip * CompoundTrip::Copy() const {
  return new CompoundTrip(*this);
}

void CompoundTrip::Display() const{
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
  if (tripList == NULL)
    return "";

  return tripList->GetFirstTrip()->GetStartCity();
}

const char* CompoundTrip::GetFinishCity() const{
  if (tripList == NULL)
    return "";

  return tripList->GetLastTrip()->GetFinishCity();
}

int CompoundTrip::GetTripsNumber() const {
  if (tripList == NULL)
    return 0;

  return tripList->GetListSize();
}

void CompoundTrip::AddTrip(const Trip & trip){
  if (tripList == NULL)
    tripList = new TripList();

  tripList->AddTripInQueue(trip);
}


CompoundTrip::~CompoundTrip() {
  #ifdef MAP
      cout << "Appel au destructeur de <CompoundTrip>" << endl;
  #endif

  delete tripList;
}
