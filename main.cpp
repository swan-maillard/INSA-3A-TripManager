#include <iostream>
using namespace std;

#include "Trajet.h"
#include "Trajetsimple.h"
#include "ListeTrajets.h"


int main() {

  char ville1[]="Marseille";
  char ville2[]="Lyon";
  char transport[]="MT1";
  int nbtrajet=1;

  Trajetsimple t(ville1, ville2, transport);
  Trajet trajet(ville1, ville2);

  t.Afficher();

  ListeTrajets list;

  list.AddTrajet(trajet);

  cout << list.GetSize() << endl;


  char* gettest=t.getTransport();
  cout<<gettest << endl;
  return 0;
}
