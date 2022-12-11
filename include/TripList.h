/*************************************************************************
    TripList  -  Liste chainée contenant des trajets.
                 Ses maillons sont de type ElementTripList
                             -------------------
    début                : 13/12/2022
    copyright            : (C) 2022 par MALARD Sarah & MAILLARD Swan
    e-mail               : sarah.malard@insa-lyon.fr & swan.maillard@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TripList> (fichier TripList.h) ----------------
#if ! defined ( TRIP_LIST_H )
#define TRIP_LIST_H

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include "ElementTripList.h"
#include "Iterator.h"
#include "Trip.h"

class TripList {

//----------------------------------------------------------------- PUBLIC
  public:
//----------------------------------------------------- Méthodes publiques
    TripList();
    TripList(const TripList & tripList);
    virtual ~TripList();
    void AddTripInQueue(const Trip & trip);
    void AddTripAlpha(const Trip & trip);
    const Trip * GetFirstTrip() const;
    const Trip * GetLastTrip() const;
    int GetListSize() const;
    Iterator * CreateIterator() const;

//----------------------------------------------------------------- PRIVE
  protected:
//----------------------------------------------------- Attributs protégés
    ElementTripList * firstElem;
    ElementTripList * lastElem;
    int size;
};


#endif // TRIP_LIST_H
