#if ! defined ( TRIP_H )
#define TRIP_H


class Trip {

  public:
    Trip();
    virtual const Trip * Copy() const = 0;
    virtual void Display() const = 0;
    virtual const char* GetStartCity() const = 0;
    virtual const char* GetFinishCity() const = 0;
    virtual ~Trip();

  protected:
    // Attributs et méthodes protégées

};

#endif // TRIP_H
