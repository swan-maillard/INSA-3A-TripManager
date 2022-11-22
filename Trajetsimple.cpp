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


//------------------------------------------------- Surcharge d'opérateurs
Trajetsimple & Trajetsimple::operator = ( const Trajetsimple & unTrajetsimple )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Trajetsimple::Trajetsimple ( const Trajetsimple & unTrajetsimple )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Trajetsimple>" << endl;
#endif
} //----- Fin de Trajetsimple (constructeur de copie)


Trajetsimple::Trajetsimple ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Trajetsimple>" << endl;
#endif
} //----- Fin de Trajetsimple


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
