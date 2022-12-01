#include <iostream>
using namespace std;

#include "Trajet.h"
#include "Trajetsimple.h"
#include "ListeTrajets.h"
#include "Catalogue.h"
#include "Trajetcompose.h"

// A faire :
// - Ajout d'un trajet composé
// - Formatage des string
// - Recherche d'un trajet
// - Renommer les méthodes / attributs
// - Réordonner le main
// - Revoir tous les const

int main() {

  int choice;
  Catalogue catalogue;
  Trajetsimple ts1("Annecy","Limoges","Voiture");
  Trajetsimple ts2("Brest","Carcassonne","Voiture");
  Trajetsimple ts3("Paris", "Epinal", "Bateau");
  Trajetsimple ts4("Epinal", "Carcassonne", "Avion");

  Trajetsimple sous1tc("Bron","Villeurbanne","Avion");
  Trajetsimple sous2tc("Villeurbanne","Cabourg","Bateau");

  Trajetcompose tc1;
  tc1.Add(sous1tc);
  tc1.Add(sous2tc);


  Trajetsimple sous1tc2("Marseille","Toulon","Bateau");
  Trajetsimple sous2tc2("Toulon","Toulouse","Bateau");
  Trajetsimple sous3tc2("Toulouse","Aix-En-Provence","Voiture");

  Trajetcompose tc2;
  tc2.Add(sous1tc2);
  tc2.Add(sous2tc2);
  tc2.Add(sous3tc2);

  catalogue.AddTrajet(ts1);
  catalogue.AddTrajet(ts2);
  catalogue.AddTrajet(ts3);
  catalogue.AddTrajet(ts4);
  catalogue.AddTrajet(tc1);
  catalogue.AddTrajet(tc2);


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
        catalogue.Afficher();
        break;
      case 2: // Recherche
        break;
      case 3: // Ajout
        int typeTrajet, loop;
        do {
          loop = 0;

          cout << "Quel type de trajet souhaitez-vous ajouter ?" << endl;
          cout << " 1 - Trajet simple" << endl;
          cout << " 2 - Trajet composé" << endl;
          cout << " 3 - Revenir" << endl;
          cin >> typeTrajet;

          if (!cin) {
            typeTrajet = -1;
            cin.clear();
            cin.ignore();
          }

          cout << endl;

          Trajetsimple * ts[100];

          switch (typeTrajet) {
            case 1:
              char depart[50], arrivee[50], transport[50];
              cout << "Veuillez remplir les informations suivantes :" << endl;
              cout << "Ville de départ : ";
              cin >> depart;
              cout << "Ville d'arrivée : ";
              cin >> arrivee;
              cout << "Moyen de transport : ";
              cin >> transport;

              ts[0] = new Trajetsimple(depart, arrivee, transport);
              catalogue.AddTrajet(*ts[0]);
              break;
            case 2:
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
