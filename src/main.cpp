/*************************************************************************
    OUI.SNC++ : Vos trajets n'ont jamais été aussi simples !

    Fichier principal de l'application, gère l'affichage des différents menus.
                             -------------------
    début                : 13/12/2022
    copyright            : (C) 2022 par MALARD Sarah & MAILLARD Swan
    e-mail               : sarah.malard@insa-lyon.fr & swan.maillard@insa-lyon.fr
*************************************************************************/


//---------------------- Fichier main.cpp ------------------------


//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
//-------------------------------------------------------- Include personnel
#include "../include/Trip.h"
#include "../include/SimpleTrip.h"
#include "../include/TripList.h"
#include "../include/Catalogue.h"
#include "../include/CompoundTrip.h"


void load(Catalogue* catalogue){
  cout<<"Quel fichier voulez-vous lire ?"<<endl;
  string file;
  cin>>file;

  cout<<"Souhaitez-vous spécifier le type de trajet que vous voulez ?\n - 0 si non \n - 1 pour les trajets simples \n - 2 pour les trajets composés"<<endl<<endl;
  int triptype=10;
  cin>>triptype;
  while(triptype>2||triptype<0){
    cout<<"Vous devez rentrer une valeur comprise entre 0 et 2."<<endl;
    cin>>triptype;
  }

  cout<<"Souhaitez-vous spécifier une ville de départ ?\n - 0 si non \n - la ville en question si oui"<<endl<<endl;
  string startcity;
  cin>>startcity;
  cout<<"Souhaitez-vous spécifier une ville d'arrivée ?\n - 0 si non \n - la ville en question si oui"<<endl<<endl;
  string endcity;
  cin>>endcity;

  cout<<"Souhaitez-vous fixer une intervalle de trajet ?\n - 0, entrée, 0 si non \n - n, entrée, m si oui"<<endl<<endl;
  int n;
  int m;
  cin>>n;
  cin>>m;
  ifstream fic;
  fic.open(file);

  if(fic){
    catalogue->LoadFromFile(fic,triptype,startcity,endcity,n,m);
    fic.close();
  } else{
    cout<<"ERREUR : impossible d'ouvrir le fichier"<<endl;
  }
}

void loadTest(Catalogue* catalogue){
  ifstream fic;
  fic.open("demo.txt");
  if(fic){
    catalogue->LoadFromFile(fic,0,"0","Monaco",0,0);
    fic.close();
  }
}

void save(Catalogue* catalogue){
  cout<<"Dans quel fichier souhaitez-vous sauvegarder votre catalogue ?"<<endl;
  string file;
  cin>>file;

  cout<<"Souhaitez-vous spécifier le type de trajet que vous voulez ?\n - 0 si non \n - 1 pour les trajets simples \n - 2 pour les trajets composés"<<endl<<endl;
  int triptype=10;
  cin>>triptype;
  while(triptype>2||triptype<0){
    cout<<"Vous devez rentrer une valeur comprise entre 0 et 2."<<endl;
    cin>>triptype;
  }

  cout<<"Souhaitez-vous spécifier une ville de départ ?\n - 0 si non \n - la ville en question si oui"<<endl<<endl;
  string startcity;
  cin>>startcity;
  cout<<"Souhaitez-vous spécifier une ville d'arrivée ?\n - 0 si non \n - la ville en question si oui"<<endl<<endl;
  string endcity;
  cin>>endcity;

  cout<<"Souhaitez-vous fixer une intervalle de trajet ?\n - 0, entrée, 0 si non \n - n, entrée, m si oui"<<endl<<endl;
  int n;
  int m;
  cin>>n;
  cin>>m;

  ofstream fic;
  fic.open(file);


  if(fic){
    catalogue->SaveInFile(fic,triptype,startcity,endcity);
    fic.close();
  }else{
    cout<<"ERREUR : impossible d'ouvrir le fichier"<<endl;
  }
}

void displayMenu(Catalogue * catalogue);
void displayCatalogue(Catalogue * catalogue);
void searchTrip(Catalogue * catalogue);
void addTrip(Catalogue * catalogue);
void addSimpleTrip(Catalogue * catalogue);
void addCompoundTrip(Catalogue * catalogue);

// Fonction principale
int main() {
  Catalogue catalogue;
  displayMenu(&catalogue);

  return EXIT_SUCCESS;
}

// Affiche le menu principal
void displayMenu(Catalogue * catalogue) {

  int choice;

  do {
    cout << "Grand Catalogue :" << endl;
    cout << " 1 - Afficher les trajets" << endl;
    cout << " 2 - Rechercher un trajet" << endl;
    cout << " 3 - Ajouter un trajet" << endl;
    cout << " 4 - Quitter" << endl;
    cout << " 5 - Charger un fichier" <<endl;
    cout << " 6 - Sauvegarder dans un fichier" <<endl;
    cin >> choice;

    cout << endl;

    if (!cin) {
      choice = -1;
      cin.clear();
      cin.ignore();
    }

    switch (choice) {
      case 1: // Affichage
        displayCatalogue(catalogue);
        break;
      case 2: // Recherche simple
        searchTrip(catalogue);
        break;
      case 3: // Ajout
        addTrip(catalogue);
        break;
      case 4: // Fin
        cout << "A bientôt dans notre grand catalogue !" << endl;
        break;
      case 5:
        load(catalogue);
        break;
      case 6:
        save(catalogue);
        break;
      default: // Erreur de saisie
        cout << "Veuillez choisir une option parmi celles proposées !" << endl;
    }

    cout << endl;

  } while (choice != 4);
}

// Affiche le contenu du catalogue
void displayCatalogue(Catalogue * catalogue) {
  catalogue->Display();
}

// Recherche un trajet en fonction du nom de la ville de départ et d'arrivée
void searchTrip(Catalogue * catalogue) {
  char startCity[50], finishCity[50];

  cout << "Vous pouvez rechercher un trajet en renseignant la ville de départ et d'arrivée" << endl;
  cout << "Ville de départ : ";
  cin >> startCity;
  cout << "Ville d'arrivée : ";
  cin >> finishCity;

  catalogue->SearchTrip(startCity, finishCity);
}

// Permet de choisir si l'utilisateur souhaite ajouter un trajet simple ou composé
void addTrip(Catalogue * catalogue) {
  int typeTrip;
  bool loop;

  do {
    loop = false;

    cout << "Quel type de trajet souhaitez-vous ajouter ?" << endl;
    cout << " 1 - Trajet simple" << endl;
    cout << " 2 - Trajet composé" << endl;
    cout << " 3 - Revenir" << endl;
    cin >> typeTrip;

    if (!cin) {
      typeTrip = -1;
      cin.clear();
      cin.ignore();
    }

    cout << endl;

    switch (typeTrip) {
      case 1:
        addSimpleTrip(catalogue);
        break;
      case 2:
        addCompoundTrip(catalogue);
        break;
      case 3:
        break;
      default:
        loop = true;
        cout << "Veuillez choisir une option parmi celles proposées !" << endl;
    }

  } while (loop);
}

// Ajoute un trajet simple
void addSimpleTrip(Catalogue * catalogue) {
  char startCity[50], finishCity[50], transport[50];

  cout << "Veuillez remplir les informations suivantes :" << endl;
  cout << "Ville de départ : ";
  cin >> startCity;
  cout << "Ville d'arrivée : ";
  cin >> finishCity;
  cout << "Moyen de transport : ";
  cin >> transport;

  catalogue->AddTrip(SimpleTrip(startCity, finishCity, transport));
}

// Ajoute un trajet composé
void addCompoundTrip(Catalogue * catalogue) {
  char startCity[50], finishCity[50], transport[50];

  CompoundTrip tc;
  int nbTrips = 0;
  while (nbTrips <= 1) {
    nbTrips = 0;

    cout << "Combien d'étapes ce trajet comporte-t-il ?" << endl;
    cin >> nbTrips;

    nbTrips++;

    if (!cin) {
      nbTrips = 0;
      cin.clear();
      cin.ignore();
    }

    cout <<endl;

    if (nbTrips <= 1)
      cout << "Un trajet composé doit au moins comporter une étape." << endl;
  }

  cout << "Veuillez remplir les informations suivantes :" << endl;
  for (int i=0; i<nbTrips; i++) {
    if (i == 0) {
      cout << "Ville de départ : ";
      cin >> startCity;
    }

    if (i == nbTrips-1)
      cout << "Ville d'arrivée : ";
    else
      cout << "Ville à l'étape " << i+1 << " : ";

    cin >> finishCity;

    cout << "Moyen de transport sur cette étape : ";
    cin >> transport;

    tc.AddTrip(SimpleTrip(startCity, finishCity, transport));
    strcpy(startCity, finishCity);
  }
  catalogue->AddTrip(tc);
}
