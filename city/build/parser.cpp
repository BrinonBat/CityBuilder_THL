// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.

#line 37 "/home/baptiste/Documents/projects/CityBuilder_THL/city/build/parser.cpp" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "parser.hpp"

// User implementation prologue.

#line 51 "/home/baptiste/Documents/projects/CityBuilder_THL/city/build/parser.cpp" // lalr1.cc:412
// Unqualified %code blocks.
#line 27 "parser/parser.yy" // lalr1.cc:413

    #include <iostream>
    #include <string>
    
    #include "scanner.hh"
    #include "driver.hh"

    #undef  yylex
    #define yylex scanner.yylex

#line 64 "/home/baptiste/Documents/projects/CityBuilder_THL/city/build/parser.cpp" // lalr1.cc:413


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 150 "/home/baptiste/Documents/projects/CityBuilder_THL/city/build/parser.cpp" // lalr1.cc:479

  /// Build a parser object.
   Parser :: Parser  (Scanner &scanner_yyarg, Driver &driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      scanner (scanner_yyarg),
      driver (driver_yyarg)
  {}

   Parser ::~ Parser  ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
   Parser ::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
   Parser ::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
   Parser ::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
      switch (other.type_get ())
    {
      case 5: // NUMBER
      case 28: // operation
        value.copy< int > (other.value);
        break;

      case 25: // traitements
      case 26: // traitement
        value.copy< std::string > (other.value);
        break;

      default:
        break;
    }

  }


  template <typename Base>
  inline
   Parser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {
    (void) v;
      switch (this->type_get ())
    {
      case 5: // NUMBER
      case 28: // operation
        value.copy< int > (v);
        break;

      case 25: // traitements
      case 26: // traitement
        value.copy< std::string > (v);
        break;

      default:
        break;
    }
}


  // Implementation of basic_symbol constructor for each type.

  template <typename Base>
   Parser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
   Parser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const int v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
   Parser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::string v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  template <typename Base>
  inline
   Parser ::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
   Parser ::basic_symbol<Base>::clear ()
  {
    // User destructor.
    symbol_number_type yytype = this->type_get ();
    basic_symbol<Base>& yysym = *this;
    (void) yysym;
    switch (yytype)
    {
   default:
      break;
    }

    // Type destructor.
    switch (yytype)
    {
      case 5: // NUMBER
      case 28: // operation
        value.template destroy< int > ();
        break;

      case 25: // traitements
      case 26: // traitement
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

    Base::clear ();
  }

  template <typename Base>
  inline
  bool
   Parser ::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
   Parser ::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
      switch (this->type_get ())
    {
      case 5: // NUMBER
      case 28: // operation
        value.move< int > (s.value);
        break;

      case 25: // traitements
      case 26: // traitement
        value.move< std::string > (s.value);
        break;

      default:
        break;
    }

    location = s.location;
  }

  // by_type.
  inline
   Parser ::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
   Parser ::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
   Parser ::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
   Parser ::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
   Parser ::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
   Parser ::by_type::type_get () const
  {
    return type;
  }
  // Implementation of make_symbol for each symbol type.
   Parser ::symbol_type
   Parser ::make_NL (const location_type& l)
  {
    return symbol_type (token::NL, l);
  }

   Parser ::symbol_type
   Parser ::make_END (const location_type& l)
  {
    return symbol_type (token::END, l);
  }

   Parser ::symbol_type
   Parser ::make_NUMBER (const int& v, const location_type& l)
  {
    return symbol_type (token::NUMBER, v, l);
  }

   Parser ::symbol_type
   Parser ::make_build (const location_type& l)
  {
    return symbol_type (token::build, l);
  }

   Parser ::symbol_type
   Parser ::make_maison (const location_type& l)
  {
    return symbol_type (token::maison, l);
  }

   Parser ::symbol_type
   Parser ::make_route (const location_type& l)
  {
    return symbol_type (token::route, l);
  }

   Parser ::symbol_type
   Parser ::make_arrow (const location_type& l)
  {
    return symbol_type (token::arrow, l);
  }

   Parser ::symbol_type
   Parser ::make_comcourt (const location_type& l)
  {
    return symbol_type (token::comcourt, l);
  }

   Parser ::symbol_type
   Parser ::make_com (const location_type& l)
  {
    return symbol_type (token::com, l);
  }

   Parser ::symbol_type
   Parser ::make_NEG (const location_type& l)
  {
    return symbol_type (token::NEG, l);
  }



  // by_state.
  inline
   Parser ::by_state::by_state ()
    : state (empty_state)
  {}

  inline
   Parser ::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
   Parser ::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
   Parser ::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
   Parser ::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
   Parser ::symbol_number_type
   Parser ::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
   Parser ::stack_symbol_type::stack_symbol_type ()
  {}


  inline
   Parser ::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
      switch (that.type_get ())
    {
      case 5: // NUMBER
      case 28: // operation
        value.move< int > (that.value);
        break;

      case 25: // traitements
      case 26: // traitement
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

  inline
   Parser ::stack_symbol_type&
   Parser ::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 5: // NUMBER
      case 28: // operation
        value.copy< int > (that.value);
        break;

      case 25: // traitements
      case 26: // traitement
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
   Parser ::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
   Parser ::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
   Parser ::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
   Parser ::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
   Parser ::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
   Parser ::debug_stream () const
  {
    return *yycdebug_;
  }

  void
   Parser ::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


   Parser ::debug_level_type
   Parser ::debug_level () const
  {
    return yydebug_;
  }

  void
   Parser ::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline  Parser ::state_type
   Parser ::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
   Parser ::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
   Parser ::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
   Parser ::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
    {
      case 5: // NUMBER
      case 28: // operation
        yylhs.value.build< int > ();
        break;

      case 25: // traitements
      case 26: // traitement
        yylhs.value.build< std::string > ();
        break;

      default:
        break;
    }


      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 57 "parser/parser.yy" // lalr1.cc:859
    {
        YYACCEPT;
    }
#line 781 "/home/baptiste/Documents/projects/CityBuilder_THL/city/build/parser.cpp" // lalr1.cc:859
    break;

  case 3:
#line 62 "parser/parser.yy" // lalr1.cc:859
    {
        std::cout << "#-> " << yystack_[0].value.as< int > () << std::endl;
    }
#line 789 "/home/baptiste/Documents/projects/CityBuilder_THL/city/build/parser.cpp" // lalr1.cc:859
    break;

  case 4:
#line 65 "parser/parser.yy" // lalr1.cc:859
    {
         // creation graphe taille 5
        std::cout<<"Construire {"<<std::endl;
        std::cout<<yystack_[1].value.as< std::string > ()<<std::endl;
        std::cout<<"}"<<std::endl;
        /*Graphe g;
        g.initMatrice(5);*/
    }
#line 802 "/home/baptiste/Documents/projects/CityBuilder_THL/city/build/parser.cpp" // lalr1.cc:859
    break;

  case 5:
#line 73 "parser/parser.yy" // lalr1.cc:859
    {
        // creation graphe de taille resultat operation
        // si graphe existe deja change juste la taille graphe
        std::cout<<"Construire ("<<yystack_[5].value.as< int > ()<<"){ test"<<std::endl;
        std::cout<<yystack_[1].value.as< std::string > ()<<std::endl;
        std::cout<<"}"<<std::endl;
       /* Graphe g;
        g.initMatrice($3);*/
    }
#line 816 "/home/baptiste/Documents/projects/CityBuilder_THL/city/build/parser.cpp" // lalr1.cc:859
    break;

  case 6:
#line 84 "parser/parser.yy" // lalr1.cc:859
    {

    }
#line 824 "/home/baptiste/Documents/projects/CityBuilder_THL/city/build/parser.cpp" // lalr1.cc:859
    break;

  case 7:
#line 88 "parser/parser.yy" // lalr1.cc:859
    {

    }
#line 832 "/home/baptiste/Documents/projects/CityBuilder_THL/city/build/parser.cpp" // lalr1.cc:859
    break;

  case 8:
#line 93 "parser/parser.yy" // lalr1.cc:859
    {
            //construire maison à un emplacement aléatoire
                std::cout<<"Maison ok"<<std::endl;
        }
#line 841 "/home/baptiste/Documents/projects/CityBuilder_THL/city/build/parser.cpp" // lalr1.cc:859
    break;

  case 9:
#line 97 "parser/parser.yy" // lalr1.cc:859
    {
            // construire maison selon coordonées
                std::cout<<"Maison cok"<<std::endl;
        }
#line 850 "/home/baptiste/Documents/projects/CityBuilder_THL/city/build/parser.cpp" // lalr1.cc:859
    break;

  case 10:
#line 101 "parser/parser.yy" // lalr1.cc:859
    {
            std::cout<<"Route "<<"->"<<std::endl;
        }
#line 858 "/home/baptiste/Documents/projects/CityBuilder_THL/city/build/parser.cpp" // lalr1.cc:859
    break;

  case 11:
#line 104 "parser/parser.yy" // lalr1.cc:859
    {
            std::cout<<"Commentaire"<<std::endl;
        }
#line 866 "/home/baptiste/Documents/projects/CityBuilder_THL/city/build/parser.cpp" // lalr1.cc:859
    break;

  case 12:
#line 111 "parser/parser.yy" // lalr1.cc:859
    {
            std::cout<<" coordonnee ";
                }
#line 874 "/home/baptiste/Documents/projects/CityBuilder_THL/city/build/parser.cpp" // lalr1.cc:859
    break;

  case 13:
#line 116 "parser/parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< int > () = yystack_[0].value.as< int > ();
    }
#line 882 "/home/baptiste/Documents/projects/CityBuilder_THL/city/build/parser.cpp" // lalr1.cc:859
    break;

  case 14:
#line 119 "parser/parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< int > () = yystack_[1].value.as< int > ();
    }
#line 890 "/home/baptiste/Documents/projects/CityBuilder_THL/city/build/parser.cpp" // lalr1.cc:859
    break;

  case 15:
#line 122 "parser/parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< int > () = yystack_[2].value.as< int > () + yystack_[0].value.as< int > ();
    }
#line 898 "/home/baptiste/Documents/projects/CityBuilder_THL/city/build/parser.cpp" // lalr1.cc:859
    break;

  case 16:
#line 125 "parser/parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< int > () = yystack_[2].value.as< int > () - yystack_[0].value.as< int > ();
    }
#line 906 "/home/baptiste/Documents/projects/CityBuilder_THL/city/build/parser.cpp" // lalr1.cc:859
    break;

  case 17:
#line 128 "parser/parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< int > () = yystack_[2].value.as< int > () * yystack_[0].value.as< int > ();
    }
#line 914 "/home/baptiste/Documents/projects/CityBuilder_THL/city/build/parser.cpp" // lalr1.cc:859
    break;

  case 18:
#line 131 "parser/parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< int > () = yystack_[2].value.as< int > () / yystack_[0].value.as< int > ();
    }
#line 922 "/home/baptiste/Documents/projects/CityBuilder_THL/city/build/parser.cpp" // lalr1.cc:859
    break;

  case 19:
#line 134 "parser/parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< int > () = - yystack_[0].value.as< int > ();
    }
#line 930 "/home/baptiste/Documents/projects/CityBuilder_THL/city/build/parser.cpp" // lalr1.cc:859
    break;


#line 934 "/home/baptiste/Documents/projects/CityBuilder_THL/city/build/parser.cpp" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
   Parser ::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
   Parser ::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const signed char  Parser ::yypact_ninf_ = -23;

  const signed char  Parser ::yytable_ninf_ = -1;

  const signed char
   Parser ::yypact_[] =
  {
       2,   -23,   -15,     4,     4,    22,   -23,    43,    25,    19,
     -23,    21,   -23,     4,     4,     4,     4,    42,    20,   -23,
      -9,    -9,   -23,   -23,     6,     6,   -23,    30,    36,    37,
       4,   -23,    50,   -23,    42,    57,     5,     6,   -23,    42,
       4,   -23,    44,    17,   -23,     4,    31,   -23
  };

  const unsigned char
   Parser ::yydefact_[] =
  {
       0,    13,     0,     0,     0,     0,     2,     3,     0,     0,
      19,     0,     1,     0,     0,     0,     0,     0,     0,    14,
      16,    15,    17,    18,     8,     0,    11,     0,     0,     0,
       0,     9,     0,     4,     7,     0,     0,     0,     6,     0,
       0,    10,     0,     0,     5,     0,     0,    12
  };

  const signed char
   Parser ::yypgoto_[] =
  {
     -23,   -23,   -23,    13,   -23,   -22,    -3
  };

  const signed char
   Parser ::yydefgoto_[] =
  {
      -1,     5,     6,    27,    28,    31,     7
  };

  const unsigned char
   Parser ::yytable_[] =
  {
      10,    11,     8,    32,     9,    15,    16,     1,     2,     1,
      20,    21,    22,    23,     3,    41,     3,    13,    14,    15,
      16,     4,    12,     4,    18,    30,    40,    36,    17,    13,
      14,    15,    16,    13,    14,    15,    16,    43,    45,    34,
      29,    19,    46,    13,    14,    15,    16,    38,    33,    24,
      25,    47,    42,    26,    35,    13,    14,    15,    16,    37,
      39,     0,    44
  };

  const signed char
   Parser ::yycheck_[] =
  {
       3,     4,    17,    25,    19,    14,    15,     5,     6,     5,
      13,    14,    15,    16,    12,    37,    12,    12,    13,    14,
      15,    19,     0,    19,     5,    19,    21,    30,     3,    12,
      13,    14,    15,    12,    13,    14,    15,    40,    21,     3,
      20,    20,    45,    12,    13,    14,    15,    34,    18,     7,
       8,    20,    39,    11,    17,    12,    13,    14,    15,     9,
       3,    -1,    18
  };

  const unsigned char
   Parser ::yystos_[] =
  {
       0,     5,     6,    12,    19,    23,    24,    28,    17,    19,
      28,    28,     0,    12,    13,    14,    15,     3,     5,    20,
      28,    28,    28,    28,     7,     8,    11,    25,    26,    20,
      19,    27,    27,    18,     3,    17,    28,     9,    25,     3,
      21,    27,    25,    28,    18,    21,    28,    20
  };

  const unsigned char
   Parser ::yyr1_[] =
  {
       0,    22,    23,    24,    24,    24,    25,    25,    26,    26,
      26,    26,    27,    28,    28,    28,    28,    28,    28,    28
  };

  const unsigned char
   Parser ::yyr2_[] =
  {
       0,     2,     1,     1,     5,     8,     3,     2,     1,     2,
       4,     1,     7,     1,     3,     3,     3,     3,     3,     2
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const  Parser ::yytname_[] =
  {
  "$end", "error", "$undefined", "NL", "END", "NUMBER", "build", "maison",
  "route", "arrow", "comcourt", "com", "'-'", "'+'", "'*'", "'/'", "NEG",
  "'{'", "'}'", "'('", "')'", "','", "$accept", "programme", "instruction",
  "traitements", "traitement", "coordonnee", "operation", YY_NULLPTR
  };


  const unsigned char
   Parser ::yyrline_[] =
  {
       0,    57,    57,    62,    65,    73,    84,    88,    93,    97,
     101,   104,   111,   116,   119,   122,   125,   128,   131,   134
  };

  // Print the state stack on the debug stream.
  void
   Parser ::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
   Parser ::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
   Parser ::token_number_type
   Parser ::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      19,    20,    14,    13,    21,    12,     2,    15,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    17,     2,    18,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    16
    };
    const unsigned int user_token_number_max_ = 267;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // yy
#line 1284 "/home/baptiste/Documents/projects/CityBuilder_THL/city/build/parser.cpp" // lalr1.cc:1167
#line 138 "parser/parser.yy" // lalr1.cc:1168


void yy::Parser::error( const location_type &l, const std::string & err_msg) {
    std::cerr << "Erreur : " << l << ", " << err_msg << std::endl;
}
