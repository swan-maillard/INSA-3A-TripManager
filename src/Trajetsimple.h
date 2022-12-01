/*************************************************************************
                           Trajetsimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Trajetsimple> (fichier Trajetsimple.h) ----------------
#if ! defined ( Trajetsimple_H )
#define TRAJETSIMPLE_H
#include "Trajet.h"

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajetsimple>
//
//
//------------------------------------------------------------------------

class Trajetsimple:public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    void Affichage() const;
    const char* getTransport() const;
    const char* getStart() const;
    const char* getEnd() const;



//-------------------------------------------- Constructeurs - destructeur


    Trajetsimple (const char* depart, const char* arrivee, const char* letransport);

    virtual ~Trajetsimple ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
const char* depart;
const char* arrivee;
const char* transport;
};

//-------------------------------- Autres définitions dépendantes de <Trajetsimple>

#endif // Trajetsimple_H
