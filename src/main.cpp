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

  ListeTrajets l;
  l.AddTrajet(t1);
  l.AddTrajet(t2);

  Trajetcompose tc(l);
  cout << tc.getStart() << " à " << tc.getEnd() << " avec " << tc.getNbTrajets()-1 << " correspondance" << endl;

  catalogue.AddTrajet(tc);

  cout << "Trajets : " << catalogue.GetNbTrajets() << endl;

  return 0;
}
