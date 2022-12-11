/*************************************************************************
    CompoundTrip  -  Trajets composés de plusieurs trajets simples
                             -------------------
    début                : 13/12/2022
    copyright            : (C) 2022 par MALARD Sarah & MAILLARD Swan
    e-mail               : sarah.malard@insa-lyon.fr & swan.maillard@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <CompoundTrip> (fichier CompoundTrip.h) ----------------
#if ! defined ( COMPOUND_TRIP_H )
#define COMPOUND_TRIP_H

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include "Trip.h"
#include "TripList.h"


class CompoundTrip : public Trip {

//----------------------------------------------------------------- PUBLIC
  public:
//----------------------------------------------------- Méthodes publiques
    CompoundTrip();
    CompoundTrip(const CompoundTrip & CompoundTrip);
    const CompoundTrip * Copy() const;
    void Display() const;
    const char* GetStartCity() const;
    const char* GetFinishCity() const;
    int GetTripsNumber() const;
    void AddTrip(const Trip & trip);
    virtual ~CompoundTrip();

//----------------------------------------------------------------- PRIVE
  protected:
//----------------------------------------------------- Attributs protégés
    TripList * tripList;

};


#endif // COMPOUND_TRIP_H
