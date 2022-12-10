#include <iostream>
#include <cstring>
using namespace std;

#include "../include/Trip.h"
#include "../include/SimpleTrip.h"
#include "../include/TripList.h"
#include "../include/Catalogue.h"
#include "../include/CompoundTrip.h"

// A faire :
// - Formatage des string
// - Renommer les méthodes / attributs
// - Réordonner le main

int main() {

  int choice;
  Catalogue catalogue;

  CompoundTrip tc1;
  tc1.AddTrip(SimpleTrip("Jouy", "Vernon", "Moto"));
  tc1.AddTrip(SimpleTrip("Vernon", "Evreux", "Moto"));

  catalogue.AddTrip(SimpleTrip("Jouy", "Vernon", "Moto"));
  catalogue.AddTrip(SimpleTrip("Vernon", "Evreux", "Voiture"));
  catalogue.AddTrip(tc1);

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
        catalogue.Display();
        break;
      case 2: // Recherche
        char startCity[50], finishCity[50];

        cout << "Vous pouvez rechercher un trajet en renseignant la ville de départ et d'arrivée" << endl;
        cout << "Ville de départ : ";
        cin >> startCity;
        cout << "Ville d'arrivée : ";
        cin >> finishCity;

        catalogue.SearchTrip(startCity, finishCity);
        break;
      case 3: // Ajout
        int typeTrip, loop;
        do {
          loop = 0;

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

          char startCity[50], finishCity[50], transport[50];
          CompoundTrip tc;
          switch (typeTrip) {
            case 1:
              cout << "Veuillez remplir les informations suivantes :" << endl;
              cout << "Ville de départ : ";
              cin >> startCity;
              cout << "Ville d'arrivée : ";
              cin >> finishCity;
              cout << "Moyen de transport : ";
              cin >> transport;

              catalogue.AddTrip(SimpleTrip(startCity, finishCity, transport));
              break;
            case 2:
              int nbTrips;
              do {
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
              } while (nbTrips <= 1);

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
              catalogue.AddTrip(tc);

              break;
            case 4:
              break;
            default:
              loop = 1;
              cout << "Veuillez choisir une option parmi celles proposées !" << endl;
          }

        } while (loop);

        break;
      case 4: // Fin
        cout << "A bientôt dans notre grand catalogue !" << endl;
        break;
      default: // Erreur de saisie
        cout << "Veuillez choisir une option parmi celles proposées !" << endl;
    }

    cout << endl;

  } while (choice != 4);

  return EXIT_SUCCESS;
}
