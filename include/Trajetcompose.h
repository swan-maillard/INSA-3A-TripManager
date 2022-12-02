#if ! defined ( Trajetcompose_H )
#define TRAJETCOMPOSE_H

#include "Trajet.h"
#include "ListeTrajets.h"


class Trajetcompose : public Trajet {

  public:
    Trajetcompose();
    Trajetcompose(const Trajetcompose & trajet);
    const Trajetcompose * copy() const;
    void Affichage() const;
    const char* GetStart() const;
    const char* GetEnd() const;
    int GetNbTrajets() const;
    void addTrajets(const Trajet & trajet);
    void Add(const Trajet& trajet);
    virtual ~Trajetcompose();

  protected:
    ListeTrajets * trajets;

};


#endif // Trajetcompose_H
