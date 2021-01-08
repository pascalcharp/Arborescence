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

