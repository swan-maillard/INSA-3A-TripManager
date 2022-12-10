#if ! defined ( COMPOUND_TRIP_H )
#define COMPOUND_TRIP_H

#include "Trip.h"
#include "TripList.h"


class CompoundTrip : public Trip {

  public:
    CompoundTrip();
    CompoundTrip(const CompoundTrip & CompoundTrip);
    const CompoundTrip * Copy() const;
    void Display() const;
    const char* GetStartCity() const;
    const char* GetFinishCity() const;
    int GetTripsNumber() const;
    void AddTrip(const Trip & trip);
    virtual ~CompoundTrip();

  protected:
    TripList * tripList;

};


#endif // COMPOUND_TRIP_H
