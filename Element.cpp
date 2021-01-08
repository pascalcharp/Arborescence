/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   element.cpp
 * Author: etudiant
 * 
 * Created on 26 décembre 2020, 22:11
 */

#include "Element.h"
#include <sstream>

Element::Element (const std::string& nom, Element* parent) : nom(nom), parent(parent) { }

Element::Element (const Element& orig) { }

const Element*    Element::reqParent()  const {return parent;}
const std::string& Element::reqNom()    const {return nom;}

std::string Element::chemin() const {
  return parent ? parent->chemin () + "/" + nom : nom; 
}

std::string Element::reqElementFormate() const {
  std::stringstream os ; 
  os << "Nom: " << nom << " Chemin: " << chemin() ; 
  return os.str() ; 
}

Element::~Element () { }

