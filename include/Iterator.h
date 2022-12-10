#if ! defined (ITERATOR_H)
#define ITERATOR_H

#include "Iterator.h"
#include "ElementTripList.h"
#include "Trip.h"


class Iterator {

  public:
    Iterator(const ElementTripList * element);
    virtual ~Iterator();
    const Trip* Next();


  protected:
    const ElementTripList * currentElement;

};

#endif // ITERATOR_H
