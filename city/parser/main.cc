#include "parser.hpp"
#include "scanner.hh"
#include "driver.hh"
#include "graphe.hh"

#include <iostream>
#include <fstream>

#include <cstring>

int main( int  argc, char* argv[]) {
    Driver driver;
    std::ifstream fichier("01.city");

    Scanner scanner(fichier, std::cout);
    yy::Parser parser(scanner, driver);

    Graphe g;
    g.initMatrice(11);
    g.affichageMatrice();

    parser.parse();

    return 0;
}
