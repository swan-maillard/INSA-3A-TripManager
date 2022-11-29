#include <iostream>
using namespace std;

#include "Trajet.h"
#include "Trajetsimple.h"
#include "ListeTrajets.h"
#include "Catalogue.h"
#include "Trajetcompose.h"

int main() {

  int choice;
  Catalogue test;
  Trajetsimple ts1("As","Bs","MT1");
  Trajetsimple ts2("Bs","Cs","MT1");

  Trajetsimple sous1tc("Bc","Yc","MT3");
  Trajetsimple sous2tc("Yc","Cc","MT2");

  ListeTrajets listetc1;
  listetc1.AddTrajetQueue(sous1tc);
  listetc1.AddTrajetQueue(sous2tc);
  Trajetcompose tc1(listetc1);

  Trajetsimple sous1tc2("Uc","ZC","MT2");
  Trajetsimple sous2tc2("Zc","Dc","MT1");

  ListeTrajets listetc2;
  listetc2.AddTrajetQueue(sous1tc2);
  listetc2.AddTrajetQueue(sous2tc2);
  Trajetcompose tc2(listetc2);

  test.AddTrajet(ts2);
  test.AddTrajet(tc1);
  test.AddTrajet(ts1);
  test.AddTrajet(tc2);


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

    ElementListe* currentElement = test.GetTrajets()->GetStart();


    switch (choice) {
      case 1:
        cout << "Affichage" << endl;
        cout << test.GetNbTrajets() << endl;
        while(currentElement!=NULL){
          currentElement->getTrajet()->Affichage();
          currentElement=currentElement->getNext();
        }

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
