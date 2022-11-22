#include <iostream>
using namespace std;

#include "Trajet.h"
#include "Trajetsimple.h"


int main() {

  Trajet t1();
  char ville1[]="Marseille";
  char ville2[]="Lyon";
  char transport[]="MT1";
  Trajetsimple t2(ville1,ville2, transport);

  return 0;
}


// Trajet (depart, arrivée)
//  -> TrajetSimple (transport)
//  -> TrajetComposé (nbTrajets, listeTrajets[TrajetSimple])
