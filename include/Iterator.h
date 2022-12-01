/*************************************************************************
                           Iterator  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Iterator> (fichier Iterator.h) ----------------
#if ! defined (ITERATOR)
#define ITERATOR
#include "Iterator.h"
#include "ElementListe.h"
#include "Trajet.h"

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Iterator>
//
//
//------------------------------------------------------------------------

class Iterator {
//----------------------------------------------------------------- PUBLIC

public:

    Iterator(const ElementListe * element);
    virtual ~Iterator();
    Trajet * Next();

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

const ElementListe * currentElement;

};

//-------------------------------- Autres définitions dépendantes de <Iterator>

#endif // ITERATOR
