#include <iostream>
using namespace std;

#include "Trajet.h"
#include "Trajetsimple.h"
#include "ListeTrajets.h"
#include "Trajetcompose.h"

int main() {

  char ville1[]="Marseille";
  char ville2[]="Lyon";
  char transport[]="MT1";

  Trajetsimple t(ville1, ville2, transport);
  Trajet trajet(ville1, ville2);
  Trajet trajet2("Lyon", "Paris");

  t.Afficher();
  ListeTrajets list;
Trajet trajet3("Paris","Evreux");

  list.AddTrajet(trajet);
  list.AddTrajet(trajet2);

  cout << "Départ : " << list.GetStart()->getTrajet()->getStart() << endl; //on récupère l'élément de dép de liste,puis son trajet, puis la ville de départ du traj
  cout << "Correspondances : " << list.GetSize() - 1 << endl;
  cout << "Arrivée : " << list.GetEnd()->getTrajet()->getEnd() << endl;

Trajet trajdep("Marseille","Paris");
Trajet trajdeux("Paris","Evreux");

ListeTrajets list2;

list2.AddTrajet(trajdep);
list2.AddTrajet(trajdeux);

Trajetcompose test("Marseille","Evreux",list2,2);

  char* gettest=t.getTransport();
  cout<<gettest << endl;
  return 0;
}
