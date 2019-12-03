%{

#include "scanner.hh"
#include <cstdlib>

#define YY_NO_UNISTD_H

using token = yy::Parser::token;

#undef  YY_DECL
#define YY_DECL int Scanner::yylex( yy::Parser::semantic_type * const lval, yy::Parser::location_type *loc )

/* update location on matching */
#define YY_USER_ACTION loc->step(); loc->columns(yyleng);

%}

%option c++
%option yyclass="Scanner"
%option noyywrap

%%
%{
    yylval = lval;
%}
fin return token::END;

(%%.*)$      { // commentaire ligne
        return token::com;
}
(%\/(.|\n)*\/%)   { // bloc de commentaire
    return token::com;
}

"Construire" return token::build;
"Maison" return token::maison;
"Route" return token::route;
"->" return token::arrow;

"+" return '+';
"*" return '*';
"-" return '-';
"/" return '/';
"(" return '(';
")" return ')';
"=" return '=';
"{" return '{';
"}" return '}';
"," return ',';
"\'" return '\'';

[0-9]+      {
    yylval->build<int>(std::atoi(YYText()));
    return token::NUMBER;
}


"\n"          {
    loc->lines();
    return token::NL;
}

^[ \t] {

}
%%
