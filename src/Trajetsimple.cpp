/*************************************************************************
                           Trajetsimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Trajetsimple> (fichier Trajetsimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel

#include "Trajetsimple.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Trajetsimple::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Trajetsimple::Affichage() const {
  cout << getStart() << " à " << getEnd() << " en " << transport << endl;
}


const char* Trajetsimple::getTransport() const{
  #ifdef MAP
      cout << "Appel au Get Transport du Trajet" << endl;
  #endif
  return transport;
}

const char* Trajetsimple::getStart() const{
  #ifdef MAP
      cout << "Appel au Get Transport du Trajet" << endl;
  #endif

  return depart;
}

const char* Trajetsimple::getEnd() const{
  #ifdef MAP
      cout << "Appel au Get Transport du Trajet" << endl;
  #endif

  return arrivee;
}

//-------------------------------------------- Constructeurs - destructeur


Trajetsimple::Trajetsimple(const char* depart, const char* arrivee, const char* letransport)
: Trajet()
{
  #ifdef MAP
      cout << "Appel au constructeur de <Trajetsimple>" << endl;
  #endif

  this->depart = depart;
  this->arrivee = arrivee;
  transport = letransport;
}

Trajetsimple::~Trajetsimple ( ) {
  #ifdef MAP
      cout << "Appel au destructeur de <Trajetsimple>" << endl;
  #endif
} //----- Fin de ~Trajetsimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
