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
void  Trajetsimple::Afficher() const{
  cout << "en";
  for (int i=0;i<strlen(transport);i++){
    cout << transport[i];
  }

}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Trajetsimple::Trajetsimple ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <Trajetsimple>" << endl;
#endif
} //----- Fin de Trajetsimple

Trajetsimple::Trajetsimple(const char* depart, const char* arrivee, char* letransport)
: Trajet(depart,arrivee), transport(letransport)
{

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
