/*************************************************************************
    ElementTripList  -  Maillon de la liste chainée TripList, contenant un trajet
                             -------------------
    début                : 13/12/2022
    copyright            : (C) 2022 par MALARD Sarah & MAILLARD Swan
    e-mail               : sarah.malard@insa-lyon.fr & swan.maillard@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <ElementTripList> (fichier ElementTripList.h) ----------------
#if ! defined ( ELEMENT_TRIP_LIST )
#define ELEMENT_TRIP_LIST

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include "Trip.h"

class ElementTripList {

//----------------------------------------------------------------- PUBLIC
  public:
//----------------------------------------------------- Méthodes publiques

    // Constructeur
    // Prend en argument le trajet représenté par le maillon
    ElementTripList(const Trip & trip);

    // Constructeur par copie
    ElementTripList(const ElementTripList & element);
    
    // Destructeur
    virtual ~ElementTripList ();

    // Ajoute un maillon à la suite de ce maillon
    void AddNext(ElementTripList * element);

    // Renvoie le trajet représenté par le maillon
    const Trip* GetTrip() const;

    // Renvoie le maillon suivant ou NULL s'il n'y a pas de maillon suivant
    ElementTripList* GetNext() const;


//----------------------------------------------------------------- PRIVE
  protected:
//----------------------------------------------------- Attributs protégés
    const Trip * trip;
    ElementTripList * next;

};

#endif // ELEMENT_TRIP_LIST
