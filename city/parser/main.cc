#include "parser.hpp"
#include "scanner.hh"
#include "driver.hh"

#include <iostream>
#include <fstream>

#include <cstring>



int main( int  argc, char* argv[]) {
    Driver driver;
    std::ifstream fichier("011.txt");
    std::string ligne;

    Scanner scanner(fichier, std::cout);
    yy::Parser parser(scanner, driver);

    parser.parse();/*
    while(getline(fichier,ligne)){
        std::cout<<ligne<<std::endl;
    }*/
    return 0;
}
