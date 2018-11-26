/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with RC or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum RCtokentype {
     VARIABLE = 258,
     SYMBOL = 259,
     DOUBLE = 260,
     INTEGER = 261,
     LOGAND = 262,
     LOGOR = 263,
     LOGXOR = 264,
     LOGNOT = 265,
     EQUAL = 266,
     NOT_EQUAL = 267,
     NODE = 268,
     GTEQ = 269,
     LTEQ = 270
   };
#endif
/* Tokens.  */
#define VARIABLE 258
#define SYMBOL 259
#define DOUBLE 260
#define INTEGER 261
#define LOGAND 262
#define LOGOR 263
#define LOGXOR 264
#define LOGNOT 265
#define EQUAL 266
#define NOT_EQUAL 267
#define NODE 268
#define GTEQ 269
#define LTEQ 270




/* Copy the first part of user declarations.  */
#line 2 "RunConfigGrammar.y"

/* 
   MaBoSS (Markov Boolean Stochastic Simulator)
   Copyright (C) 2011 Institut Curie, 26 rue d'Ulm, Paris, France
   
   MaBoSS is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.
   
   MaBoSS is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.
   
   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA 
*/

/*
   Module:
     RunConfigGrammar.l

   Authors:
     Eric Viara <viara@sysra.com>
     Gautier Stoll <gautier.stoll@curie.fr>
 
   Date:
     January-March 2011
     updated to add extended initial conditions: October 2014
*/

#include "BooleanNetwork.h"
#include "RunConfig.h"

extern int RClex();

static void RCerror(const char *s);
static Network* network;

extern std::string RC_error_head();


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 46 "RunConfigGrammar.y"
{
  Expression* expr;
  char* str;
  double d;
  long long l;
  std::vector<const Node*>* node_list;
  std::vector<Expression*>* expr_list;
  IStateGroup::ProbaIState* istate_expr;
  std::vector<IStateGroup::ProbaIState*>* istate_expr_list;
}
/* Line 193 of yacc.c.  */
#line 181 "RunConfigGrammar.tab.c"
	YYSTYPE;
# define RCstype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 194 "RunConfigGrammar.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 RCtype_uint8;
#else
typedef unsigned char RCtype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 RCtype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char RCtype_int8;
#else
typedef short int RCtype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 RCtype_uint16;
#else
typedef unsigned short int RCtype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 RCtype_int16;
#else
typedef short int RCtype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined RCoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined RCoverflow || YYERROR_VERBOSE */


#if (! defined RCoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union RCalloc
{
  RCtype_int16 RCss;
  YYSTYPE RCvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union RCalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (RCtype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T RCi;				\
	  for (RCi = 0; RCi < (Count); RCi++)	\
	    (To)[RCi] = (From)[RCi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T RCnewbytes;						\
	YYCOPY (&RCptr->Stack, Stack, RCsize);				\
	Stack = &RCptr->Stack;						\
	RCnewbytes = RCstacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	RCptr += RCnewbytes / sizeof (*RCptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   86

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  53
/* YYNRULES -- Number of states.  */
#define YYNSTATES  101

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   270

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? RCtranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const RCtype_uint8 RCtranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    26,     2,     2,     2,     2,     2,     2,
      22,    23,    27,    24,    21,    25,    18,    28,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    33,    16,
      29,    17,    30,    32,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    19,     2,    20,    31,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const RCtype_uint8 RCprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    16,    21,
      28,    35,    39,    41,    45,    47,    51,    56,    58,    62,
      67,    69,    71,    73,    77,    79,    81,    84,    87,    90,
      93,    95,    99,   103,   105,   109,   113,   115,   119,   123,
     127,   131,   133,   137,   141,   143,   147,   149,   153,   155,
     159,   163,   165,   171
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const RCtype_int8 RCrhs[] =
{
      35,     0,    -1,    36,    -1,    35,    36,    -1,    44,    -1,
      37,    -1,    38,    -1,    16,    -1,     4,    17,    56,    16,
      -1,     4,    18,     4,    17,    56,    16,    -1,    39,    18,
       4,    17,    41,    16,    -1,    19,    40,    20,    -1,     4,
      -1,    40,    21,     4,    -1,    42,    -1,    41,    21,    42,
      -1,    45,    19,    43,    20,    -1,    45,    -1,    43,    21,
      45,    -1,     3,    17,    56,    16,    -1,     6,    -1,     5,
      -1,     3,    -1,    22,    56,    23,    -1,    45,    -1,    46,
      -1,    24,    47,    -1,    25,    47,    -1,    26,    47,    -1,
      10,    47,    -1,    47,    -1,    48,    27,    47,    -1,    48,
      28,    47,    -1,    48,    -1,    49,    24,    48,    -1,    49,
      25,    48,    -1,    49,    -1,    50,    29,    49,    -1,    50,
      30,    49,    -1,    50,    15,    49,    -1,    50,    14,    49,
      -1,    50,    -1,    51,    11,    50,    -1,    51,    12,    50,
      -1,    51,    -1,    52,     7,    51,    -1,    52,    -1,    53,
       8,    52,    -1,    53,    -1,    54,     9,    53,    -1,    54,
      31,    53,    -1,    54,    -1,    54,    32,    56,    33,    55,
      -1,    55,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const RCtype_uint16 RCrline[] =
{
       0,    84,    84,    87,    92,    93,    94,    95,    98,   106,
     133,   146,   152,   157,   164,   169,   176,   182,   187,   194,
     203,   207,   211,   215,   221,   227,   231,   235,   239,   243,
     249,   253,   257,   263,   267,   271,   277,   281,   285,   289,
     293,   299,   303,   307,   313,   317,   323,   327,   333,   337,
     341,   347,   351,   357
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const RCtname[] =
{
  "$end", "error", "$undefined", "VARIABLE", "SYMBOL", "DOUBLE",
  "INTEGER", "LOGAND", "LOGOR", "LOGXOR", "LOGNOT", "EQUAL", "NOT_EQUAL",
  "NODE", "GTEQ", "LTEQ", "';'", "'='", "'.'", "'['", "']'", "','", "'('",
  "')'", "'+'", "'-'", "'!'", "'*'", "'/'", "'<'", "'>'", "'^'", "'?'",
  "':'", "$accept", "translation_unit", "decl", "runconfig_decl",
  "node_attr_decl", "symbol_istate_list", "symbol_list",
  "istate_expression_list", "istate_expression", "expression_list",
  "var_decl", "primary_expression", "postfix_expression",
  "unary_expression", "multiplicative_expression", "additive_expression",
  "relational_expression", "equality_expression", "logical_and_expression",
  "logical_or_expression", "logical_xor_expression",
  "conditional_expression", "expression", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const RCtype_uint16 RCtoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,    59,    61,    46,    91,
      93,    44,    40,    41,    43,    45,    33,    42,    47,    60,
      62,    94,    63,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const RCtype_uint8 RCr1[] =
{
       0,    34,    35,    35,    36,    36,    36,    36,    37,    38,
      38,    39,    40,    40,    41,    41,    42,    43,    43,    44,
      45,    45,    45,    45,    46,    47,    47,    47,    47,    47,
      48,    48,    48,    49,    49,    49,    50,    50,    50,    50,
      50,    51,    51,    51,    52,    52,    53,    53,    54,    54,
      54,    55,    55,    56
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const RCtype_uint8 RCr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     4,     6,
       6,     3,     1,     3,     1,     3,     4,     1,     3,     4,
       1,     1,     1,     3,     1,     1,     2,     2,     2,     2,
       1,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     1,     3,     1,     3,
       3,     1,     5,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const RCtype_uint8 RCdefact[] =
{
       0,     0,     0,     7,     0,     0,     2,     5,     6,     0,
       4,     0,     0,     0,    12,     0,     1,     3,     0,    22,
      21,    20,     0,     0,     0,     0,     0,    24,    25,    30,
      33,    36,    41,    44,    46,    48,    51,    53,     0,     0,
       0,    11,     0,     0,    29,     0,    26,    27,    28,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    19,     8,     0,    13,     0,    23,
      31,    32,    34,    35,    40,    39,    37,    38,    42,    43,
      45,    47,    49,    50,     0,     0,     0,    14,     0,     0,
       9,    10,     0,     0,    52,    15,     0,    17,    16,     0,
      18
};

/* YYDEFGOTO[NTERM-NUM].  */
static const RCtype_int8 RCdefgoto[] =
{
      -1,     5,     6,     7,     8,     9,    15,    86,    87,    96,
      10,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -68
static const RCtype_int8 RCpact[] =
{
      41,   -14,    -8,   -68,    13,    24,   -68,   -68,   -68,    -5,
     -68,     9,     9,    38,   -68,    32,   -68,   -68,    42,   -68,
     -68,   -68,     9,     9,     9,     9,     9,   -68,   -68,   -68,
      28,    34,    -7,    50,    64,    65,     7,   -68,    56,    58,
      59,   -68,    71,    60,   -68,    55,   -68,   -68,   -68,     9,
       9,     9,     9,     9,     9,     9,     9,     9,     9,     9,
       9,     9,     9,     9,   -68,   -68,     9,   -68,    15,   -68,
     -68,   -68,    28,    28,    34,    34,    34,    34,    -7,    -7,
      50,    64,    65,    65,    46,    66,    20,   -68,    61,     9,
     -68,   -68,    15,    15,   -68,   -68,    43,   -68,   -68,    15,
     -68
};

/* YYPGOTO[NTERM-NUM].  */
static const RCtype_int8 RCpgoto[] =
{
     -68,   -68,    76,   -68,   -68,   -68,   -68,   -68,    -9,   -68,
     -68,   -67,   -68,   -20,    14,    -6,    10,    25,    26,     8,
     -68,    -4,   -12
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const RCtype_uint8 RCtable[] =
{
      39,    88,    44,    11,    46,    47,    48,    53,    54,    12,
      13,    45,    19,    18,    20,    21,    61,    14,    19,    22,
      20,    21,    55,    56,    16,    88,    97,     1,     2,    70,
      71,    23,   100,    24,    25,    26,    91,    23,    62,    63,
       3,    92,    40,     4,     1,     2,    43,    74,    75,    76,
      77,    84,    41,    42,    85,    49,    50,     3,    51,    52,
       4,    57,    58,    98,    99,    72,    73,    78,    79,    82,
      83,    59,    64,    60,    65,    67,    66,    68,    69,    89,
      93,    17,    90,    95,    80,    94,    81
};

static const RCtype_uint8 RCcheck[] =
{
      12,    68,    22,    17,    24,    25,    26,    14,    15,    17,
      18,    23,     3,    18,     5,     6,     9,     4,     3,    10,
       5,     6,    29,    30,     0,    92,    93,     3,     4,    49,
      50,    22,    99,    24,    25,    26,    16,    22,    31,    32,
      16,    21,     4,    19,     3,     4,     4,    53,    54,    55,
      56,    63,    20,    21,    66,    27,    28,    16,    24,    25,
      19,    11,    12,    20,    21,    51,    52,    57,    58,    61,
      62,     7,    16,     8,    16,     4,    17,    17,    23,    33,
      19,     5,    16,    92,    59,    89,    60
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const RCtype_uint8 RCstos[] =
{
       0,     3,     4,    16,    19,    35,    36,    37,    38,    39,
      44,    17,    17,    18,     4,    40,     0,    36,    18,     3,
       5,     6,    10,    22,    24,    25,    26,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    56,
       4,    20,    21,     4,    47,    56,    47,    47,    47,    27,
      28,    24,    25,    14,    15,    29,    30,    11,    12,     7,
       8,     9,    31,    32,    16,    16,    17,     4,    17,    23,
      47,    47,    48,    48,    49,    49,    49,    49,    50,    50,
      51,    52,    53,    53,    56,    56,    41,    42,    45,    33,
      16,    16,    21,    19,    55,    42,    43,    45,    20,    21,
      45
};

#define RCerrok		(RCerrstatus = 0)
#define RCclearin	(RCchar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto RCacceptlab
#define YYABORT		goto RCabortlab
#define YYERROR		goto RCerrorlab


/* Like YYERROR except do call RCerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto RCerrlab

#define YYRECOVERING()  (!!RCerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (RCchar == YYEMPTY && RClen == 1)				\
    {								\
      RCchar = (Token);						\
      RClval = (Value);						\
      RCtoken = YYTRANSLATE (RCchar);				\
      YYPOPSTACK (1);						\
      goto RCbackup;						\
    }								\
  else								\
    {								\
      RCerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `RClex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX RClex (YYLEX_PARAM)
#else
# define YYLEX RClex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (RCdebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (RCdebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      RC_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
RC_symbol_value_print (FILE *RCoutput, int RCtype, YYSTYPE const * const RCvaluep)
#else
static void
RC_symbol_value_print (RCoutput, RCtype, RCvaluep)
    FILE *RCoutput;
    int RCtype;
    YYSTYPE const * const RCvaluep;
#endif
{
  if (!RCvaluep)
    return;
# ifdef YYPRINT
  if (RCtype < YYNTOKENS)
    YYPRINT (RCoutput, RCtoknum[RCtype], *RCvaluep);
# else
  YYUSE (RCoutput);
# endif
  switch (RCtype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
RC_symbol_print (FILE *RCoutput, int RCtype, YYSTYPE const * const RCvaluep)
#else
static void
RC_symbol_print (RCoutput, RCtype, RCvaluep)
    FILE *RCoutput;
    int RCtype;
    YYSTYPE const * const RCvaluep;
#endif
{
  if (RCtype < YYNTOKENS)
    YYFPRINTF (RCoutput, "token %s (", RCtname[RCtype]);
  else
    YYFPRINTF (RCoutput, "nterm %s (", RCtname[RCtype]);

  RC_symbol_value_print (RCoutput, RCtype, RCvaluep);
  YYFPRINTF (RCoutput, ")");
}

/*------------------------------------------------------------------.
| RC_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
RC_stack_print (RCtype_int16 *bottom, RCtype_int16 *top)
#else
static void
RC_stack_print (bottom, top)
    RCtype_int16 *bottom;
    RCtype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (RCdebug)							\
    RC_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
RC_reduce_print (YYSTYPE *RCvsp, int RCrule)
#else
static void
RC_reduce_print (RCvsp, RCrule)
    YYSTYPE *RCvsp;
    int RCrule;
#endif
{
  int RCnrhs = RCr2[RCrule];
  int RCi;
  unsigned long int RClno = RCrline[RCrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     RCrule - 1, RClno);
  /* The symbols being reduced.  */
  for (RCi = 0; RCi < RCnrhs; RCi++)
    {
      fprintf (stderr, "   $%d = ", RCi + 1);
      RC_symbol_print (stderr, RCrhs[RCprhs[RCrule] + RCi],
		       &(RCvsp[(RCi + 1) - (RCnrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (RCdebug)				\
    RC_reduce_print (RCvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int RCdebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef RCstrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define RCstrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
RCstrlen (const char *RCstr)
#else
static YYSIZE_T
RCstrlen (RCstr)
    const char *RCstr;
#endif
{
  YYSIZE_T RClen;
  for (RClen = 0; RCstr[RClen]; RClen++)
    continue;
  return RClen;
}
#  endif
# endif

# ifndef RCstpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define RCstpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
RCstpcpy (char *RCdest, const char *RCsrc)
#else
static char *
RCstpcpy (RCdest, RCsrc)
    char *RCdest;
    const char *RCsrc;
#endif
{
  char *RCd = RCdest;
  const char *RCs = RCsrc;

  while ((*RCd++ = *RCs++) != '\0')
    continue;

  return RCd - 1;
}
#  endif
# endif

# ifndef RCtnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for RCerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from RCtname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
RCtnamerr (char *RCres, const char *RCstr)
{
  if (*RCstr == '"')
    {
      YYSIZE_T RCn = 0;
      char const *RCp = RCstr;

      for (;;)
	switch (*++RCp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++RCp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (RCres)
	      RCres[RCn] = *RCp;
	    RCn++;
	    break;

	  case '"':
	    if (RCres)
	      RCres[RCn] = '\0';
	    return RCn;
	  }
    do_not_strip_quotes: ;
    }

  if (! RCres)
    return RCstrlen (RCstr);

  return RCstpcpy (RCres, RCstr) - RCres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
RCsyntax_error (char *RCresult, int RCstate, int RCchar)
{
  int RCn = RCpact[RCstate];

  if (! (YYPACT_NINF < RCn && RCn <= YYLAST))
    return 0;
  else
    {
      int RCtype = YYTRANSLATE (RCchar);
      YYSIZE_T RCsize0 = RCtnamerr (0, RCtname[RCtype]);
      YYSIZE_T RCsize = RCsize0;
      YYSIZE_T RCsize1;
      int RCsize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *RCarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int RCx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *RCfmt;
      char const *RCf;
      static char const RCunexpected[] = "syntax error, unexpected %s";
      static char const RCexpecting[] = ", expecting %s";
      static char const RCor[] = " or %s";
      char RCformat[sizeof RCunexpected
		    + sizeof RCexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof RCor - 1))];
      char const *RCprefix = RCexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int RCxbegin = RCn < 0 ? -RCn : 0;

      /* Stay within bounds of both RCcheck and RCtname.  */
      int RCchecklim = YYLAST - RCn + 1;
      int RCxend = RCchecklim < YYNTOKENS ? RCchecklim : YYNTOKENS;
      int RCcount = 1;

      RCarg[0] = RCtname[RCtype];
      RCfmt = RCstpcpy (RCformat, RCunexpected);

      for (RCx = RCxbegin; RCx < RCxend; ++RCx)
	if (RCcheck[RCx + RCn] == RCx && RCx != YYTERROR)
	  {
	    if (RCcount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		RCcount = 1;
		RCsize = RCsize0;
		RCformat[sizeof RCunexpected - 1] = '\0';
		break;
	      }
	    RCarg[RCcount++] = RCtname[RCx];
	    RCsize1 = RCsize + RCtnamerr (0, RCtname[RCx]);
	    RCsize_overflow |= (RCsize1 < RCsize);
	    RCsize = RCsize1;
	    RCfmt = RCstpcpy (RCfmt, RCprefix);
	    RCprefix = RCor;
	  }

      RCf = YY_(RCformat);
      RCsize1 = RCsize + RCstrlen (RCf);
      RCsize_overflow |= (RCsize1 < RCsize);
      RCsize = RCsize1;

      if (RCsize_overflow)
	return YYSIZE_MAXIMUM;

      if (RCresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *RCp = RCresult;
	  int RCi = 0;
	  while ((*RCp = *RCf) != '\0')
	    {
	      if (*RCp == '%' && RCf[1] == 's' && RCi < RCcount)
		{
		  RCp += RCtnamerr (RCp, RCarg[RCi++]);
		  RCf += 2;
		}
	      else
		{
		  RCp++;
		  RCf++;
		}
	    }
	}
      return RCsize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
RCdestruct (const char *RCmsg, int RCtype, YYSTYPE *RCvaluep)
#else
static void
RCdestruct (RCmsg, RCtype, RCvaluep)
    const char *RCmsg;
    int RCtype;
    YYSTYPE *RCvaluep;
#endif
{
  YYUSE (RCvaluep);

  if (!RCmsg)
    RCmsg = "Deleting";
  YY_SYMBOL_PRINT (RCmsg, RCtype, RCvaluep, RClocationp);

  switch (RCtype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int RCparse (void *YYPARSE_PARAM);
#else
int RCparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int RCparse (void);
#else
int RCparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int RCchar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE RClval;

/* Number of syntax errors so far.  */
int RCnerrs;



/*----------.
| RCparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
RCparse (void *YYPARSE_PARAM)
#else
int
RCparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
RCparse (void)
#else
int
RCparse ()

#endif
#endif
{
  
  int RCstate;
  int RCn;
  int RCresult;
  /* Number of tokens to shift before error messages enabled.  */
  int RCerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int RCtoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char RCmsgbuf[128];
  char *RCmsg = RCmsgbuf;
  YYSIZE_T RCmsg_alloc = sizeof RCmsgbuf;
#endif

  /* Three stacks and their tools:
     `RCss': related to states,
     `RCvs': related to semantic values,
     `RCls': related to locations.

     Refer to the stacks thru separate pointers, to allow RCoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  RCtype_int16 RCssa[YYINITDEPTH];
  RCtype_int16 *RCss = RCssa;
  RCtype_int16 *RCssp;

  /* The semantic value stack.  */
  YYSTYPE RCvsa[YYINITDEPTH];
  YYSTYPE *RCvs = RCvsa;
  YYSTYPE *RCvsp;



#define YYPOPSTACK(N)   (RCvsp -= (N), RCssp -= (N))

  YYSIZE_T RCstacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE RCval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int RClen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  RCstate = 0;
  RCerrstatus = 0;
  RCnerrs = 0;
  RCchar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  RCssp = RCss;
  RCvsp = RCvs;

  goto RCsetstate;

/*------------------------------------------------------------.
| RCnewstate -- Push a new state, which is found in RCstate.  |
`------------------------------------------------------------*/
 RCnewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  RCssp++;

 RCsetstate:
  *RCssp = RCstate;

  if (RCss + RCstacksize - 1 <= RCssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T RCsize = RCssp - RCss + 1;

#ifdef RCoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *RCvs1 = RCvs;
	RCtype_int16 *RCss1 = RCss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if RCoverflow is a macro.  */
	RCoverflow (YY_("memory exhausted"),
		    &RCss1, RCsize * sizeof (*RCssp),
		    &RCvs1, RCsize * sizeof (*RCvsp),

		    &RCstacksize);

	RCss = RCss1;
	RCvs = RCvs1;
      }
#else /* no RCoverflow */
# ifndef YYSTACK_RELOCATE
      goto RCexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= RCstacksize)
	goto RCexhaustedlab;
      RCstacksize *= 2;
      if (YYMAXDEPTH < RCstacksize)
	RCstacksize = YYMAXDEPTH;

      {
	RCtype_int16 *RCss1 = RCss;
	union RCalloc *RCptr =
	  (union RCalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (RCstacksize));
	if (! RCptr)
	  goto RCexhaustedlab;
	YYSTACK_RELOCATE (RCss);
	YYSTACK_RELOCATE (RCvs);

#  undef YYSTACK_RELOCATE
	if (RCss1 != RCssa)
	  YYSTACK_FREE (RCss1);
      }
# endif
#endif /* no RCoverflow */

      RCssp = RCss + RCsize - 1;
      RCvsp = RCvs + RCsize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) RCstacksize));

      if (RCss + RCstacksize - 1 <= RCssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", RCstate));

  goto RCbackup;

/*-----------.
| RCbackup.  |
`-----------*/
RCbackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  RCn = RCpact[RCstate];
  if (RCn == YYPACT_NINF)
    goto RCdefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (RCchar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      RCchar = YYLEX;
    }

  if (RCchar <= YYEOF)
    {
      RCchar = RCtoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      RCtoken = YYTRANSLATE (RCchar);
      YY_SYMBOL_PRINT ("Next token is", RCtoken, &RClval, &RClloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  RCn += RCtoken;
  if (RCn < 0 || YYLAST < RCn || RCcheck[RCn] != RCtoken)
    goto RCdefault;
  RCn = RCtable[RCn];
  if (RCn <= 0)
    {
      if (RCn == 0 || RCn == YYTABLE_NINF)
	goto RCerrlab;
      RCn = -RCn;
      goto RCreduce;
    }

  if (RCn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (RCerrstatus)
    RCerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", RCtoken, &RClval, &RClloc);

  /* Discard the shifted token unless it is eof.  */
  if (RCchar != YYEOF)
    RCchar = YYEMPTY;

  RCstate = RCn;
  *++RCvsp = RClval;

  goto RCnewstate;


/*-----------------------------------------------------------.
| RCdefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
RCdefault:
  RCn = RCdefact[RCstate];
  if (RCn == 0)
    goto RCerrlab;
  goto RCreduce;


/*-----------------------------.
| RCreduce -- Do a reduction.  |
`-----------------------------*/
RCreduce:
  /* RCn is the number of a rule to reduce with.  */
  RClen = RCr2[RCn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  RCval = RCvsp[1-RClen];


  YY_REDUCE_PRINT (RCn);
  switch (RCn)
    {
        case 2:
#line 85 "RunConfigGrammar.y"
    {
;}
    break;

  case 3:
#line 88 "RunConfigGrammar.y"
    {
;}
    break;

  case 8:
#line 99 "RunConfigGrammar.y"
    {
  NetworkState network_state;
  double value = (RCvsp[(3) - (4)].expr)->eval(NULL, network_state);
  RunConfig::getInstance()->setParameter((RCvsp[(1) - (4)].str), value);
;}
    break;

  case 9:
#line 107 "RunConfigGrammar.y"
    {
  Node* node = network->getNode((RCvsp[(1) - (6)].str));
  NetworkState network_state;
  double value = (RCvsp[(5) - (6)].expr)->eval(NULL, network_state);
  if (!strcasecmp((RCvsp[(3) - (6)].str), "istate")) {
    if (backward_istate) {
      node->setIState((bool)value);
    } else {
      if (value < 0) {
	new IStateGroup(node);
      } else {
	new IStateGroup(node, (RCvsp[(5) - (6)].expr));
      }
    }
  } else if (!strcasecmp((RCvsp[(3) - (6)].str), "is_internal")) {
    node->isInternal((bool)value);
  } else if (!strcasecmp((RCvsp[(3) - (6)].str), "refstate")) {
    if (value < 0) {
      node->setReference(false);
    } else {
      node->setReferenceState((NodeState)value);
    }
  } else {
    throw BNException(std::string(RC_error_head() + "invalid node attribute: ") + (RCvsp[(3) - (6)].str) + ", valid attributes are: istate or is_internal");
  }
;}
    break;

  case 10:
#line 134 "RunConfigGrammar.y"
    {
  if (strcasecmp((RCvsp[(3) - (6)].str), "istate")) {
    throw BNException(std::string(RC_error_head() + "invalid node group attribute: ") + (RCvsp[(3) - (6)].str) + ", valid attribute is istate");
  }
  std::string error_msg;
  new IStateGroup((RCvsp[(1) - (6)].node_list), (RCvsp[(5) - (6)].istate_expr_list), error_msg);
  if (error_msg.length() > 0) {
    throw BNException(std::string(RC_error_head() + error_msg));
  }
;}
    break;

  case 11:
#line 147 "RunConfigGrammar.y"
    {
  (RCval.node_list) = (RCvsp[(2) - (3)].node_list);
;}
    break;

  case 12:
#line 153 "RunConfigGrammar.y"
    {
  (RCval.node_list) = new std::vector<const Node*>();
  (RCval.node_list)->push_back(network->getNode((RCvsp[(1) - (1)].str)));
;}
    break;

  case 13:
#line 158 "RunConfigGrammar.y"
    {
  (RCval.node_list) = (RCvsp[(1) - (3)].node_list);
  (RCval.node_list)->push_back(network->getNode((RCvsp[(3) - (3)].str)));
;}
    break;

  case 14:
#line 165 "RunConfigGrammar.y"
    {
  (RCval.istate_expr_list) = new std::vector<IStateGroup::ProbaIState*>();
  (RCval.istate_expr_list)->push_back((RCvsp[(1) - (1)].istate_expr));
;}
    break;

  case 15:
#line 170 "RunConfigGrammar.y"
    {
  (RCval.istate_expr_list) = (RCvsp[(1) - (3)].istate_expr_list);
  (RCval.istate_expr_list)->push_back((RCvsp[(3) - (3)].istate_expr));
;}
    break;

  case 16:
#line 177 "RunConfigGrammar.y"
    {
  (RCval.istate_expr) = new IStateGroup::ProbaIState((RCvsp[(1) - (4)].expr), (RCvsp[(3) - (4)].expr_list));
;}
    break;

  case 17:
#line 183 "RunConfigGrammar.y"
    {
  (RCval.expr_list) = new std::vector<Expression*>();
  (RCval.expr_list)->push_back((RCvsp[(1) - (1)].expr));
;}
    break;

  case 18:
#line 188 "RunConfigGrammar.y"
    {
  (RCval.expr_list) = (RCvsp[(1) - (3)].expr_list);
  (RCval.expr_list)->push_back((RCvsp[(3) - (3)].expr));
;}
    break;

  case 19:
#line 195 "RunConfigGrammar.y"
    {
  SymbolTable* symtab = SymbolTable::getInstance();
  const Symbol* symbol = symtab->getOrMakeSymbol((RCvsp[(1) - (4)].str));
  NetworkState dummy_state;
  symtab->setSymbolValue(symbol, (RCvsp[(3) - (4)].expr)->eval(NULL, dummy_state));
;}
    break;

  case 20:
#line 204 "RunConfigGrammar.y"
    {
  (RCval.expr) = new ConstantExpression((RCvsp[(1) - (1)].l));
;}
    break;

  case 21:
#line 208 "RunConfigGrammar.y"
    {
  (RCval.expr) = new ConstantExpression((RCvsp[(1) - (1)].d));
;}
    break;

  case 22:
#line 212 "RunConfigGrammar.y"
    {
  (RCval.expr) = new SymbolExpression(SymbolTable::getInstance()->getOrMakeSymbol((RCvsp[(1) - (1)].str)));
;}
    break;

  case 23:
#line 216 "RunConfigGrammar.y"
    {
  (RCval.expr) = new ParenthesisExpression((RCvsp[(2) - (3)].expr));
;}
    break;

  case 24:
#line 222 "RunConfigGrammar.y"
    {
  (RCval.expr) = (RCvsp[(1) - (1)].expr);
;}
    break;

  case 25:
#line 228 "RunConfigGrammar.y"
    {
  (RCval.expr) = (RCvsp[(1) - (1)].expr);
;}
    break;

  case 26:
#line 232 "RunConfigGrammar.y"
    {
  (RCval.expr) = (RCvsp[(2) - (2)].expr);
;}
    break;

  case 27:
#line 236 "RunConfigGrammar.y"
    {
  (RCval.expr) = new SubExpression(new ConstantExpression(0.0), (RCvsp[(2) - (2)].expr));
;}
    break;

  case 28:
#line 240 "RunConfigGrammar.y"
    {
  (RCval.expr) = new NotLogicalExpression((RCvsp[(2) - (2)].expr));
;}
    break;

  case 29:
#line 244 "RunConfigGrammar.y"
    {
  (RCval.expr) = new NotLogicalExpression((RCvsp[(2) - (2)].expr));
;}
    break;

  case 30:
#line 250 "RunConfigGrammar.y"
    {
  (RCval.expr) = (RCvsp[(1) - (1)].expr);
;}
    break;

  case 31:
#line 254 "RunConfigGrammar.y"
    {
  (RCval.expr) = new MulExpression((RCvsp[(1) - (3)].expr), (RCvsp[(3) - (3)].expr));
;}
    break;

  case 32:
#line 258 "RunConfigGrammar.y"
    {
  (RCval.expr) = new DivExpression((RCvsp[(1) - (3)].expr), (RCvsp[(3) - (3)].expr));
;}
    break;

  case 33:
#line 264 "RunConfigGrammar.y"
    {
  (RCval.expr) = (RCvsp[(1) - (1)].expr);
;}
    break;

  case 34:
#line 268 "RunConfigGrammar.y"
    {
  (RCval.expr) = new AddExpression((RCvsp[(1) - (3)].expr), (RCvsp[(3) - (3)].expr));
;}
    break;

  case 35:
#line 272 "RunConfigGrammar.y"
    {
  (RCval.expr) = new SubExpression((RCvsp[(1) - (3)].expr), (RCvsp[(3) - (3)].expr));
;}
    break;

  case 36:
#line 278 "RunConfigGrammar.y"
    {
  (RCval.expr) = (RCvsp[(1) - (1)].expr);
;}
    break;

  case 37:
#line 282 "RunConfigGrammar.y"
    {
  (RCval.expr) = new LetterExpression((RCvsp[(1) - (3)].expr), (RCvsp[(3) - (3)].expr));
;}
    break;

  case 38:
#line 286 "RunConfigGrammar.y"
    {
  (RCval.expr) = new GreaterExpression((RCvsp[(1) - (3)].expr), (RCvsp[(3) - (3)].expr));
;}
    break;

  case 39:
#line 290 "RunConfigGrammar.y"
    {
  (RCval.expr) = new LetterOrEqualExpression((RCvsp[(1) - (3)].expr), (RCvsp[(3) - (3)].expr));
;}
    break;

  case 40:
#line 294 "RunConfigGrammar.y"
    {
  (RCval.expr) = new GreaterOrEqualExpression((RCvsp[(1) - (3)].expr), (RCvsp[(3) - (3)].expr));
;}
    break;

  case 41:
#line 300 "RunConfigGrammar.y"
    {
  (RCval.expr) = (RCvsp[(1) - (1)].expr);
;}
    break;

  case 42:
#line 304 "RunConfigGrammar.y"
    {
  (RCval.expr) = new EqualExpression((RCvsp[(1) - (3)].expr), (RCvsp[(3) - (3)].expr));
;}
    break;

  case 43:
#line 308 "RunConfigGrammar.y"
    {
  (RCval.expr) = new NotEqualExpression((RCvsp[(1) - (3)].expr), (RCvsp[(3) - (3)].expr));
;}
    break;

  case 44:
#line 314 "RunConfigGrammar.y"
    {
  (RCval.expr) = (RCvsp[(1) - (1)].expr);
;}
    break;

  case 45:
#line 318 "RunConfigGrammar.y"
    {
  (RCval.expr) = new AndLogicalExpression((RCvsp[(1) - (3)].expr), (RCvsp[(3) - (3)].expr));
;}
    break;

  case 46:
#line 324 "RunConfigGrammar.y"
    {
  (RCval.expr) = (RCvsp[(1) - (1)].expr);
;}
    break;

  case 47:
#line 328 "RunConfigGrammar.y"
    {
  (RCval.expr) = new OrLogicalExpression((RCvsp[(1) - (3)].expr), (RCvsp[(3) - (3)].expr));
;}
    break;

  case 48:
#line 334 "RunConfigGrammar.y"
    {
  (RCval.expr) = (RCvsp[(1) - (1)].expr);
;}
    break;

  case 49:
#line 338 "RunConfigGrammar.y"
    {
  (RCval.expr) = new XorLogicalExpression((RCvsp[(1) - (3)].expr), (RCvsp[(3) - (3)].expr));
;}
    break;

  case 50:
#line 342 "RunConfigGrammar.y"
    {
  (RCval.expr) = new XorLogicalExpression((RCvsp[(1) - (3)].expr), (RCvsp[(3) - (3)].expr));
;}
    break;

  case 51:
#line 348 "RunConfigGrammar.y"
    {
  (RCval.expr) = (RCvsp[(1) - (1)].expr);
;}
    break;

  case 52:
#line 352 "RunConfigGrammar.y"
    {
  (RCval.expr) = new CondExpression((RCvsp[(1) - (5)].expr), (RCvsp[(3) - (5)].expr), (RCvsp[(5) - (5)].expr));
;}
    break;

  case 53:
#line 358 "RunConfigGrammar.y"
    {
  (RCval.expr) = (RCvsp[(1) - (1)].expr);
;}
    break;


/* Line 1267 of yacc.c.  */
#line 1850 "RunConfigGrammar.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", RCr1[RCn], &RCval, &RCloc);

  YYPOPSTACK (RClen);
  RClen = 0;
  YY_STACK_PRINT (RCss, RCssp);

  *++RCvsp = RCval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  RCn = RCr1[RCn];

  RCstate = RCpgoto[RCn - YYNTOKENS] + *RCssp;
  if (0 <= RCstate && RCstate <= YYLAST && RCcheck[RCstate] == *RCssp)
    RCstate = RCtable[RCstate];
  else
    RCstate = RCdefgoto[RCn - YYNTOKENS];

  goto RCnewstate;


/*------------------------------------.
| RCerrlab -- here on detecting error |
`------------------------------------*/
RCerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!RCerrstatus)
    {
      ++RCnerrs;
#if ! YYERROR_VERBOSE
      RCerror (YY_("syntax error"));
#else
      {
	YYSIZE_T RCsize = RCsyntax_error (0, RCstate, RCchar);
	if (RCmsg_alloc < RCsize && RCmsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T RCalloc = 2 * RCsize;
	    if (! (RCsize <= RCalloc && RCalloc <= YYSTACK_ALLOC_MAXIMUM))
	      RCalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (RCmsg != RCmsgbuf)
	      YYSTACK_FREE (RCmsg);
	    RCmsg = (char *) YYSTACK_ALLOC (RCalloc);
	    if (RCmsg)
	      RCmsg_alloc = RCalloc;
	    else
	      {
		RCmsg = RCmsgbuf;
		RCmsg_alloc = sizeof RCmsgbuf;
	      }
	  }

	if (0 < RCsize && RCsize <= RCmsg_alloc)
	  {
	    (void) RCsyntax_error (RCmsg, RCstate, RCchar);
	    RCerror (RCmsg);
	  }
	else
	  {
	    RCerror (YY_("syntax error"));
	    if (RCsize != 0)
	      goto RCexhaustedlab;
	  }
      }
#endif
    }



  if (RCerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (RCchar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (RCchar == YYEOF)
	    YYABORT;
	}
      else
	{
	  RCdestruct ("Error: discarding",
		      RCtoken, &RClval);
	  RCchar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto RCerrlab1;


/*---------------------------------------------------.
| RCerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
RCerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label RCerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto RCerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (RClen);
  RClen = 0;
  YY_STACK_PRINT (RCss, RCssp);
  RCstate = *RCssp;
  goto RCerrlab1;


/*-------------------------------------------------------------.
| RCerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
RCerrlab1:
  RCerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      RCn = RCpact[RCstate];
      if (RCn != YYPACT_NINF)
	{
	  RCn += YYTERROR;
	  if (0 <= RCn && RCn <= YYLAST && RCcheck[RCn] == YYTERROR)
	    {
	      RCn = RCtable[RCn];
	      if (0 < RCn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (RCssp == RCss)
	YYABORT;


      RCdestruct ("Error: popping",
		  RCstos[RCstate], RCvsp);
      YYPOPSTACK (1);
      RCstate = *RCssp;
      YY_STACK_PRINT (RCss, RCssp);
    }

  if (RCn == YYFINAL)
    YYACCEPT;

  *++RCvsp = RClval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", RCstos[RCn], RCvsp, RClsp);

  RCstate = RCn;
  goto RCnewstate;


/*-------------------------------------.
| RCacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
RCacceptlab:
  RCresult = 0;
  goto RCreturn;

/*-----------------------------------.
| RCabortlab -- YYABORT comes here.  |
`-----------------------------------*/
RCabortlab:
  RCresult = 1;
  goto RCreturn;

#ifndef RCoverflow
/*-------------------------------------------------.
| RCexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
RCexhaustedlab:
  RCerror (YY_("memory exhausted"));
  RCresult = 2;
  /* Fall through.  */
#endif

RCreturn:
  if (RCchar != YYEOF && RCchar != YYEMPTY)
     RCdestruct ("Cleanup: discarding lookahead",
		 RCtoken, &RClval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (RClen);
  YY_STACK_PRINT (RCss, RCssp);
  while (RCssp != RCss)
    {
      RCdestruct ("Cleanup: popping",
		  RCstos[*RCssp], RCvsp);
      YYPOPSTACK (1);
    }
#ifndef RCoverflow
  if (RCss != RCssa)
    YYSTACK_FREE (RCss);
#endif
#if YYERROR_VERBOSE
  if (RCmsg != RCmsgbuf)
    YYSTACK_FREE (RCmsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (RCresult);
}


#line 363 "RunConfigGrammar.y"


void runconfig_setNetwork(Network* _network)
{
  network = _network;
}

#include "lex.RC.cc"

