#if ! defined ( ELEMENT_TRIP_LIST )
#define ELEMENT_TRIP_LIST

#include "Trip.h"

class ElementTripList {

  public:
    ElementTripList(const Trip & trip);
    ElementTripList(const ElementTripList & element);
    void AddNext(ElementTripList * element);
    const Trip* GetTrip() const;
    ElementTripList* GetNext() const;
    virtual ~ElementTripList ();

  protected:
    const Trip * trip;
    ElementTripList * next;

};

#endif // ELEMENT_TRIP_LIST
