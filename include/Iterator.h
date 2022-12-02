#if ! defined (ITERATOR_H)
#define ITERATOR_H

#include "Iterator.h"
#include "ElementListe.h"
#include "Trajet.h"


class Iterator {

  public:
    Iterator(const ElementListe * element);
    virtual ~Iterator();
    const Trajet * Next();


  protected:
    const ElementListe * currentElement;

};

#endif // ITERATOR_H
