/*************************************************************************
    Trip  -  Classe abstraite représentant un trajet pouvant être simple ou composé
                             -------------------
    début                : 13/12/2022
    copyright            : (C) 2022 par MALARD Sarah & MAILLARD Swan
    e-mail               : sarah.malard@insa-lyon.fr & swan.maillard@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Trip> (fichier Trip.h) ----------------
#if ! defined ( TRIP_H )
#define TRIP_H

#include <string>

class Trip {

//----------------------------------------------------------------- PUBLIC
  public:
//----------------------------------------------------- Méthodes publiques

    // Constructeur
    Trip();

    // Destructeur
    virtual ~Trip();

    // Renvoie une copie du trajet
    // Méthode abstraite
    virtual const Trip * Copy() const = 0;

    // Affiche les informations du trajet
    // Méthode abstraite
    virtual void Display() const = 0;

    // Renvoie la ville de départ du trajet
    // Méthode abstraite
    virtual const char* GetStartCity() const = 0;

    // Renvoie la ville d'arrivée du trajet
    // Méthode abstraite
    virtual const char* GetFinishCity() const = 0;

    virtual const string ToFileFormat() const = 0;
};

#endif // TRIP_H
