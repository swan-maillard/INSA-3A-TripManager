#include <iostream>
#include <cstring>
using namespace std;

#include "../include/Trip.h"
#include "../include/SimpleTrip.h"
#include "../include/TripList.h"
#include "../include/Catalogue.h"
#include "../include/CompoundTrip.h"

// A faire :
// - Recherche avancée
// - Formatage des string

void displayMenu(Catalogue * catalogue);
void displayCatalogue(Catalogue * catalogue);
void searchTrip(Catalogue * catalogue);
void addTrip(Catalogue * catalogue);
void addSimpleTrip(Catalogue * catalogue);
void addCompoundTrip(Catalogue * catalogue);

int main() {
  Catalogue catalogue;

  CompoundTrip tc1;
  tc1.AddTrip(SimpleTrip("Jouy", "Vernon", "Moto"));
  tc1.AddTrip(SimpleTrip("Vernon", "Evreux", "Moto"));

  catalogue.AddTrip(SimpleTrip("Jouy", "Vernon", "Moto"));
  catalogue.AddTrip(SimpleTrip("Vernon", "Evreux", "Voiture"));
  catalogue.AddTrip(tc1);


  displayMenu(&catalogue);

  return EXIT_SUCCESS;
}

void displayMenu(Catalogue * catalogue) {

  int choice;

  do {
    cout << "Grand Catalogue :" << endl;
    cout << " 1 - Afficher les trajets" << endl;
    cout << " 2 - Rechercher un trajet" << endl;
    cout << " 3 - Ajouter un trajet" << endl;
    cout << " 4 - Quitter" << endl;
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
      case 4: // Fin
        cout << "A bientôt dans notre grand catalogue !" << endl;
        break;
      default: // Erreur de saisie
        cout << "Veuillez choisir une option parmi celles proposées !" << endl;
    }

    cout << endl;

  } while (choice != 4);
}

void displayCatalogue(Catalogue * catalogue) {
  catalogue->Display();
}

void searchTrip(Catalogue * catalogue) {
  char startCity[50], finishCity[50];

  cout << "Vous pouvez rechercher un trajet en renseignant la ville de départ et d'arrivée" << endl;
  cout << "Ville de départ : ";
  cin >> startCity;
  cout << "Ville d'arrivée : ";
  cin >> finishCity;

  catalogue->SearchTrip(startCity, finishCity);
}

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