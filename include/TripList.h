#if ! defined ( TRIP_LIST_H )
#define TRIP_LIST_H

#include "ElementTripList.h"
#include "Iterator.h"
#include "Trip.h"

class TripList {

  public:
    TripList();
    TripList(const TripList & tripList);
    virtual ~TripList();
    void AddTripInQueue(const Trip & trip);
    void AddTripAlpha(const Trip & trip);
    const Trip * GetFirstTrip() const;
    const Trip * GetLastTrip() const;
    int GetListSize() const;
    Iterator * CreateIterator() const;

  protected:
    ElementTripList * firstElem;
    ElementTripList * lastElem;
    int size;
};


#endif // TRIP_LIST_H
