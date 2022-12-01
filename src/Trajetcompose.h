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
    void Affichage() const;
    const char* getStart() const;
    const char* getEnd() const;
    int getNbTrajets() const;
    ListeTrajets * getTrajets() const;
    void addTrajets(Trajet & trajet);
    void Add(Trajet& trajet);

    Trajetcompose (); //a modifier pour enlever départ et arrivée (mais ça faisait des pb)

    virtual ~Trajetcompose ( );
//------------------------------------------------------------------ PRIVE
protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
ListeTrajets * trajets;
};

//-------------------------------- Autres définitions dépendantes de <Trajetcompose>

#endif // Trajetcompose_H
