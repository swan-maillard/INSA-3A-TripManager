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
#include "ListeTrajets.h"


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
    ListeTrajets getTrajets() const;
    void addTrajets(Trajet trajet, int index);


//-------------------------------------------- Constructeurs - destructeur
    Trajetcompose (const char* depart, const char* arrivee, ListeTrajets lestrajets,int nbtrajets); //a modifier pour enlever départ et arrivée (mais ça faisait des pb)

    virtual ~Trajetcompose ( );
    // Mode d'emploi :
    //
    // Contrat :
    //
//------------------------------------------------------------------ PRIVE
protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
ListeTrajets trajets;
int nbtrajets;
};

//-------------------------------- Autres définitions dépendantes de <Trajetcompose>

#endif // Trajetcompose_H
