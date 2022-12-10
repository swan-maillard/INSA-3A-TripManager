using namespace std;
#include <iostream>
#include <cstring>

#include "../include/Trip.h"


Trip::Trip() {
  #ifdef MAP
      cout << "Appel au constructeur de <Trip>" << endl;
  #endif
}

Trip::~Trip() {
#ifdef MAP
    cout << "Appel au destructeur de <Trip>" << endl;
#endif
}
