/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Fichier.h
 * Author: etudiant
 *
 * Created on 9 janvier 2021, 18:29
 */

#ifndef FICHIER_H
#define FICHIER_H

#include "Element.h"

class Fichier : public Element
{
public:
  Fichier (const std::string&, Element*);
  Fichier (const Fichier& orig);

  std::string chemin () const override ; 
  std::size_t taille () const override ; 
  std::string afficher () const override ; 
  Element* clone () const override ; 

  Element* reqElement (const std::string&) const override ; 
  std::string reqElementFormate () const override ; 

  virtual ~Fichier ();
private:

};

#endif /* FICHIER_H */

