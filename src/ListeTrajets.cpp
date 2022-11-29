/*************************************************************************
                           ListeTrajets  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <ListeTrajets> (fichier ListeTrajets.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "ListeTrajets.h"
#include "ElementListe.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//-------------------------------------------- Constructeurs - destructeur


ListeTrajets::ListeTrajets ()
// Algorithme :
//
{
  #ifdef MAP
      cout << "Appel au constructeur de <ListeTrajets>" << endl;
  #endif

  size = 0;
  start = NULL;
  end = NULL;
}


ListeTrajets::~ListeTrajets ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <ListeTrajets>" << endl;
#endif

  ElementListe * currentElement = start;
  while (currentElement != NULL) {
    ElementListe * next = currentElement->getNext();
    delete currentElement;
    currentElement = next;
  }
} //----- Fin de ~ListeTrajets

void ListeTrajets::AddTrajetQueue(Trajet & trajet) {
  #ifdef MAP
      cout << "Appel au AddTrajetQueue de <ListeTrajets>" << endl;
  #endif

  size++;
  ElementListe * lastTrajet = end;
  end = new ElementListe(trajet);
  if (lastTrajet != NULL)
    lastTrajet->AddNext(end);
  if (start == NULL)
    start = end;
}

void ListeTrajets::AddTrajetAlpha(Trajet & trajet) {
  #ifdef MAP
      cout << "Appel au AddTrajetAlpha de <ListeTrajets>" << endl;
  #endif

  size++;
  if (start == NULL) {
    start = end = new ElementListe(trajet);
    return;
  }

  ElementListe * previousElement = NULL;
  ElementListe * currentElement = start;
  int inserted = 0;

  while (currentElement != NULL && !inserted) {
    char * cityEndCurrent = currentElement->getTrajet()->getEnd();
    char * cityEndToInsert = trajet.getEnd();

    if (strcmp(cityEndToInsert, cityEndCurrent) < 0) {
      if (previousElement == NULL) {
        previousElement = new ElementListe(trajet);
        previousElement->AddNext(currentElement);
        start = previousElement;
        inserted = 1;
      }
      else {
        char * cityEndPrevious = previousElement->getTrajet()->getEnd();
        if (strcmp(cityEndToInsert, cityEndPrevious) >= 0) {
          ElementListe * newElement = new ElementListe(trajet);
          newElement->AddNext(currentElement);
          previousElement->AddNext(newElement);
        }
      }
    }
    previousElement = currentElement;
    currentElement = currentElement->getNext();
  }

}

ElementListe * ListeTrajets::GetStart() {
  #ifdef MAP
      cout << "Appel au GetStart de <ListeTrajets>" << endl;
  #endif

  return start;
}

ElementListe * ListeTrajets::GetEnd() {
  #ifdef MAP
      cout << "Appel au GetEnd de <ListeTrajets>" << endl;
  #endif

  return end;
}

int ListeTrajets::GetSize() {
  #ifdef MAP
      cout << "Appel au GetSize de <ListeTrajets>" << endl;
  #endif

  return size;
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
