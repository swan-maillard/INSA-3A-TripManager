/*************************************************************************
                           ElementListe  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <ElementListe> (fichier ElementListe.h) ----------------
#if ! defined ( ELEMENT_LISTE_H )
#define ELEMENT_LISTE_H
#include "Trajet.h"

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ElementListe>
//
//
//------------------------------------------------------------------------

class ElementListe
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    ElementListe (Trajet & trajet);
    // Mode d'emploi :
    //
    // Contrat :
    virtual ~ElementListe ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    Trajet* getTrajet() const;
    ElementListe* getNext() const;

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
Trajet * trajet;
ElementListe * next;
};

//-------------------------------- Autres définitions dépendantes de <ElementListe>

#endif // ELEMENT_LISTE_H
