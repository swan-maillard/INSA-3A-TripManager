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
#include <ctype.h>

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

  cout << "Notre catalogue propose " << GetTripsNumber() << " trajet" << (GetTripsNumber() > 1 ? "s" : "") << " :" << endl;

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

void Catalogue::LoadFromFile(ifstream & file, loadSaveSettings & settings) {
  #ifdef MAP
      cout << "Exécution de LoadFromFile de <Catalogue>" << endl;
  #endif

  string line;
  int tripIndex = 0;
  bool isInCompound = false;
  bool isInAllowedCompound = false;
  CompoundTrip * tc = NULL;

  // Pour chaque ligne du fichier
  while (getline(file, line)) {
    // On récupère le nombre de caractères de la ligne
    int lengthLine = line.length();
    char c;

    // On récupère les arguments de la ligne (les arguments sont séparés par des `;`)
    string args[3];
    int argIndex = 0;
    for (int i=0; i<lengthLine; i++) {
      c = line[i];

      if (!isprint(c))
        break;

      if (c == ';')
        argIndex++;
      else
        args[argIndex] += c;
    }

    // S'il n'y a pas d'arguments on passe à la ligne suivante
    if (argIndex == 0)
      continue;

    if (args[0] == "COMPOUND") {
      // Si le premier argument est "COMPOUND" alors on entre dans un trajet composé
      isInCompound = true;
      isInAllowedCompound = false;

      // On vérifie les différents critères
      bool checkType = (settings.type == 0 || settings.type == 2);
      bool checkStartCity = (settings.startCity == "0" || settings.startCity == args[1]);
      bool checkFinishCity = (settings.finishCity == "0" || settings.finishCity == args[2]);
      bool checkInterval = (settings.isInterval == 0 || (settings.minInterval <= tripIndex && settings.maxInterval >= tripIndex));
      if (checkType && checkStartCity && checkFinishCity) {
        if (checkInterval) {
          tc = new CompoundTrip();
          isInAllowedCompound = true;
        }
        tripIndex++;
      }
    }
    else if (args[0] == "END_COMPOUND") {
      // Si le premier argument est "END_COMPOUND" et que l'on est dans un trajet composé alors on en sort
      isInCompound = false;
      if (isInAllowedCompound) {
        AddTrip(*tc);
        delete tc;
        tc = NULL;
      }
    }
    else if (argIndex == 3 && args[0].length() > 0 && args[1].length() > 0 && args[2].length() > 0) {
      // S'il y a trois arguments alors on est dans un trajet simple

      if (isInCompound) {
        // Si on est dans un trajet composé, on vérifie que ce trajet a vérifié les critères
        if (isInAllowedCompound)
          tc->AddTrip(SimpleTrip(args[0].c_str(), args[1].c_str(), args[2].c_str()));
      }
      else {
        // On est dans un trajet simple
        // On vérifie que le trajet respecte les critères
        bool checkType = (settings.type == 0 || settings.type == 1);
        bool checkStartCity = (settings.startCity == "0" || settings.startCity == args[0]);
        bool checkFinishCity = (settings.finishCity == "0" || settings.finishCity == args[1]);
        bool checkInterval = (settings.isInterval == 0 || (settings.minInterval <= tripIndex && settings.maxInterval >= tripIndex));
        if (checkType && checkStartCity && checkFinishCity) {
          if (checkInterval) 
            AddTrip(SimpleTrip(args[0].c_str(), args[1].c_str(), args[2].c_str()));
          tripIndex++;
        }
      }
    }

  }
}

void Catalogue::SaveInFile(ofstream & file, loadSaveSettings & settings) const {
  #ifdef MAP
      cout << "Exécution de SaveInFile de <Catalogue>" << endl;
  #endif

  // Si le catalogue est vide on sort de la méthode
  if (tripList == NULL) return;

  // On itère sur les différents trajets
  int tripIndex = 0;
  Iterator * tripsIterator = tripList->CreateIterator();
  const Trip * currentTrip;
  while ((currentTrip = tripsIterator->Next()) != NULL) {

    // Si le trajet valide les critères, on l'écrit dans le fichier
    bool checkType = (settings.type == 0 || (settings.type == 1 && currentTrip->GetClass() == "SimpleTrip") || (settings.type == 2 && currentTrip->GetClass() == "CompoundTrip"));
    bool checkStartCity = (settings.startCity == "0" || settings.startCity == string(currentTrip->GetStartCity()));
    bool checkFinishCity = (settings.finishCity == "0" || settings.finishCity == string(currentTrip->GetFinishCity()));
    bool checkInterval = (settings.isInterval == 0 || (settings.minInterval <= tripIndex && settings.maxInterval >= tripIndex));
    if (checkType && checkStartCity && checkFinishCity) {
      if (checkInterval) file << currentTrip->ToFileFormat();
      tripIndex++;
    }
  }

  delete tripsIterator;
}