/*************************************************************************
                           Trajetcompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Trajetcompose> (fichier Trajetcompose.h) ----------------
#if ! defined ( Trajetcompose_H )
#define TRAJETCOMPOSE_H
#include "Trajet.h"

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajetcompose>
//
//
//------------------------------------------------------------------------

class Trajetcompose:public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    virtual void Afficher() const;
    int getNbTrajets() const;

//-------------------------------------------- Constructeurs - destructeur
    Trajetcompose (const char* depart, const char* arrivee, int nbtrajets);

    virtual ~Trajetcompose ( );
    // Mode d'emploi :
    //
    // Contrat :
    //
//------------------------------------------------------------------ PRIVE
protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
int nbtrajets;
};

//-------------------------------- Autres définitions dépendantes de <Trajetcompose>

#endif // Trajetcompose_H
