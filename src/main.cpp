#include <iostream>
#include <cstring>
using namespace std;

#include "../include/Trajet.h"
#include "../include/Trajetsimple.h"
#include "../include/ListeTrajets.h"
#include "../include/Catalogue.h"
#include "../include/Trajetcompose.h"

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

  catalogue.AddTrajet(Trajetsimple("Jouy", "Vernon", "Moto"));

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
        char depart[50], arrivee[50];

        cout << "Vous pouvez rechercher un trajet en renseignant la ville de départ et d'arrivée" << endl;
        cout << "Ville de départ : ";
        cin >> depart;
        cout << "Ville d'arrivée : ";
        cin >> arrivee;

        catalogue.SearchTrajets(depart, arrivee);
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

          char depart[50], arrivee[50], transport[50];
          Trajetcompose tc;
          switch (typeTrajet) {
            case 1:
              cout << "Veuillez remplir les informations suivantes :" << endl;
              cout << "Ville de départ : ";
              cin >> depart;
              cout << "Ville d'arrivée : ";
              cin >> arrivee;
              cout << "Moyen de transport : ";
              cin >> transport;

              catalogue.AddTrajet(Trajetsimple(depart, arrivee, transport));
              break;
            case 2:
              int nbTrajets;
              do {
                nbTrajets = 0;
                cout << "Combien d'étapes ce trajet comporte-t-il ?" << endl;
                cin >> nbTrajets;
                nbTrajets++;

                if (!cin) {
                  nbTrajets = 0;
                  cin.clear();
                  cin.ignore();
                }

                cout <<endl;

                if (nbTrajets <= 1)
                  cout << "Un trajet composé doit au moins comporter une étape." << endl;
              } while (nbTrajets <= 1);

              cout << "Veuillez remplir les informations suivantes :" << endl;
              for (int i=0; i<nbTrajets; i++) {
                if (i == 0) {
                  cout << "Ville de départ : ";
                  cin >> depart;
                }

                if (i == nbTrajets-1)
                  cout << "Ville d'arrivée : ";
                else
                  cout << "Ville à l'étape " << i+1 << " : ";
                cin >> arrivee;

                cout << "Moyen de transport sur cette étape : ";
                cin >> transport;

                tc.Add(Trajetsimple(depart, arrivee, transport));
                strcpy(depart, arrivee);
              }
              catalogue.AddTrajet(tc);

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
