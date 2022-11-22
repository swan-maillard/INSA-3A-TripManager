#include <iostream>
using namespace std;

#include "Trajet.h"
#include "Trajetsimple.h"


int main() {

  char ville1[]="Marseille";
  char ville2[]="Lyon";
  char transport[]="MT1";

  Trajetsimple t(ville1, ville2, transport);

  t.Afficher();

  char* gettest=t.getTransport();
  cout<<gettest;
  return 0;
}


// Trajet (depart, arrivée)
//  -> TrajetSimple (transport)
//  -> TrajetComposé (nbTrajets, listeTrajets[TrajetSimple])
