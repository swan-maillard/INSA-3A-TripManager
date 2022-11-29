/*************************************************************************
                           ListeTrajets  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <ListeTrajets> (fichier ListeTrajets.h) ----------------
#if ! defined ( LISTE_TRAJETS_H )
#define LISTE_TRAJETS_H
#include "ElementListe.h"

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ListeTrajets>
//
//
//------------------------------------------------------------------------

class ListeTrajets
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    ListeTrajets ();
    // Mode d'emploi :
    //
    // Contrat :
    virtual ~ListeTrajets ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void AddTrajetQueue(Trajet & trajet);
    void AddTrajetAlpha(Trajet & trajet);

    ElementListe * GetStart();

    ElementListe * GetEnd();

    int GetSize();

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
ElementListe * start;
ElementListe * end;
int size;

};

//-------------------------------- Autres définitions dépendantes de <ListeTrajets>

#endif // LISTE_TRAJETS_H
