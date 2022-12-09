#if ! defined ( ELEMENT_LISTE_H )
#define ELEMENT_LISTE_H

#include "Trajet.h"


class ElementListe {

  public:
    ElementListe(const Trajet & trajet);
    ElementListe(const ElementListe * element);
    void AddNext(ElementListe * element);
    const Trajet* GetTrajet() const;
    ElementListe* GetNext() const;
    virtual ~ElementListe ();

  protected:
    const Trajet * trajet;
    ElementListe * next;

};

#endif // ELEMENT_LISTE_H
