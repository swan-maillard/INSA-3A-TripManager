/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "ListeTrajets.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Catalogue::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode



//-------------------------------------------- Constructeurs - destructeur


Catalogue::Catalogue () {
  #ifdef MAP
      cout << "Appel au constructeur de <Catalogue>" << endl;
  #endif

  trajets = new ListeTrajets();
}

void Catalogue::Afficher() const {
  #ifdef MAP
      cout << "Appel à Afficher de <Catalogue>" << endl;
  #endif

  Iterator * trajetIterator = trajets->GetIterator();
  Trajet * currentTrajet;
  cout << "Notre catalogue propose " << GetNbTrajets() << " trajets :" << endl;
  while ((currentTrajet = trajetIterator->Next()) != NULL) {
    cout << "- ";
    currentTrajet->Affichage();
  }
  delete trajetIterator;
}

int Catalogue::GetNbTrajets() const {
  #ifdef MAP
      cout << "Appel à GetNbTrajets de <Catalogue>" << endl;
  #endif

  return trajets->GetSize();
}

void Catalogue::AddTrajet(Trajet & trajet) {
  #ifdef MAP
      cout << "Appel à AddTrajet de <Catalogue>" << endl;
  #endif

  trajets->AddTrajetAlpha(trajet);
}


Catalogue::~Catalogue () {
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif

  delete trajets;

}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
