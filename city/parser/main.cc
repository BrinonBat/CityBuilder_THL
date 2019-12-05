#include "parser.hpp"
#include "scanner.hh"
#include "driver.hh"

#include <iostream>
#include <fstream>

#include <cstring>



int main( int  argc, char* argv[]) {
    Driver driver;
    std::ifstream fichier("../exemples/01.city");
    std::string ligne;

    Scanner scanner(fichier, std::cout);
    yy::Parser parser(scanner, driver);

    parser.parse();
    return 0;
}
