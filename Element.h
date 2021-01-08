/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   element.h
 * Author: etudiant
 *
 * Created on 26 décembre 2020, 22:11
 */

#ifndef ELEMENT_H
#define ELEMENT_H

#include <string>

/**
 * \class Element
 * Classe abstraite utilisée pour représenter un élément d'une arborescence.\n
 * Un dossier contient des éléments, qui à leur tour peuvent être des dossiers
 * ou des fichiers.\n
 * Tout élément devra donc implémenter les méthodes suivantes:\n
 * chemin(): afficher le chemin complet depuis la racine de l'arborescence\n
 * taille(): afficher la mémoire occupée par l'élément\n
 * afficher(): afficher les informations de base de l'élément\n
 * clone(): retourner un pointeur à une copie de l'élément\n
 * reqElement(): retourner un pointeur à l'élément\n
 * reqElementFormate(): retourner une chaîne de caractère contenant les 
 * informations de l'élément\n
 * 
 */

class Element
{
public:
  Element (const std::string& = "", Element* = nullptr );
  Element (const Element& orig);
  
  virtual std::string chemin()   const = 0 ; 
  virtual std::size_t taille()   const = 0 ; 
  virtual std::string afficher() const = 0 ; 
  virtual Element*    clone()    const = 0 ; 
  
  virtual Element*    reqElement(const std::string&) const = 0 ; 
  virtual std::string reqElementFormate()            const = 0 ; 
  
  const   Element*    reqParent() const ; 
  const std::string&   reqNom() const ;
  
  virtual ~Element ();
private:
  
  std::string nom ; 
  Element*    parent ; 
  

};

#endif /* ELEMENT_H */

