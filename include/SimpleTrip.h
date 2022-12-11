/*************************************************************************
    SimpleTrip  -  Trajet simple allant d'une ville d'arrivée à une ville de 
                   départ avec un moyen de transport.
                   Cette classe hérite de Trip.
                             -------------------
    début                : 13/12/2022
    copyright            : (C) 2022 par MALARD Sarah & MAILLARD Swan
    e-mail               : sarah.malard@insa-lyon.fr & swan.maillard@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <SimpleTrip> (fichier SimpleTrip.h) ----------------
#if ! defined ( SIMPLE_TRIP_H )
#define SIMPLE_TRIP_H

#include "Trip.h"

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
class SimpleTrip : public Trip {

//----------------------------------------------------------------- PUBLIC
  public:
//----------------------------------------------------- Méthodes publiques
    SimpleTrip (const char* startCity, const char* finishCity, const char* transport);
    SimpleTrip(const SimpleTrip & trajet);
    const SimpleTrip * Copy() const;
    virtual ~SimpleTrip();
    void Display() const;
    const char* GetTransport() const;
    const char* GetStartCity() const;
    const char* GetFinishCity() const;

//----------------------------------------------------------------- PRIVE
  protected:
//----------------------------------------------------- Attributs protégés
    const char* startCity;
    const char* finishCity;
    const char* transport;

};

#endif // SIMPLE_TRIP_H
