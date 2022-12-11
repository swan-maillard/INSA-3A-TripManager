/*************************************************************************
    Iterator  -  Permet d'itérer sur les maillons des listes chainées TripList
                             -------------------
    début                : 13/12/2022
    copyright            : (C) 2022 par MALARD Sarah & MAILLARD Swan
    e-mail               : sarah.malard@insa-lyon.fr & swan.maillard@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Iterator> (fichier Iterator.h) ----------------
#if ! defined (ITERATOR_H)
#define ITERATOR_H

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include "Iterator.h"
#include "ElementTripList.h"
#include "Trip.h"


class Iterator {

//----------------------------------------------------------------- PUBLIC
  public:
//----------------------------------------------------- Méthodes publiques
    Iterator(const ElementTripList * element);
    virtual ~Iterator();
    const Trip* Next();


//----------------------------------------------------------------- PRIVE
  protected:
//----------------------------------------------------- Attributs protégés
    const ElementTripList * currentElement;

};

#endif // ITERATOR_H
