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

char* Trajetsimple::getTransport() const{
  #ifdef MAP
      cout << "Appel au Get Transport du Trajet" << endl;
  #endif
  return transport;
}

//-------------------------------------------- Constructeurs - destructeur


Trajetsimple::Trajetsimple(const char* depart, const char* arrivee, const char* letransport)
: Trajet(depart, arrivee)
{
  #ifdef MAP
      cout << "Appel au constructeur de <Trajetsimple>" << endl;
  #endif
  transport = new char[strlen(letransport)+1];
  strcpy(transport, letransport);
}

Trajetsimple::~Trajetsimple ( ) {
  #ifdef MAP
      cout << "Appel au destructeur de <Trajetsimple>" << endl;
  #endif

  delete [] transport;

} //----- Fin de ~Trajetsimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
