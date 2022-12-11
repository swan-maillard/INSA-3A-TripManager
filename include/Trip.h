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

class Trip {

//----------------------------------------------------------------- PUBLIC
  public:
//----------------------------------------------------- Méthodes publiques
    Trip();
    virtual const Trip * Copy() const = 0;
    virtual void Display() const = 0;
    virtual const char* GetStartCity() const = 0;
    virtual const char* GetFinishCity() const = 0;
    virtual ~Trip();
};

#endif // TRIP_H
