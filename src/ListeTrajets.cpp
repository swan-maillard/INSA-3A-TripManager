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
  start = NULL;
  end = NULL;
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
  #ifdef MAP
      cout << "Appel au AddTrajetQueue de <ListeTrajets>" << endl;
  #endif

  ElementListe * newElement = new ElementListe(trajet);
  if (start == NULL)
    start = end = newElement;
  else {
    end->AddNext(newElement);
    end = newElement;
  }

  size++;
}


void ListeTrajets::AddTrajetAlpha(const Trajet & trajet) {
  #ifdef MAP
      cout << "Appel au AddTrajetAlpha de <ListeTrajets>" << endl;
  #endif

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
  return start->GetTrajet();
}


const Trajet * ListeTrajets::GetLastTrajet() const {
  return end->GetTrajet();
}


int ListeTrajets::GetSize() const {
  #ifdef MAP
      cout << "Appel au GetSize de <ListeTrajets>" << endl;
  #endif

  return size;
}


Iterator * ListeTrajets::GetIterator() const {
  Iterator * iterator = new Iterator(start);
  return iterator;
}
