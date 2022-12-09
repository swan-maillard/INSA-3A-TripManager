using namespace std;

#include <iostream>
#include <cstring>

#include "../include/Trajetcompose.h"
#include "../include/ListeTrajets.h"


Trajetcompose::Trajetcompose(): Trajet() {
  #ifdef MAP
      cout << "Appel au constructeur de <Trajetcompose>" << endl;
  #endif

  trajets = NULL;
}

Trajetcompose::Trajetcompose(const Trajetcompose & trajet): Trajet() {
  #ifdef MAP
      cout << "Appel au constructeur de copie de <Trajetcompose>" << endl;
  #endif

  trajets = (trajet.trajets == NULL ? NULL : new ListeTrajets(trajet.trajets));
}

const Trajetcompose * Trajetcompose::copy() const {
  return new Trajetcompose(*this);
}

void Trajetcompose::Affichage() const{
  if (trajets == NULL)
    return;

  Iterator * trajetIterator = trajets->CreateIterator();
  const Trajet * currentTrajet;

  cout << GetStart() << " à " << GetEnd() << " avec "  << GetNbTrajets() - 1 << " correspondances :" << endl;

  while((currentTrajet = trajetIterator->Next()) != NULL) {
    cout << "\t- ";
    currentTrajet->Affichage();
  }
  delete trajetIterator;
}


const char* Trajetcompose::GetStart() const{
  if (trajets == NULL)
    return NULL;

  return trajets->GetFirstTrajet()->GetStart();
}

const char* Trajetcompose::GetEnd() const{
  if (trajets == NULL)
    return NULL;

  return trajets->GetLastTrajet()->GetEnd();
}

int Trajetcompose::GetNbTrajets() const {
  if (trajets == NULL)
    return 0;

  return trajets->GetSize();
}

void Trajetcompose::Add(const Trajet & trajet){
  if (trajets == NULL)
    trajets = new ListeTrajets();

  trajets->AddTrajetQueue(trajet);
}


Trajetcompose::~Trajetcompose() {
  #ifdef MAP
      cout << "Appel au destructeur de <Trajetcompose>" << endl;
  #endif

  delete trajets;
}
