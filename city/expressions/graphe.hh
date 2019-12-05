#pragma once
#include <string>
#include <vector>
#include <set>
#include <tuple>
#include <array>
#include <limits>
#include "construction.hh"
#include <memory>

const int Max = 1000;

class Graphe{
  private : 
    std::array<std::array<int,Max>, Max> matrice;
    std::array<bool,Max> parcourus;
    int nbSommet;
    bool oriente;
    
  public :

    Graphe();
    ~Graphe();
    void initMatrice(int nbSommet);
    int getnbSommet(int i) {return nbSommet;}
    void setOriente(bool o) {oriente = o;};
    void ajoutArc(int,int,int); 
    void affichageMatrice(); 
    void parcoursProfondeur();
    void explorer(int s);
    void parcoursLargeur();
};
