#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "../include/Trajet.h"


Trajet::Trajet () {
  #ifdef MAP
      cout << "Appel au constructeur de <Trajet>" << endl;
  #endif
}

Trajet::~Trajet () {
#ifdef MAP
    cout << "Appel au destructeur de <Trajet>" << endl;
#endif
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
