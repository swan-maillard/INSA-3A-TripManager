#if ! defined ( Trajetsimple_H )
#define TRAJETSIMPLE_H

#include "Trajet.h"


class Trajetsimple : public Trajet {

  public:
    Trajetsimple (const char* depart, const char* arrivee, const char* transport);
    Trajetsimple(const Trajetsimple & trajet);
    const Trajetsimple * copy() const;
    virtual ~Trajetsimple();
    void Affichage() const;
    const char* GetTransport() const;
    const char* GetStart() const;
    const char* GetEnd() const;

  protected:
    const char* depart;
    const char* arrivee;
    const char* transport;

};

#endif // Trajetsimple_H
