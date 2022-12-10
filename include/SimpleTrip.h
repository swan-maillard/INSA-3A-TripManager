#if ! defined ( SIMPLE_TRIP_H )
#define SIMPLE_TRIP_H

#include "Trip.h"


class SimpleTrip : public Trip {

  public:
    SimpleTrip (const char* startCity, const char* finishCity, const char* transport);
    SimpleTrip(const SimpleTrip & trajet);
    const SimpleTrip * Copy() const;
    virtual ~SimpleTrip();
    void Display() const;
    const char* GetTransport() const;
    const char* GetStartCity() const;
    const char* GetFinishCity() const;

  protected:
    const char* startCity;
    const char* finishCity;
    const char* transport;

};

#endif // SIMPLE_TRIP_H
