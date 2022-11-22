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


//------------------------------------------------- Surcharge d'opérateurs
Trajet & Trajet::operator = ( const Trajet & unTrajet )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Trajet ::Trajet( const Trajet & unTrajet )
// Algorithme :
//
{
  #ifdef MAP
      cout << "Appel au constructeur de copie de <Trajet>" << endl;
  #endif

  depart=unTrajet.depart;
  arrivee=unTrajet.arrivee;
} //----- Fin de Trajet (constructeur de copie)

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
Trajet::Trajet ( )
// Algorithme :
//
{
  #ifdef MAP
      cout << "Appel au constructeur de <Trajet>" << endl;
  #endif
} //----- Fin de Trajet


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
