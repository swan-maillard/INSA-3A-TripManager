#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

#include "ListeTrajets.h"


class Catalogue {

  public:
    Catalogue();
    void Afficher() const;
    int GetNbTrajets() const;
    void AddTrajet(const Trajet & trajet);
    void SearchTrajets(const char * depart, const char * arrivee);
    virtual ~Catalogue ();

  protected:
    ListeTrajets * trajets;

};

#endif // CATALOGUE_H
