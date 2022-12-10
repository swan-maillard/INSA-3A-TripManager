#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

#include "TripList.h"


class Catalogue {

  public:
    Catalogue();
    void Display() const;
    int GetTripsNumber() const;
    void AddTrip(const Trip & trip);
    void SearchTrip(const char * tripStart, const char * tripFinish);
    virtual ~Catalogue ();

  protected:
    TripList * tripList;

};

#endif // CATALOGUE_H
