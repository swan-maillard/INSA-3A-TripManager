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

#include "Trajetcompose.h"
#include "ListeTrajets.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Trajetcompose::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

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

//-------------------------------------------- Constructeurs - destructeur


Trajetcompose::Trajetcompose(ListeTrajets & lestrajets)
: Trajet(lestrajets.GetStart()->getTrajet()->getStart(), lestrajets.GetEnd()->getTrajet()->getEnd())
{
  #ifdef MAP
      cout << "Appel au constructeur de <Trajetcompose>" << endl;
  #endif

  trajets = &lestrajets;
}

Trajetcompose::~Trajetcompose ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Trajetcompose>" << endl;
#endif

} //----- Fin de ~Trajetcompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
