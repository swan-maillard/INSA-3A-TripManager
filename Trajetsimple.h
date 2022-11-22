/*************************************************************************
                           Trajetsimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Trajetsimple> (fichier Trajetsimple.h) ----------------
#if ! defined ( Trajetsimple_H )
#define TRAJETSIMPLE_H
#include "Trajet.h"

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajetsimple>
//
//
//------------------------------------------------------------------------

class Trajetsimple:public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    Trajetsimple & operator = ( const Trajetsimple & unTrajetsimple );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Trajetsimple ( const Trajetsimple & unTrajetsimple );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Trajetsimple ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

      Trajetsimple ( char* depart,  char* arrivee,  char* letransport)
      : Trajet(depart,arrivee), transport(letransport)
        {

        }

    virtual ~Trajetsimple ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
char* transport;
};

//-------------------------------- Autres définitions dépendantes de <Trajetsimple>

#endif // Trajetsimple_H
