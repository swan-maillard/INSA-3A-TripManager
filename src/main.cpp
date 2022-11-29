#include <iostream>
using namespace std;

#include "Trajet.h"
#include "Trajetsimple.h"
#include "ListeTrajets.h"
#include "Catalogue.h"
#include "Trajetcompose.h"

int main() {

  int choice;
  Catalogue catalogue;
  Trajetsimple ts1("Annecy","Limoges","Voiture");
  Trajetsimple ts2("Brest","Carcassonne","Voiture");
  Trajetsimple ts3("Paris", "Epinal", "Bateau");
  Trajetsimple ts4("Epinal", "Carcassonne", "Avion");

  Trajetsimple sous1tc("Bron","Villeurbanne","Avion");
  Trajetsimple sous2tc("Villeurbanne","Cabourg","Bateau");

  ListeTrajets listetc1;
  listetc1.AddTrajetQueue(sous1tc);
  listetc1.AddTrajetQueue(sous2tc);
  Trajetcompose tc1(listetc1);

  Trajetsimple sous1tc2("Marseille","Toulon","Bateau");
  Trajetsimple sous2tc2("Toulon","Toulouse","Bateau");
  Trajetsimple sous3tc2("Toulouse","Aix-En-Provence","Voiture");

  ListeTrajets listetc2;
  listetc2.AddTrajetQueue(sous1tc2);
  listetc2.AddTrajetQueue(sous2tc2);
  listetc2.AddTrajetQueue(sous3tc2);
  Trajetcompose tc2(listetc2);

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
