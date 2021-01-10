/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Fichier.cpp
 * Author: etudiant
 * 
 * Created on 9 janvier 2021, 18:29
 */

#include "Fichier.h"

Fichier::Fichier (const std::string& nom, Element* parent) : Element (nom, parent) { }

Fichier::Fichier (const Fichier& orig) { }

std::string Fichier::chemin () const
{
  return Element::chemin ();
}

std::size_t Fichier::taille () const {
  return 0 ; 
}

std::string Fichier::afficher () const { 
  return "" ; 
}

Element* Fichier::clone () const { 
  return new Fichier(*this) ; 
}

Element* Fichier::reqElement (const std::string&) const { 
  return nullptr ; 
}

std::string Fichier::reqElementFormate () const { 
  return "" ; 
}


Fichier::~Fichier () { }

