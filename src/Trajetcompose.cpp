/*************************************************************************
                           Trajetcompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Trajetcompose> (fichier Trajetcompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel

#include "../include/Trajetcompose.h"
#include "../include/ListeTrajets.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Trajetcompose::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Trajetcompose::Affichage() const{

  Iterator * trajetIterator = trajets->GetIterator();
  Trajet * currentTrajet;
  cout << getStart() << " à " << getEnd() << " avec "  << getNbTrajets() - 1 << " correspondances :" << endl;
  while((currentTrajet = trajetIterator->Next()) != NULL) {
    cout << "\t- ";
    currentTrajet->Affichage();
  }
  delete trajetIterator;
}

const char* Trajetcompose::getStart() const{
  #ifdef MAP
      cout << "Appel au Get Transport du Trajet" << endl;
  #endif

  return trajets->GetFirstTrajet()->getStart();
}

const char* Trajetcompose::getEnd() const{
  #ifdef MAP
      cout << "Appel au Get Transport du Trajet" << endl;
  #endif

  return trajets->GetLastTrajet()->getEnd();
}

int Trajetcompose::getNbTrajets() const{
  #ifdef MAP
      cout << "Appel au Get NbTrajets du Trajet" << endl;
  #endif

  return trajets->GetSize();
}

ListeTrajets * Trajetcompose::getTrajets() const{
  #ifdef MAP
      cout << "Appel au Get Trajets du Trajet" << endl;
  #endif
  return trajets;
}

void Trajetcompose::addTrajets(Trajet & trajet){
  #ifdef MAP
      cout << "Appel au AddTrajet du trajet composé" << endl;
  #endif

   this->trajets->AddTrajetQueue(trajet);
}

void Trajetcompose::Add(Trajet& trajet){
  trajets->AddTrajetQueue(trajet);
}

//-------------------------------------------- Constructeurs - destructeur


Trajetcompose::Trajetcompose()
: Trajet()
{
  #ifdef MAP
      cout << "Appel au constructeur de <Trajetcompose>" << endl;
  #endif

  trajets = new ListeTrajets();
}

Trajetcompose::~Trajetcompose ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Trajetcompose>" << endl;
#endif

delete trajets;

} //----- Fin de ~Trajetcompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
