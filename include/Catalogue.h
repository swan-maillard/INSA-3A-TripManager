/*************************************************************************
    Catalogue  -  Contient des trajets et permet d'effectuer des actions (affichage, recherche, ajout)
                             -------------------
    début                : 13/12/2022
    copyright            : (C) 2022 par MALARD Sarah & MAILLARD Swan
    e-mail               : sarah.malard@insa-lyon.fr & swan.maillard@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include "TripList.h"

class Catalogue {

//----------------------------------------------------------------- PUBLIC
  public:
//----------------------------------------------------- Méthodes publiques
    Catalogue();
    void Display() const;
    int GetTripsNumber() const;
    void AddTrip(const Trip & trip);
    void SearchTrip(const char * startCity, const char * finishCity);
    virtual ~Catalogue ();

//----------------------------------------------------------------- PRIVE
  protected:
//----------------------------------------------------- Attributs protégés
    TripList * tripList;

};

#endif // CATALOGUE_H
