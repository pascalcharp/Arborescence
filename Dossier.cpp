/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Dossier.cpp
 * Author: etudiant
 * 
 * Created on 26 décembre 2020, 22:58
 */

#include "Dossier.h"
#include <sstream>

// Constructeur de base.  Par défaut, sans nom et sans parent.

Dossier::Dossier (const std::string& nom, Element* parent) : Element(nom, parent) { }

// Constructeur de copie.  Fait une copie profonde des enfants.

Dossier::Dossier (const Dossier& orig) : Element( orig.reqNom(), nullptr ) {
  for (auto element: orig.elements) {
      elements.insert (element->clone()) ; 
    }
}

// Affiche le chemin complet à-partir de l'élément racine

std::string Dossier::chemin() const {
  return Element::chemin() + "/" ; 
}

// Pour les dossiers: affiche la somme des tailles des enfants.

 std::size_t Dossier::taille() const {
   std::size_t total = 0;
  
   if ( !elements.empty() ) {
       for (auto element: elements) total += element->taille() ; 
     }
   return total ; 
 } 
 
 // Retourne un objet chaîne contenant le nom, le chemin et la taille du dossier.
 
 std::string Dossier::reqElementFormate() const {
   std::stringstream os;
   
   os << Element::reqElementFormate() << " Taille: " << taille() ; 
   return os.str() ; 
 }
 
 // Retourne l'adresse d'un enfant avec le nom demandé
 
 Element* Dossier::reqElement(const std::string& nomRequis) const {
   Element* adresse = nullptr ; 
   
   for (auto element: elements) {
       if ( element->reqNom() == nomRequis ) adresse = element ; 
     }
   return adresse ; 
 }
 
 // Retourne un objet chaîne contenant la liste des enfants
 
 std::string Dossier::afficher() const {
   std::string resultat ; 
   static std::string separateur = "\n" ; 
   
   for (auto element: elements) {
       resultat += element->reqElementFormate();
       resultat += separateur;
     }
   return resultat ;
 }
 
 // Retourne un pointeur à une copie de l'objet courant
 
 Element* Dossier::clone() const {
   return new Dossier(*this) ; 
 }
 
 // Crée un enfant avec le nom en argument
 
 void Dossier::creerNouveauDossier(const std::string& nouveauNom) {
   Dossier* nouveau = new Dossier(nouveauNom, this) ; 
   elements.insert(nouveau) ; 
 }

 // Destructeur: libère la mémoire des enfants.
 
Dossier::~Dossier () {
    for (auto element: elements) delete element ; 
}

