#include <iostream>
using namespace std;

#include "Trajet.h"
#include "Trajetsimple.h"
#include "ListeTrajets.h"
#include "Catalogue.h"

#include "Trajetcompose.h"

int main() {

  Catalogue catalogue;

  cout << "Trajets : " << catalogue.GetNbTrajets() << endl;

  Trajetsimple t1("Paris", "Marseille", "voiture");
  Trajetsimple t2("Marseille", "Lyon", "bateau");

  catalogue.AddTrajet(t1);
  catalogue.AddTrajet(t2);

  cout << "Trajets : " << catalogue.GetNbTrajets() << endl;

  return 0;
}
