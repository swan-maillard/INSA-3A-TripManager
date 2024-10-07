# OUI-SNC++

**OUI-SNC++** est une application console en C++ permettant de gérer un catalogue de trajets, qu'ils soient simples ou composés. Elle offre des fonctionnalités telles que l'affichage, la recherche, l'ajout, la sauvegarde et le chargement de trajets à partir de fichiers.

## Fonctionnalités

- **Affichage des trajets** : Affiche tous les trajets actuellement enregistrés dans le catalogue.
- **Recherche de trajets** : Permet de rechercher des trajets en fonction d'une ville de départ et d'une ville d'arrivée.
- **Ajout de trajets** :
  - **Trajet simple** : Trajet direct entre une ville de départ et une ville d'arrivée, via un moyen de transport.
  - **Trajet composé** : Trajet constitué de plusieurs étapes successives (plusieurs trajets simples enchaînés).
- **Sauvegarde du catalogue** : Sauvegarde les trajets dans un fichier avec des options pour filtrer par type de trajet et villes spécifiques.
- **Chargement du catalogue** : Charge des trajets à partir d'un fichier avec des options de filtrage similaires à celles de la sauvegarde.

## Installation

1. **Cloner le projet** :
   ```bash
   git clone https://github.com/swan-maillard/TP-3IF-TripManager.git
   ```

2. **Accéder au répertoire du projet** :
   ```bash
   cd TP-3IF-TripManager
   ```

3. **Compiler le projet** :
   ```bash
   make
   ```

4. **Lancer l'application** :
   ```bash
   ./trajets
   ```

## Utilisation

Une fois l'application lancée, un menu interactif vous permet de naviguer entre différentes options :

1. **Afficher les trajets** : Montre tous les trajets enregistrés dans le catalogue.
2. **Rechercher un trajet** : Permet de rechercher un trajet en spécifiant la ville de départ et la ville d'arrivée.
3. **Ajouter un trajet** :
   - **Trajet simple** : Ajoutez un trajet direct en fournissant les informations de la ville de départ, de la ville d'arrivée, et du moyen de transport.
   - **Trajet composé** : Ajoutez un trajet composé en spécifiant les différentes étapes (villes et moyens de transport).
4. **Charger un fichier** : Charge des trajets à partir d'un fichier existant.
5. **Sauvegarder dans un fichier** : Sauvegarde le catalogue actuel dans un fichier avec des options de filtrage (type de trajet, ville de départ, ville d'arrivée, etc.).
6. **Quitter** : Quitte l'application.

## Structure du projet

- **src/** : Contient les fichiers source C++ (.cpp).
- **include/** : Contient les fichiers d'en-tête (.h).
- **Makefile** : Automatisation de la compilation et de la gestion du projet.

## Commandes Makefile

Le projet inclut un Makefile pour simplifier la compilation et la gestion des fichiers. Voici quelques commandes utiles :

- `make` : Compile le projet et génère l'exécutable.
- `make dev` : Compile le projet en mode développement avec des options de débogage.
- `make run` : Compile et exécute l'application.
- `make clean` : Supprime les fichiers objets générés.
- `make fclean` : Supprime les fichiers objets ainsi que l'exécutable.
- `make info` : Affiche des informations sur la structure du projet.

## Auteurs

- **Sarah Malard** (sarah.malard@insa-lyon.fr)
- **Swan Maillard** (swan.maillard@insa-lyon.fr)

## Licence

Ce projet est sous licence MIT. Consultez le fichier `LICENSE` pour plus d'informations.
