#include <iostream>
#include <cstring>
using namespace std;

#include "../include/Catalogue.h"
#include "../include/ListeTrajets.h"

Catalogue::Catalogue () {
  #ifdef MAP
      cout << "Appel au constructeur de <Catalogue>" << endl;
  #endif

  trajets = NULL;
}

void Catalogue::Afficher() const {
  if (trajets == NULL) {
    cout << "Notre catalogue est pour l'instant vide mais vous pouvez nous aider à le remplir !" << endl;
    return;
  }

  Iterator * trajetIterator = trajets->CreateIterator();
  const Trajet * currentTrajet;

  cout << "Notre catalogue propose " << GetNbTrajets() << " trajets :" << endl;

  while ((currentTrajet = trajetIterator->Next()) != NULL) {
    cout << "- ";
    currentTrajet->Affichage();
  }
  delete trajetIterator;
}

int Catalogue::GetNbTrajets() const {
  if (trajets == NULL)
    return 0;

  return trajets->GetSize();
}

void Catalogue::AddTrajet(const Trajet & trajet) {
  if (trajets == NULL)
    trajets = new ListeTrajets();

  trajets->AddTrajetAlpha(trajet);
}

void Catalogue::SearchTrajets(const char * depart, const char * arrivee) {
  if (trajets == NULL) {
    cout << "Le catalogue ne contient aucun trajet" << endl;
    return;
  }

  Iterator * iterator = trajets->CreateIterator();
  const Trajet * currentTrajet;
  ListeTrajets trajetsFound;

  while ((currentTrajet = iterator->Next()) != NULL) {
    if (strcmp(currentTrajet->GetStart(), depart) == 0 && strcmp(currentTrajet->GetEnd(), arrivee) == 0) {
      trajetsFound.AddTrajetQueue(*currentTrajet);
    }
  }
  delete iterator;


  if (trajetsFound.GetSize() == 0)
    cout << "Aucun trajet allant de " << depart << " à " << arrivee << " n'a été trouvé..." << endl;
  else
    cout << trajetsFound.GetSize() << " trajet(s) allant de " << depart << " à " << arrivee << " ont été trouvé(s) :" << endl;

  iterator = trajetsFound.CreateIterator();
  while ((currentTrajet = iterator->Next()) != NULL) {
    cout << "- ";
    currentTrajet->Affichage();
  }
  delete iterator;
}


Catalogue::~Catalogue () {
  #ifdef MAP
      cout << "Appel au destructeur de <Catalogue>" << endl;
  #endif

  delete trajets;
}
