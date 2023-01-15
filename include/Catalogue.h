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
#include <fstream>

//-------------------------------------------------------- Include personnel
#include "TripList.h"

struct loadSaveSettings {
  int type = 0;
  string startCity = "0";
  string finishCity = "0";
  int isInterval = 0;
  int minInterval = 0;
  int maxInterval = 0;
};

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

    // Charge les trajets depuis un fichier dans le catalogue
    void LoadFromFile(ifstream & file, loadSaveSettings & settings);

    // Sauvegarde les trajets du catalogue dans un fichier
    void SaveInFile(ofstream & file, loadSaveSettings & settings) const;


//----------------------------------------------------------------- PRIVE
  protected:
//----------------------------------------------------- Attributs protégés
    TripList * tripList;

};

#endif // CATALOGUE_H
