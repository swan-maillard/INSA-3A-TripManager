/*************************************************************************
    TripList  -  Liste chainée contenant des trajets.
                 Ses maillons sont de type ElementTripList
                             -------------------
    début                : 13/12/2022
    copyright            : (C) 2022 par MALARD Sarah & MAILLARD Swan
    e-mail               : sarah.malard@insa-lyon.fr & swan.maillard@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TripList> (fichier TripList.h) ----------------
#if ! defined ( TRIP_LIST_H )
#define TRIP_LIST_H

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include "ElementTripList.h"
#include "Iterator.h"
#include "Trip.h"

class TripList {

//----------------------------------------------------------------- PUBLIC
  public:
//----------------------------------------------------- Méthodes publiques

    // Constructeur
    TripList();

    // Constructeur par copie
    TripList(const TripList & tripList);

    // Destructeur
    virtual ~TripList();

    // Ajoute un trajet à la fin de la liste chainée
    void AddTripInQueue(const Trip & trip);

    // Ajoute un trajet à la liste chainée en respectant l'ordre alphabétique du nom de la ville d'arrivée
    void AddTripAlpha(const Trip & trip);

    // Renvoie le premier trajet de la liste chainée
    const Trip * GetFirstTrip() const;

    // Renvoie le dernier trajet de la liste chainée
    const Trip * GetLastTrip() const;

    // Renvoie la taille de la liste chainée
    int GetListSize() const;

    // Crée un itérateur en lui passant en argument le premier maillon de la liste chainée
    Iterator * CreateIterator() const;

//----------------------------------------------------------------- PRIVE
  protected:
//----------------------------------------------------- Attributs protégés
    ElementTripList * firstElem;
    ElementTripList * lastElem;
    int size;
};


#endif // TRIP_LIST_H
