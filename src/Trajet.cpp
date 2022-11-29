/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Trajet::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Trajet::Afficher() const {
  for (int i=0;i<(int)strlen(depart);i++){
    cout << depart[i];
  }
  cout << " à ";
  for (int i=0;i<(int)strlen(arrivee);i++){
    cout << arrivee[i];
  }
}

char* Trajet::getStart() const{
  #ifdef MAP
      cout << "Appel au Get Start du Trajet" << endl;
  #endif
  return depart;
}

char* Trajet::getEnd() const{
  #ifdef MAP
      cout << "Appel au Get End du Trajet" << endl;
  #endif
  return arrivee;
}


//-------------------------------------------- Constructeurs - destructeur


Trajet::Trajet (const char* villedepart, const char* villearrivee )
// Algorithme :
//
{
  #ifdef MAP
      cout << "Appel au constructeur de <Trajet>" << endl;
  #endif
  this->depart=new char[strlen(villedepart)+1];
  this->arrivee=new char[strlen(villedepart)+1];
  strcpy(depart,villedepart);
  strcpy(arrivee,villearrivee);

}


Trajet::~Trajet ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Trajet>" << endl;
#endif

  delete[] depart;
  delete[] arrivee;
} //----- Fin de ~Trajet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
