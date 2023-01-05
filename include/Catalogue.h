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
#include <fstream>

class Catalogue {

//----------------------------------------------------------------- PUBLIC
  public:
//----------------------------------------------------- Méthodes publiques

    // Constructeur
    Catalogue();

    // Destructeur
    virtual ~Catalogue ();

    // Affiche les différents trajets du catalogue
    void Display() const;

    // Renvoie le nombre de trajets du catalogue
    int GetTripsNumber() const;

    // Ajoute un trajet au catalogue
    // L'ajout se fera alphabétiquement selon le nom de la ville d'arrivée
    void AddTrip(const Trip & trip);

    // Recherche un trajet avec le nom de la ville de départ et celle de fin
    void SearchTrip(const char * startCity, const char * finishCity);

    void LoadFromFile(ifstream & file, int type, string villedepart, string villearrivee, int n, int m);

    void SaveInFile(ofstream & file, int type, string villedepart, string villearrivee) const;


//----------------------------------------------------------------- PRIVE
  protected:
//----------------------------------------------------- Attributs protégés
    TripList * tripList;

};

#endif // CATALOGUE_H
