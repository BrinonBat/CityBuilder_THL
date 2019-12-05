#include "graphe.hh"
#include <sstream>
#include <iostream>
#include <queue>

Graphe::Graphe(): rayon(0), oriente(false){
}

Graphe::~Graphe(){

}

void Graphe::initMatrice(int nbS){
  rayon = nbS;
  for (int i=0; i<(rayon*2)+1; ++i){
    for (int j=0; j<(rayon*2)+1; ++j){
      matrice[i][j]=0;
    }
  }
  std::cout << "Graphe initialisé " <<std::endl;
}

void Graphe::ajoutArc(int origine,int destination, int c){
  if (!oriente) matrice[destination-1][origine-1] = c;
  matrice[origine-1][destination-1] = c;
}

void Graphe::affichageMatrice(){
  std::vector<int> largeurColonne;
  for (int i=0; i<(rayon*2)+1; ++i){
    int max=0;
    for (int j=0; j<(rayon*2)+1; ++j){
      std::ostringstream tmp;
      tmp << matrice[j][i];
      if (tmp.tellp() > max) {max=tmp.tellp();}
    }
    largeurColonne.push_back(max);
  }
  std::cout << "    ";
  for (int i=0; i<(rayon*2)+1; ++i)
    printf("%*d  ",largeurColonne[i],i-rayon);
  std::cout << std::endl;
  for (int i=0; i<(rayon*2)+1; ++i){
    printf("%3d|",i-rayon);
    for (int j=0; j<(rayon*2)+1; ++j){
      if(j-rayon>=0 && (j-rayon)<10){
      printf("%*.*d  ",largeurColonne[j],largeurColonne[j],matrice[i][j]);
    }else if((j-rayon)<-9){
      printf("%*.*d    ",largeurColonne[j],largeurColonne[j],matrice[i][j]);
    }else{
      printf("%*.*d   ",largeurColonne[j],largeurColonne[j],matrice[i][j]);
    }

    }
    std::cout << std::endl;
  }
}

void Graphe::explorer(int s){
  parcourus[s]=true;
  std::cout << "S" << s+1 << " ";
  for (int i=0;i<(rayon*2)+1;++i) {
    if (!parcourus[i] and (matrice[s][i]!=0))
      explorer(i);
  }
}
