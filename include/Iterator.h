/*************************************************************************
    Iterator  -  Permet d'itérer sur les maillons des listes chainées TripList
                             -------------------
    début                : 13/12/2022
    copyright            : (C) 2022 par MALARD Sarah & MAILLARD Swan
    e-mail               : sarah.malard@insa-lyon.fr & swan.maillard@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Iterator> (fichier Iterator.h) ----------------
#if ! defined (ITERATOR_H)
#define ITERATOR_H

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include "Iterator.h"
#include "ElementTripList.h"
#include "Trip.h"


class Iterator {

//----------------------------------------------------------------- PUBLIC
  public:
//----------------------------------------------------- Méthodes publiques

    // Constructeur
    // Prend en argument le maillon de départ de l'itérateur
    Iterator(const ElementTripList * element);

    // Destructeur
    virtual ~Iterator();

    // Renvoie le maillon courant et passe au maillon suivant
    const Trip* Next();


//----------------------------------------------------------------- PRIVE
  protected:
//----------------------------------------------------- Attributs protégés
    const ElementTripList * currentElement;

};

#endif // ITERATOR_H
