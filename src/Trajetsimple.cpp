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
void  Trajetsimple::Afficher() const {
  Trajet::Afficher();

  cout << " en ";
  for (int i=0;i<strlen(transport);i++){
    cout << transport[i];
  }
  cout << endl;
}

char* Trajetsimple::getTransport() const{
  #ifdef MAP
      cout << "Appel au Get Transport du Trajet" << endl;
  #endif
  return transport;
}

//-------------------------------------------- Constructeurs - destructeur


Trajetsimple::Trajetsimple(const char* depart, const char* arrivee, char* letransport)
: Trajet(depart,arrivee), transport(letransport)
{
  #ifdef MAP
      cout << "Appel au constructeur de <Trajetsimple>" << endl;
  #endif
}

Trajetsimple::~Trajetsimple ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Trajetsimple>" << endl;
#endif
} //----- Fin de ~Trajetsimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
