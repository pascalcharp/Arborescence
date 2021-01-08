/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Dossier.h
 * Author: etudiant
 *
 * Created on 26 décembre 2020, 22:58
 */

#ifndef DOSSIER_H
#define DOSSIER_H

#include <set>

#include "Element.h"

class Dossier : public Element
{
public:
  Dossier (const std::string& = "", Element* = nullptr);
  Dossier (const Dossier& orig);

  std::string chemin ()   const override;
  std::size_t taille ()   const override;
  std::string afficher () const override;
  Element* clone ()       const override;
  std::string reqElementFormate() const override;
  Element* reqElement(const std::string&) const override ; 

  void creerNouveauDossier (const std::string&);

  virtual ~Dossier ();
private:
  std::set<Element*> elements;

};

#endif /* DOSSIER_H */

