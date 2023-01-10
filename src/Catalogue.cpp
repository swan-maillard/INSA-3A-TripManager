/*************************************************************************
    Catalogue  -  Contient des trajets et permet d'effectuer des actions (affichage, recherche, ajout)
                             -------------------
    début                : 13/12/2022
    copyright            : (C) 2022 par MALARD Sarah & MAILLARD Swan
    e-mail               : sarah.malard@insa-lyon.fr & swan.maillard@insa-lyon.fr
*************************************************************************/


//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------


//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>
#include <string>

//------------------------------------------------------ Include personnel
#include "../include/Catalogue.h"
#include "../include/TripList.h"
#include "../include/SimpleTrip.h"
#include "../include/CompoundTrip.h"


//----------------------------------------------------------------- PUBLIC

Catalogue::Catalogue () {
  #ifdef MAP
      cout << "Construction de <Catalogue>" << endl;
  #endif

  tripList = NULL;
}

Catalogue::~Catalogue () {
  #ifdef MAP
      cout << "Destruction de <Catalogue>" << endl;
  #endif

  delete tripList;
}

void Catalogue::Display() const {
  #ifdef MAP
      cout << "Exécution de Display de <Catalogue>" << endl;
  #endif

  if (tripList == NULL) {
    cout << "Notre catalogue est pour l'instant vide mais vous pouvez nous aider à le remplir !" << endl;
    return;
  }

  Iterator * tripsIterator = tripList->CreateIterator();
  const Trip * currentTrip;

  cout << "Notre catalogue propose " << GetTripsNumber() << " trajets :" << endl;

  while ((currentTrip = tripsIterator->Next()) != NULL) {
    cout << "- ";
    currentTrip->Display();
  }
  delete tripsIterator;
}

int Catalogue::GetTripsNumber() const {
  #ifdef MAP
    cout << "Exécution de GetTripsNumber de <Catalogue>" << endl;
  #endif

  if (tripList == NULL)
    return 0;

  return tripList->GetListSize();
}

void Catalogue::AddTrip(const Trip & trip) {
  #ifdef MAP
      cout << "Exécution de AddTrip de <Catalogue>" << endl;
  #endif

  if (tripList == NULL)
    tripList = new TripList();

  tripList->AddTripAlpha(trip);
}

void Catalogue::SearchTrip(const char * startCity, const char * finishCity) {
  #ifdef MAP
      cout << "Exécution de SearchTrip de <Catalogue>" << endl;
  #endif

  if (tripList == NULL) {
    cout << "Le catalogue ne contient aucun trajet" << endl;
    return;
  }

  // On itère sur les trajets du catalogue et on stocke ceux qui correspondent à la recherche dans foundTrips
  Iterator * tripsIterator = tripList->CreateIterator();
  const Trip * currentTrip;
  TripList foundTrips;
  while ((currentTrip = tripsIterator->Next()) != NULL) {
    if (strcmp(currentTrip->GetStartCity(), startCity) == 0 && strcmp(currentTrip->GetFinishCity(), finishCity) == 0) {
      foundTrips.AddTripInQueue(*currentTrip);
    }
  }
  delete tripsIterator;

  if (foundTrips.GetListSize() == 0)
    cout << "Aucun trajet allant de " << startCity << " à " << finishCity << " n'a été trouvé..." << endl;
  else if (foundTrips.GetListSize() == 1)
    cout << "1 trajet allant de " << startCity << " à " << finishCity << " a été trouvé :" << endl;
  else
    cout << foundTrips.GetListSize() << " trajets allant de " << startCity << " à " << finishCity << " ont été trouvés :" << endl;

  // On itère sur foundTrips (trajets correspondant à la recherche) et on les affiche
  tripsIterator = foundTrips.CreateIterator();
  while ((currentTrip = tripsIterator->Next()) != NULL) {
    cout << "- ";
    currentTrip->Display();
  }
  delete tripsIterator;
}

void Catalogue::LoadFromFile(ifstream & file, int type, string villedepart, string villearrivee, int n, int m) {
  string ligne;
  int nbTrips = 0;
  bool isCompound = false;
  CompoundTrip * tc = NULL;


  string departcompose;
  string arriveecomposee;
  while (getline(file, ligne)) {
    char c;
    string mots[3];
    int index = 0;

    for (int i=0; i<(int)ligne.length(); i++) {
      c = ligne[i];

      if (c == ';') {
        index++;
      }
      else {
        mots[index] += c;
      }
    }
    if (mots[0].length() == 0)
      continue;

    if (mots[0] == "COMPOUND") {
      isCompound = true;
      nbTrips++;
      tc = new CompoundTrip();
      departcompose=mots[1];
      arriveecomposee=mots[2];
      continue;
    }
    else if (mots[0] == "END_COMPOUND") {
      isCompound = false;
      if(type!=1&& (villedepart=="0" || villedepart==departcompose) && (villearrivee=="0"||villearrivee==arriveecomposee)&&((n==0 && m==0)|| (nbTrips<=m && nbTrips>=n))){ //partie sur n et m à enlever car ça marche pas
      AddTrip(*tc);
    }
    departcompose="0";
    arriveecomposee="0";
      delete tc;
      tc=NULL;
      continue;
    }

    SimpleTrip trip(mots[0].c_str(), mots[1].c_str(), mots[2].c_str());
    if (!isCompound) {
      if(type!=2&& (villedepart=="0" || villedepart==mots[0]) && (villearrivee=="0"||villearrivee==mots[1])){
        nbTrips++;
        if(((n==0 && m==0)|| (nbTrips<=m && nbTrips>=n))) //partie sur n et m qui marche pas
          AddTrip(trip);
    }
    }
    else {
      tc->AddTrip(trip);
    }
  }
  cout<<"nombre de trajets :" <<nbTrips; //problème dans le compteur de trajet?

}

void Catalogue::SaveInFile(ofstream & file, int type, string villedepart, string villearrivee) const {
  if (tripList == NULL) return;

  Iterator * tripsIterator = tripList->CreateIterator();
  const Trip * currentTrip;

  while ((currentTrip = tripsIterator->Next()) != NULL) {
    if((type==0 || type==currentTrip->GetType())&&(villedepart=="0"||villedepart==currentTrip->GetStartCity())&&(villearrivee=="0"||villearrivee==currentTrip->GetFinishCity()))
    file<<currentTrip->ToFileFormat();
  }

  delete tripsIterator;
}
