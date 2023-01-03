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
#include <string>
#include "Trip.h"
#include "TripList.h"


class CompoundTrip : public Trip {

//----------------------------------------------------------------- PUBLIC
  public:
//----------------------------------------------------- Méthodes publiques

    // Constructeur
    CompoundTrip();

    // Constructeur par copie
    CompoundTrip(const CompoundTrip & CompoundTrip);

    // Destructeur
    virtual ~CompoundTrip();

    // Renvoie une copie du trajet composé
    const CompoundTrip * Copy() const;

    // Affiche les trajets constituants le trajet composé
    void Display() const;

    // Renvoie la ville de départ du trajet composé
    const char* GetStartCity() const;

    // Renvoie la ville d'arrivée du trajet composé
    const char* GetFinishCity() const;

    // Renvoie le nombre de trajets constituants le trajet composé
    int GetTripsNumber() const;

    // Ajoute un trajet simple ou composé au trajet composé
    void AddTrip(const Trip & trip);

    const string ToFileFormat() const;


//----------------------------------------------------------------- PRIVE
  protected:
//----------------------------------------------------- Attributs protégés
    TripList * tripList;

};


#endif // COMPOUND_TRIP_H
