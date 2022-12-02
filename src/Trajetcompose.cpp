using namespace std;

#include <iostream>
#include <cstring>

#include "../include/Trajetcompose.h"
#include "../include/ListeTrajets.h"


Trajetcompose::Trajetcompose(): Trajet() {
  #ifdef MAP
      cout << "Appel au constructeur de <Trajetcompose>" << endl;
  #endif

  trajets = new ListeTrajets();
}

Trajetcompose::Trajetcompose(const Trajetcompose & trajet): Trajet() {
  #ifdef MAP
      cout << "Appel au constructeur de copie de <Trajetcompose>" << endl;
  #endif

  trajets = trajet.trajets;
}

const Trajetcompose * Trajetcompose::copy() const {
  return new Trajetcompose(*this);
}

void Trajetcompose::Affichage() const{

  Iterator * trajetIterator = trajets->GetIterator();
  const Trajet * currentTrajet;
  cout << GetStart() << " à " << GetEnd() << " avec "  << GetNbTrajets() - 1 << " correspondances :" << endl;
  while((currentTrajet = trajetIterator->Next()) != NULL) {
    cout << "\t- ";
    currentTrajet->Affichage();
  }
  delete trajetIterator;
}


const char* Trajetcompose::GetStart() const{
  #ifdef MAP
      cout << "Appel au Get Transport du Trajet" << endl;
  #endif

  return trajets->GetFirstTrajet()->GetStart();
}


const char* Trajetcompose::GetEnd() const{
  #ifdef MAP
      cout << "Appel au Get Transport du Trajet" << endl;
  #endif

  return trajets->GetLastTrajet()->GetEnd();
}

int Trajetcompose::GetNbTrajets() const {
  #ifdef MAP
      cout << "Appel au Get Trajets du Trajet" << endl;
  #endif
  return trajets->GetSize();
}


void Trajetcompose::addTrajets(const Trajet & trajet) {
  #ifdef MAP
      cout << "Appel au AddTrajet du trajet composé" << endl;
  #endif

   this->trajets->AddTrajetQueue(trajet);
}


void Trajetcompose::Add(const Trajet & trajet){
  trajets->AddTrajetQueue(trajet);
}


Trajetcompose::~Trajetcompose() {
  #ifdef MAP
      cout << "Appel au destructeur de <Trajetcompose>" << endl;
  #endif

  delete trajets;
}
