using namespace std;

#include <iostream>
#include <cstring>

#include "../include/ListeTrajets.h"
#include "../include/ElementListe.h"
#include "../include/Trajet.h"
#include "../include/Iterator.h"

ListeTrajets::ListeTrajets() {
  #ifdef MAP
      cout << "Appel au constructeur de <ListeTrajets>" << endl;
  #endif

  size = 0;
  start = end = NULL;
}

ListeTrajets::ListeTrajets(const ListeTrajets * trajets) {
  #ifdef MAP
      cout << "Appel au constructeur de copie <ListeTrajets>" << endl;
  #endif

  size = trajets->size;

  if (trajets->start == NULL) {
    start = end = NULL;
  }
  else {
    start = new ElementListe(trajets->start);
    if (trajets->start == trajets->end)
      end = start;
    else
      end = new ElementListe(trajets->end);
  }
}


ListeTrajets::~ListeTrajets() {
  #ifdef MAP
      cout << "Appel au destructeur de <ListeTrajets>" << endl;
  #endif

  ElementListe * currentElement = start;
  while (currentElement != NULL) {
    ElementListe * next = currentElement->GetNext();
    delete currentElement;
    currentElement = next;
  }
}


void ListeTrajets::AddTrajetQueue(const Trajet & trajet) {
  ElementListe * newElement = new ElementListe(trajet);

  if (start == NULL) {
    start = end = newElement;
  }
  else {
    end->AddNext(newElement);
    end = newElement;
  }

  size++;
}


void ListeTrajets::AddTrajetAlpha(const Trajet & trajet) {
  ElementListe * newElement = new ElementListe(trajet);

  if (start == NULL) {
    start = end = newElement;
  }
  else if (strcmp(trajet.GetEnd(), GetFirstTrajet()->GetEnd()) < 0) {
    newElement->AddNext(start);
    start = newElement;
  }
  else if (strcmp(trajet.GetEnd(), GetLastTrajet()->GetEnd()) >= 0) {
    end->AddNext(newElement);
    end = newElement;
  }
  else {
    ElementListe * previousElement = start;
    ElementListe * currentElement = start->GetNext();
    while (strcmp(trajet.GetEnd(), currentElement->GetTrajet()->GetEnd()) >= 0) {
      previousElement = currentElement;
      currentElement = currentElement->GetNext();
    }
    newElement->AddNext(currentElement);
    previousElement->AddNext(newElement);
  }

  size++;
}


const Trajet * ListeTrajets::GetFirstTrajet() const {
  if (start == NULL)
    return NULL;

  return start->GetTrajet();
}


const Trajet * ListeTrajets::GetLastTrajet() const {
  if (end == NULL)
    return NULL;

  return end->GetTrajet();
}


int ListeTrajets::GetSize() const {
  return size;
}


Iterator * ListeTrajets::CreateIterator() const {
  Iterator * iterator = new Iterator(start);
  return iterator;
}
