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
#include "Iterator.h"
#include "Trajet.h"

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ListeTrajets>
//
//
//------------------------------------------------------------------------

class ListeTrajets
{Iterator * iterator;
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    ListeTrajets ();

    virtual ~ListeTrajets ( );

    void AddTrajetQueue(Trajet & trajet);

    void AddTrajetAlpha(Trajet & trajet);

    Trajet * GetFirstTrajet() const;

    Trajet * GetLastTrajet() const;

    int GetSize() const;

    Iterator * GetIterator() const;

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
