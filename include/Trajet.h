#if ! defined ( TRAJET_H )
#define TRAJET_H


class Trajet {

  public:
    Trajet();
    virtual const Trajet * copy() const = 0;
    virtual void Affichage() const = 0;
    virtual const char* GetStart() const = 0;
    virtual const char* GetEnd() const = 0;
    virtual ~Trajet ( );

  protected:
    // Attributs et méthodes protégées

};

#endif // TRAJET_H
