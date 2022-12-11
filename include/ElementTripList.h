/*************************************************************************
    ElementTripList  -  Maillon de la liste chainée TripList, contenant un trajet
                             -------------------
    début                : 13/12/2022
    copyright            : (C) 2022 par MALARD Sarah & MAILLARD Swan
    e-mail               : sarah.malard@insa-lyon.fr & swan.maillard@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <ElementTripList> (fichier ElementTripList.h) ----------------
#if ! defined ( ELEMENT_TRIP_LIST )
#define ELEMENT_TRIP_LIST

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include "Trip.h"

class ElementTripList {

//----------------------------------------------------------------- PUBLIC
  public:
//----------------------------------------------------- Méthodes publiques
    ElementTripList(const Trip & trip);
    ElementTripList(const ElementTripList & element);
    void AddNext(ElementTripList * element);
    const Trip* GetTrip() const;
    ElementTripList* GetNext() const;
    virtual ~ElementTripList ();

//----------------------------------------------------------------- PRIVE
  protected:
//----------------------------------------------------- Attributs protégés
    const Trip * trip;
    ElementTripList * next;

};

#endif // ELEMENT_TRIP_LIST
