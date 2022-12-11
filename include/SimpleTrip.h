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

    // Constructeur
    // Prend en argument la ville de départ, d'arrivée et le moyen de transport
    SimpleTrip (const char* startCity, const char* finishCity, const char* transport);

    // Constructeur par copie
    SimpleTrip(const SimpleTrip & trajet);

    // Destructeur
    virtual ~SimpleTrip();

    // Renvoie une copie du trajet simple
    const SimpleTrip * Copy() const;

    // Affiche les attributs du trajet simple (ville de départ, d'arrivée et le moyen de transport)
    void Display() const;

    // Renvoie le moyen de transport du trajet
    const char* GetTransport() const;

    // Renvoie la ville de départ du trajet
    const char* GetStartCity() const;

    // Renvoie la ville d'arrivée du trajet
    const char* GetFinishCity() const;

//----------------------------------------------------------------- PRIVE
  protected:
//----------------------------------------------------- Attributs protégés
    const char* startCity;
    const char* finishCity;
    const char* transport;

};

#endif // SIMPLE_TRIP_H
