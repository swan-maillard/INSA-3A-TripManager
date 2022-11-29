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
  Trajetsimple trajetsimple("A","B","MT1");
  Trajetsimple ts2("B","C","MT1");

  Trajetsimple sous1tc("B","Y","MT3");
  Trajetsimple sous2tc("Y","C","MT2");

  ListeTrajets listetc1;
  listetc1.AddTrajet(sous1tc);
  listetc1.AddTrajet(sous2tc);
  Trajetcompose trajetcompose(listetc1);

  Trajetsimple sous1tc2("A","Z","MT2");
  Trajetsimple sous2tc2("Z","C","MT1");

  ListeTrajets listetc2;
  listetc2.AddTrajet(sous1tc2);
  listetc2.AddTrajet(sous2tc2);
  Trajetcompose tc2(listetc2);

  ElementListe* currentElement = trajetcompose.getTrajets()->GetStart(); //pour les trajets composés après



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
        /*ElementListe * currentElement = start;
        while (currentElement != NULL) {
          ElementListe * next = currentElement->getNext();
          delete currentElement;
          currentElement = next;*/

          //Trajet simple
          cout << "Trajet de " << trajetsimple.getStart() << " à " << trajetsimple.getEnd() << " en " << trajetsimple.getTransport()<<endl;

          //Trajet Trajetcompose
          cout<<"Trajet de ";
          while(currentElement!=NULL){
            cout<<currentElement->getTrajet()->getStart()<<" à "<<currentElement->getTrajet()->getEnd()<<" en "<<currentElement->getTrajet()->getTransport();
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
