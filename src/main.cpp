/*************************************************************************
    OUI.SNC++ : Vos trajets n'ont jamais été aussi simples !

    Fichier principal de l'application, gère l'affichage des différents menus.
                             -------------------
    début                : 13/12/2022
    copyright            : (C) 2022 par MALARD Sarah & MAILLARD Swan
    e-mail               : sarah.malard@insa-lyon.fr & swan.maillard@insa-lyon.fr
*************************************************************************/


//---------------------- Fichier main.cpp ------------------------


//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
//-------------------------------------------------------- Include personnel
#include "../include/Trip.h"
#include "../include/SimpleTrip.h"
#include "../include/TripList.h"
#include "../include/Catalogue.h"
#include "../include/CompoundTrip.h"



void displayMenu(Catalogue * catalogue);
void displayCatalogue(Catalogue * catalogue);
void searchTrip(Catalogue * catalogue);
void addTrip(Catalogue * catalogue);
void addSimpleTrip(Catalogue * catalogue);
void addCompoundTrip(Catalogue * catalogue);
void load(Catalogue * catalogue);
void save(Catalogue * catalogue);
loadSaveSettings askForSettings();

// Fonction principale
int main() {
  Catalogue catalogue;
  displayMenu(&catalogue);

  return EXIT_SUCCESS;
}

// Affiche le menu principal
void displayMenu(Catalogue * catalogue) {

  int choice;

  do {
    cout << "Grand Catalogue :" << endl;
    cout << " 1 - Afficher les trajets" << endl;
    cout << " 2 - Rechercher un trajet" << endl;
    cout << " 3 - Ajouter un trajet" << endl;
    cout << " 4 - Charger un fichier" <<endl;
    cout << " 5 - Sauvegarder dans un fichier" <<endl;
    cout << " 6 - Quitter" << endl;
    cin >> choice;

    cout << endl;

    if (!cin) {
      choice = -1;
      cin.clear();
      cin.ignore();
    }

    switch (choice) {
      case 1: // Affichage
        displayCatalogue(catalogue);
        break;
      case 2: // Recherche simple
        searchTrip(catalogue);
        break;
      case 3: // Ajout
        addTrip(catalogue);
        break;
      case 4: // Chargement du catalogue depuis un fichier
        load(catalogue);
        break;
      case 5: // Sauvegarde du catalogue dans un fichier
        save(catalogue);
        break;
      case 6: // Fin
        cout << "A bientôt dans notre grand catalogue !" << endl;
        break;
      default: // Erreur de saisie
        cout << "Veuillez choisir une option parmi celles proposées !" << endl;
    }

    cout << endl;

  } while (choice != 4);
}

// Affiche le contenu du catalogue
void displayCatalogue(Catalogue * catalogue) {
  catalogue->Display();
}

// Recherche un trajet en fonction du nom de la ville de départ et d'arrivée
void searchTrip(Catalogue * catalogue) {
  char startCity[50], finishCity[50];

  cout << "Vous pouvez rechercher un trajet en renseignant la ville de départ et d'arrivée" << endl;
  cout << "Ville de départ : ";
  cin >> startCity;
  cout << "Ville d'arrivée : ";
  cin >> finishCity;

  catalogue->SearchTrip(startCity, finishCity);
}

// Permet de choisir si l'utilisateur souhaite ajouter un trajet simple ou composé
void addTrip(Catalogue * catalogue) {
  int typeTrip;
  bool loop;

  do {
    loop = false;

    cout << "Quel type de trajet souhaitez-vous ajouter ?" << endl;
    cout << " 1 - Trajet simple" << endl;
    cout << " 2 - Trajet composé" << endl;
    cout << " 3 - Revenir" << endl;
    cin >> typeTrip;

    if (!cin) {
      typeTrip = -1;
      cin.clear();
      cin.ignore();
    }

    cout << endl;

    switch (typeTrip) {
      case 1:
        addSimpleTrip(catalogue);
        break;
      case 2:
        addCompoundTrip(catalogue);
        break;
      case 3:
        break;
      default:
        loop = true;
        cout << "Veuillez choisir une option parmi celles proposées !" << endl;
    }

  } while (loop);
}

// Ajoute un trajet simple
void addSimpleTrip(Catalogue * catalogue) {
  char startCity[50], finishCity[50], transport[50];

  cout << "Veuillez remplir les informations suivantes :" << endl;
  cout << "Ville de départ : ";
  cin >> startCity;
  cout << "Ville d'arrivée : ";
  cin >> finishCity;
  cout << "Moyen de transport : ";
  cin >> transport;

  catalogue->AddTrip(SimpleTrip(startCity, finishCity, transport));
}

// Ajoute un trajet composé
void addCompoundTrip(Catalogue * catalogue) {
  char startCity[50], finishCity[50], transport[50];

  CompoundTrip tc;
  int nbTrips = 0;
  while (nbTrips <= 1) {
    nbTrips = 0;

    cout << "Combien d'étapes ce trajet comporte-t-il ?" << endl;
    cin >> nbTrips;

    nbTrips++;

    if (!cin) {
      nbTrips = 0;
      cin.clear();
      cin.ignore();
    }

    cout <<endl;

    if (nbTrips <= 1)
      cout << "Un trajet composé doit au moins comporter une étape." << endl;
  }

  cout << "Veuillez remplir les informations suivantes :" << endl;
  for (int i=0; i<nbTrips; i++) {
    if (i == 0) {
      cout << "Ville de départ : ";
      cin >> startCity;
    }

    if (i == nbTrips-1)
      cout << "Ville d'arrivée : ";
    else
      cout << "Ville à l'étape " << i+1 << " : ";

    cin >> finishCity;

    cout << "Moyen de transport sur cette étape : ";
    cin >> transport;

    tc.AddTrip(SimpleTrip(startCity, finishCity, transport));
    strcpy(startCity, finishCity);
  }
  catalogue->AddTrip(tc);
}


void load(Catalogue * catalogue) {
  ifstream stream;
  string file;
  loadSaveSettings settings;

  cout << "Quel fichier souhaitez-vous récupérer ?" << endl;
  cin >> file;

  stream.open(file);
  if (!stream) {
    cout << "ERREUR : Le fichier `" << file << "` est introuvable." << endl;
    return;
  }

  settings = askForSettings();

  catalogue->LoadFromFile(stream, settings);
}

void save(Catalogue* catalogue){
  ofstream stream;
  string file;
  loadSaveSettings settings;

  cout << "Dans quel fichier souhaitez-vous sauvegarder le catalogue ?" << endl;
  cin >> file;

  stream.open(file);
  if (!stream) {
    cout << "ERREUR : Le fichier `" << file << "` est introuvable." << endl;
    return;
  }

  settings = askForSettings();

  catalogue->SaveInFile(stream, settings);
}

loadSaveSettings askForSettings() {
  loadSaveSettings settings;
  bool error;

  do {
    error = false;

    cout << "Souhaitez-vous préciser un type de trajet ?" << endl;
    cout << " 0 : Non" << endl;
    cout << " 1 : Trajets Simples seulement" << endl;
    cout << " 2 : Trajets Composés seulement" << endl;
    cin >> settings.type;

    if (!cin || settings.type < 0 || settings.type > 2) {
      error = true;
      cout << "Le type de trajet ne peut prendre que les valeurs 0, 1 ou 2." << endl;

      if (!cin) {
        cin.clear();
        cin.ignore();
      }
    }
  } while (error);
  

  cout << "Souhaitez-vous préciser une ville de départ ? (0 si non)" << endl;
  cin >> settings.startCity;

  cout << "Souhaitez-vous préciser une ville d'arrivée ? (0 si non)" << endl;
  cin >> settings.finishCity;

  do {
    error = false;
    cout << "Souhaitez-vous préciser un intervalle de trajets à récupérer ?" << endl;
    cout << " 0 : Non" << endl;
    cout << " 1 : Oui" << endl;
    cin >> settings.isInterval;

    if (!cin || settings.isInterval < 0 || settings.isInterval > 1) {
      error = true;
      cout << "Les réponses attendues sont : 0 ou 1." << endl;

      if (!cin) {
        cin.clear();
        cin.ignore();
      }
    }
  } while (error);
  

  if (settings.isInterval) {

    do {
      error = false;
      cout << "Indice du premier trajet à récupérer (les trajets sont comptés à partir de 0) :" << endl;
      cin >> settings.minInterval;

      if (!cin || settings.minInterval < 0) {
        error = true;
        cout << "L'indice du premier trajet à récupérer ne peut pas être inférieur à 0." << endl;

        if (!cin) {
          cin.clear();
          cin.ignore();
        }
      }
    } while (error);
    
    do {
      error = false;
      cout << "Indice du dernier trajet à récupérer (les trajets sont comptés à partir de 0) :" << endl;
      cin >> settings.maxInterval;

      if (!cin || settings.maxInterval < settings.minInterval) {
        error = true;
        cout << "L'indice du dernier trajet à récupérer ne peut pas être inférieur à celui du premier trajet." << endl;

        if (!cin) {
          cin.clear();
          cin.ignore();
        }
      }

    } while (error);
  }

  return settings;
}