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
    int rayon;
    bool oriente;
    
  public :

    Graphe();
    ~Graphe();
    void initMatrice(int rayon);
    int getRayon(int i) {return rayon;}
    void setOriente(bool o) {oriente = o;};
    void ajoutArc(int,int,int); 
    void affichageMatrice(); 
    void parcoursProfondeur();
    void explorer(int s);
    void parcoursLargeur();
};
