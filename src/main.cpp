#include <iostream>
using namespace std;

#include "Trajet.h"
#include "Trajetsimple.h"
#include "ListeTrajets.h"
#include "Catalogue.h"
#include "Trajetcompose.h"

int main() {

  int choice;

  do {
    cout << "Grand Catalogue :" << endl;
    cout << " 1 - Afficher les trajets" << endl;
    cout << " 2 - Rechercher un trajet" << endl;
    cout << " 3 - Ajouter un trajet" << endl;
    cout << " 4 - Quitter" << endl;
    cout << "Séléction : " << endl;
    cin >> choice;

    cout << endl;

    if (!cin) {
      choice = -1;
      cin.clear();
      cin.ignore();
    }

    switch (choice) {
      case 1:
        cout << "Affichage" << endl;
        break;
      case 2:
        cout << "Recherche" << endl;
        break;
      case 3:
        cout << "Ajoute" << endl;
        break;
      case 4:
        cout << "Au revoir :'('" << endl;
        break;
      default:
        cout << "Veuillez choisir une option parmi celles proposées !" << endl;
    }

    cout << endl;

  } while (choice != 4);



  return EXIT_SUCCESS;
}
