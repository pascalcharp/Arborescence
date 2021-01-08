/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   tsteur.cpp
 * Author: etudiant
 *
 * Created on 28 décembre 2020, 14:00
 */

#include <stdlib.h>
#include <iostream>

#include "gtest/gtest.h"
#include "Dossier.h"

TEST(Dossier, ConstructeurParDefautNoExcept) {
  ASSERT_NO_THROW(Dossier test) ;
}

TEST(Dossier, ConstructeurParDefautValeursBaseAttendues) {
  Dossier test;
  ASSERT_EQ(test.reqParent(), nullptr) ; 
  ASSERT_EQ(test.reqNom(), "") ; 
}

TEST(Dossier, ConstructeurParDefautTailleAttendue) {
  Dossier test ; 
  ASSERT_EQ(test.taille(), 0) ; 
}

TEST(Dossier, ConstructeurParDefautCheminAttendu) {
  Dossier test ; 
  ASSERT_EQ(test.chemin(), "/") ; 
}

TEST(Dossier, ConstructeurParDefautAffichageAttendu) {
  Dossier test ; 
  ASSERT_EQ(test.afficher(), "") ; 
}

class TestDossier : public ::testing::Test {
public:
  Dossier root ;
  
  TestDossier() : root() {
    root.creerNouveauDossier("SD1") ; 
    root.creerNouveauDossier("SD2") ; 
  }
};

TEST_F(TestDossier, afficher) {
  EXPECT_EQ(root.afficher (), "Nom: SD1 Chemin: SD1/ Taille: 0\nNom: SD2 Chemin: SD2/ Taille: 0\n") ; 
}

TEST_F(TestDossier, taille) {
  EXPECT_EQ(root.taille(), 0) ; 
}