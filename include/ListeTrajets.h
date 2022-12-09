#if ! defined ( LISTE_TRAJETS_H )
#define LISTE_TRAJETS_H

#include "ElementListe.h"
#include "Iterator.h"
#include "Trajet.h"

class ListeTrajets {

  public:
    ListeTrajets();
    ListeTrajets(const ListeTrajets * trajets);
    virtual ~ListeTrajets();
    void AddTrajetQueue(const Trajet & trajet);
    void AddTrajetAlpha(const Trajet & trajet);
    const Trajet * GetFirstTrajet() const;
    const Trajet * GetLastTrajet() const;
    int GetSize() const;
    Iterator * CreateIterator() const;

  protected:
    ElementListe * start;
    ElementListe * end;
    int size;

};


#endif // LISTE_TRAJETS_H
