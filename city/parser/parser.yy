%skeleton "lalr1.cc"
%require "3.0"

%defines
%define parser_class_name { Parser }
%define api.value.type variant
%define parse.assert

%locations

%code requires{
    #include "contexte.hh"
    #include "expressionBinaire.hh"
    #include "expressionUnaire.hh"
    #include "constante.hh"
    #include "variable.hh"
    #include "graphe.hh"

    class Scanner;
    class Driver;
    class Graphe;
}

%parse-param { Scanner &scanner }
%parse-param { Driver &driver }

%code{
    #include <iostream>
    #include <string>
    
    #include "scanner.hh"
    #include "driver.hh"

    #undef  yylex
    #define yylex scanner.yylex
}

%token                  NL
%token                  END
%token <int>            NUMBER
%token                  build
%token                  maison
%token                  route
%token                  arrow
%token                  comcourt
%token                  com

%type <int>             operation
%type<std::string>      traitement traitements 
%left '-' '+'
%left '*' '/'
%precedence  NEG

%%

programme:
    instruction{
        YYACCEPT;
    }

instruction:
    operation  {
        std::cout << "#-> " << $1 << std::endl;
    }
    | build '{' NL traitements '}'{
         // creation graphe taille 5
        std::cout<<"Construire {"<<std::endl;
        std::cout<<$4<<std::endl;
        std::cout<<"}"<<std::endl;
        /*Graphe g;
        g.initMatrice(5);*/
    }
    | build '(' NUMBER ')' '{' NL traitements '}' {
        // creation graphe de taille resultat operation
        // si graphe existe deja change juste la taille graphe
        std::cout<<"Construire ("<<$3<<"){ test"<<std::endl;
        std::cout<<$7<<std::endl;
        std::cout<<"}"<<std::endl;
       /* Graphe g;
        g.initMatrice($3);*/
    }

traitements:
    traitement NL traitements{

    }
    |
    traitement NL {

    }

traitement:
         maison {
            //construire maison à un emplacement aléatoire
                std::cout<<"Maison ok"<<std::endl;
        }
        | maison  coordonnee {
            // construire maison selon coordonées
                std::cout<<"Maison cok"<<std::endl;
        }
        | route coordonnee arrow coordonnee  {
            std::cout<<"Route "<<"->"<<std::endl;
        }
        | com {
            std::cout<<"Commentaire"<<std::endl;
        }



coordonnee:
        '(' operation ',' operation ',' operation ')' {
            std::cout<<" coordonnee ";
                }

operation:
    NUMBER {
        $$ = $1;
    }
    | '(' operation ')' {
        $$ = $2;
    }
    | operation '+' operation {
        $$ = $1 + $3;
    }
    | operation '-' operation {
        $$ = $1 - $3;
    }
    | operation '*' operation {
        $$ = $1 * $3;
    }
    | operation '/' operation {
        $$ = $1 / $3;
    }
    | '-' operation %prec NEG {
        $$ = - $2;
    }

%%

void yy::Parser::error( const location_type &l, const std::string & err_msg) {
    std::cerr << "Erreur : " << l << ", " << err_msg << std::endl;
}
