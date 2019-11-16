/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.ypp" /* yacc.c:339  */
     #include "ast_nodes.cpp"
	#include <bits/stdc++.h>
        using namespace std;

        union ASTnode{
        int int_val;
        bool bool_val;
        char char_val;
        char* str_val;
        char* symbol;
        class Node* node;
        class List* node_list;
        };

        typedef union ASTnode YYSTYPE;
        int ARG_CHECK = 0;

        // #define YYSTYPE int
        
	extern  int yylex();
        extern  int yyparse ();
        extern char* yytext;
        extern FILE* yyin;
	void yyerror(const char *s);

        class Node* start = NULL;
        // extern YYSTYPE yylval;


#line 96 "parser.tab.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.hpp".  */
#ifndef YY_YY_PARSER_TAB_HPP_INCLUDED
# define YY_YY_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT_LITERAL = 258,
    BOOL_LITERAL = 259,
    CHAR_LITERAL = 260,
    STRING_LITERAL = 261,
    MINUS = 262,
    NOT = 263,
    ID = 264,
    ARITH_OP = 265,
    REL_OP = 266,
    EQ_OP = 267,
    COND_OP = 268,
    LEFT_ROUND = 269,
    RIGHT_ROUND = 270,
    TYPE = 271,
    BAD_CHAR = 272,
    COMMA = 273,
    SEMICOLON = 274,
    EQUALS = 275,
    QUESTION_MARK = 276,
    COLON = 277,
    LEFT_SQUARE = 278,
    RIGHT_SQUARE = 279,
    LEFT_CURLY = 280,
    RIGHT_CURLY = 281,
    CALLOUT = 282,
    IF = 283,
    ELSE = 284,
    FOR = 285,
    WHILE = 286,
    RETURN = 287,
    BREAK = 288,
    CONTINUE = 289,
    CLASS = 290,
    PROGRAM = 291
  };
#endif

/* Value type.  */


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 179 "parser.tab.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   252

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  51
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  131

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    78,    78,    80,    81,    83,    84,    86,    87,    89,
      90,    92,    93,    94,    97,    98,   100,   101,   103,   106,
     107,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   132,   133,   134,   135,   143,   144,   145,   148,   149,
     152,   153
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT_LITERAL", "BOOL_LITERAL",
  "CHAR_LITERAL", "STRING_LITERAL", "MINUS", "NOT", "ID", "ARITH_OP",
  "REL_OP", "EQ_OP", "COND_OP", "LEFT_ROUND", "RIGHT_ROUND", "TYPE",
  "BAD_CHAR", "COMMA", "SEMICOLON", "EQUALS", "QUESTION_MARK", "COLON",
  "LEFT_SQUARE", "RIGHT_SQUARE", "LEFT_CURLY", "RIGHT_CURLY", "CALLOUT",
  "IF", "ELSE", "FOR", "WHILE", "RETURN", "BREAK", "CONTINUE", "CLASS",
  "PROGRAM", "$accept", "Goal", "program", "method_decl", "method_decls",
  "parameters", "composite_type", "block", "var_decls", "var_decl",
  "statements", "statement", "expr", "literal", "location", "method_call",
  "callout_args", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291
};
# endif

#define YYPACT_NINF -46

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-46)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -16,   -14,    44,   -46,    -5,   -46,    23,    32,   -46,    -9,
      49,    23,   -46,    57,   -46,   -46,    52,     4,    21,   -46,
      41,    53,    20,   -46,   -46,    40,    43,    33,    62,    70,
      95,   -46,    43,    23,   -46,    51,   -46,   -46,   -46,   -46,
       7,     7,    54,     7,    71,    72,    75,    77,     7,    65,
      73,    67,    95,   110,   -46,   187,   -46,    74,    76,   -46,
      87,   -46,   239,   -46,   -46,   239,     7,   215,    99,     7,
      97,     7,   120,   -46,   -46,    88,   142,   -46,   -46,     7,
       7,     7,     7,   157,     7,   -46,   -46,   168,   -46,    35,
     221,    90,   227,   -46,   -46,   -46,   -46,   -46,   -46,    86,
     191,    98,   -46,     7,    43,     7,    43,   157,   -46,     7,
     239,    39,    91,   201,   -46,   -46,   183,   -46,     7,    43,
       7,   -46,   239,   -46,   205,   125,   115,     7,   233,    43,
     -46
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     0,     1,     0,    11,     7,     0,
       0,     0,    16,     0,     4,     8,     0,     0,     0,    17,
       0,     0,     0,    18,     3,    12,     0,     0,     0,     0,
       0,     6,     0,     0,     9,     0,    41,    43,    42,    44,
       0,     0,    45,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    19,     0,    31,    39,    40,     5,
       0,    13,    36,    39,    40,    37,     0,     0,     0,     0,
       0,     0,     0,    29,    30,     0,     0,    15,    20,     0,
       0,     0,     0,     0,     0,    22,    10,     0,    38,     0,
       0,     0,     0,    28,    14,    32,    33,    34,    35,     0,
       0,    46,    49,     0,     0,     0,     0,     0,    21,     0,
      50,     0,    23,     0,    26,    25,     0,    48,     0,     0,
       0,    47,    51,    24,     0,     0,     0,     0,     0,     0,
      27
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -46,   -46,   -46,    15,   141,   -46,    60,   -32,   123,    -6,
     102,   -45,   -39,   -46,   -27,   -24,   -46
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     8,     9,    27,    10,    31,    11,    12,
      53,    54,    55,    56,    63,    64,   111
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      59,    62,    65,    57,    67,    19,    58,     7,    78,    72,
      36,    37,    38,    39,    40,    41,    42,    14,    22,     1,
       6,    43,     4,    23,    15,    57,    57,    87,    58,    58,
      90,    78,    92,    15,    44,    26,     7,     7,    99,     7,
      95,    96,    97,    98,     5,   100,    19,    24,    32,    57,
     102,    33,    58,   103,   117,    13,    57,   118,    17,    58,
      20,    21,   115,    29,   110,    25,   113,    22,    30,    16,
     116,    34,   112,    35,   114,    61,    75,    66,    16,   122,
      57,   124,    28,    58,    73,    68,    69,   123,   128,    70,
      51,    71,    74,    60,    84,    85,    86,   130,    36,    37,
      38,    39,    40,    41,    42,    89,    91,    23,   107,    43,
     105,     7,    51,    36,    37,    38,    39,    40,    41,    42,
     119,   109,    44,    45,    43,    46,    47,    48,    49,    50,
      79,    80,    81,    82,   126,   127,    77,    44,    45,    93,
      46,    47,    48,    49,    50,    36,    37,    38,    39,    40,
      41,    42,    18,    52,    76,     0,    43,     0,     0,     0,
      36,    37,    38,    39,    40,    41,    42,     0,    94,    44,
      45,    43,    46,    47,    48,    49,    50,     0,    79,    80,
      81,    82,     0,     0,    44,    45,     0,    46,    47,    48,
      49,    50,   101,    79,    80,    81,    82,    79,    80,    81,
      82,    79,    80,    81,    82,     0,     0,   121,    83,     0,
     108,    79,    80,    81,    82,    79,    80,    81,    82,     0,
     120,     0,     0,     0,   125,    79,    80,    81,    82,     0,
      88,    79,    80,    81,    82,     0,   104,    79,    80,    81,
      82,     0,   106,    79,    80,    81,    82,     0,   129,    79,
      80,    81,    82
};

static const yytype_int16 yycheck[] =
{
      32,    40,    41,    30,    43,    11,    30,    16,    53,    48,
       3,     4,     5,     6,     7,     8,     9,    26,    14,    35,
      25,    14,    36,    19,     9,    52,    53,    66,    52,    53,
      69,    76,    71,    18,    27,    15,    16,    16,    83,    16,
      79,    80,    81,    82,     0,    84,    52,    26,    15,    76,
      15,    18,    76,    18,    15,    23,    83,    18,     9,    83,
       3,     9,   107,    23,   103,    24,   105,    14,    25,     9,
     109,     9,   104,     3,   106,    24,     9,    23,    18,   118,
     107,   120,    22,   107,    19,    14,    14,   119,   127,    14,
      30,    14,    19,    33,    20,    19,     9,   129,     3,     4,
       5,     6,     7,     8,     9,     6,     9,    19,    22,    14,
      20,    16,    52,     3,     4,     5,     6,     7,     8,     9,
      29,    23,    27,    28,    14,    30,    31,    32,    33,    34,
      10,    11,    12,    13,     9,    20,    26,    27,    28,    19,
      30,    31,    32,    33,    34,     3,     4,     5,     6,     7,
       8,     9,    11,    30,    52,    -1,    14,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    -1,    26,    27,
      28,    14,    30,    31,    32,    33,    34,    -1,    10,    11,
      12,    13,    -1,    -1,    27,    28,    -1,    30,    31,    32,
      33,    34,    24,    10,    11,    12,    13,    10,    11,    12,
      13,    10,    11,    12,    13,    -1,    -1,    24,    21,    -1,
      19,    10,    11,    12,    13,    10,    11,    12,    13,    -1,
      19,    -1,    -1,    -1,    19,    10,    11,    12,    13,    -1,
      15,    10,    11,    12,    13,    -1,    15,    10,    11,    12,
      13,    -1,    15,    10,    11,    12,    13,    -1,    15,    10,
      11,    12,    13
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    35,    38,    39,    36,     0,    25,    16,    40,    41,
      43,    45,    46,    23,    26,    40,    43,     9,    41,    46,
       3,     9,    14,    19,    26,    24,    15,    42,    43,    23,
      25,    44,    15,    18,     9,     3,     3,     4,     5,     6,
       7,     8,     9,    14,    27,    28,    30,    31,    32,    33,
      34,    43,    45,    47,    48,    49,    50,    51,    52,    44,
      43,    24,    49,    51,    52,    49,    23,    49,    14,    14,
      14,    14,    49,    19,    19,     9,    47,    26,    48,    10,
      11,    12,    13,    21,    20,    19,     9,    49,    15,     6,
      49,     9,    49,    19,    26,    49,    49,    49,    49,    48,
      49,    24,    15,    18,    15,    20,    15,    22,    19,    23,
      49,    53,    44,    49,    44,    48,    49,    15,    18,    29,
      19,    24,    49,    44,    49,    19,     9,    20,    49,    15,
      44
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    40,    41,    41,    42,
      42,    43,    43,    43,    44,    44,    45,    45,    46,    47,
      47,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    50,    50,    50,    50,    51,    51,    51,    52,    52,
      53,    53
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     6,     5,     6,     5,     1,     2,     2,
       4,     1,     4,     7,     4,     3,     1,     2,     3,     1,
       2,     4,     2,     5,     7,     5,     5,    13,     3,     2,
       2,     1,     3,     3,     3,     3,     2,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     4,     7,     6,     4,
       1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
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

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:
#line 80 "parser.ypp" /* yacc.c:1646  */
    {printf("program -> CLASS PROGRAM LEFT_CURLY var_decls method_decls RIGHT_CURLY \n");}
#line 1365 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 81 "parser.ypp" /* yacc.c:1646  */
    {printf("program -> CLASS PROGRAM LEFT_CURLY method_decls RIGHT_CURLY \n");}
#line 1371 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 83 "parser.ypp" /* yacc.c:1646  */
    {(yyval.node) = new MethodDeclParam((yyvsp[-5].node), (yyvsp[-4].symbol), (yyvsp[-3].symbol), (yyvsp[-2].node_list)); printf("method_decl -> composite_type ID LEFT_ROUND parameters RIGHT_ROUND block\n");}
#line 1377 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 84 "parser.ypp" /* yacc.c:1646  */
    {printf("method_decl -> composite_type ID LEFT_ROUND RIGHT_ROUND block\n");}
#line 1383 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 86 "parser.ypp" /* yacc.c:1646  */
    {(yyval.node_list) = new MethodDecls(); (yyval.node_list)->list.push_back((yyvsp[0].node)); printf("method_decls -> method_decl\n");}
#line 1389 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 87 "parser.ypp" /* yacc.c:1646  */
    {(yyval.node_list)->list.push_back((yyvsp[0].node)); printf("method_decls -> method_decls method_decl \n");}
#line 1395 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 89 "parser.ypp" /* yacc.c:1646  */
    {(yyval.node_list) = new Parameters(); (yyval.node_list)->add((yyvsp[-1].node), (yyvsp[0].symbol)); printf("parameters -> composite_type ID \n");}
#line 1401 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 90 "parser.ypp" /* yacc.c:1646  */
    {(yyval.node_list)->add((yyvsp[-1].node), (yyvsp[0].symbol)); printf("parameters -> parameters COMMA composite_type ID \n");}
#line 1407 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 92 "parser.ypp" /* yacc.c:1646  */
    {(yyval.node) = new Type((yyvsp[0].symbol)); printf("composite_type -> TYPE\n");}
#line 1413 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 93 "parser.ypp" /* yacc.c:1646  */
    {printf("composite_type -> TYPE LEFT_SQUARE INT_LITERAL RIGHT_SQUARE\n");}
#line 1419 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 94 "parser.ypp" /* yacc.c:1646  */
    {printf("composite_type -> TYPE LEFT_SQUARE INT_LITERAL RIGHT_SQUARE LEFT_SQUARE INT_LITERAL RIGHT_SQUARE \n");}
#line 1425 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 97 "parser.ypp" /* yacc.c:1646  */
    {(yyval.node) = new DecBlock((yyvsp[-2].node_list), (yyvsp[-1].node_list)); printf("block -> LEFT_CURLY var_decls statements RIGHT_CURLY\n"); start = (yyval.node);}
#line 1431 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 98 "parser.ypp" /* yacc.c:1646  */
    {(yyval.node) = new StatBlock((yyvsp[-1].node_list)); printf("block -> LEFT_CURLY statements RIGHT_CURLY\n"); start = (yyval.node);}
#line 1437 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 100 "parser.ypp" /* yacc.c:1646  */
    {(yyval.node_list) = new VarDecls(); (yyval.node_list)->list.push_back((yyvsp[0].node)); printf("var_decls -> var_decl\n");}
#line 1443 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 101 "parser.ypp" /* yacc.c:1646  */
    {(yyval.node_list)->list.push_back((yyvsp[0].node)); printf("var_decls-> var_decls var_decl\n");}
#line 1449 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 103 "parser.ypp" /* yacc.c:1646  */
    {(yyval.node) = new VarDecl((yyvsp[-2].node), (yyvsp[-1].symbol)); printf("var_decl -> composite_type ID SEMICOLON\n");}
#line 1455 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 106 "parser.ypp" /* yacc.c:1646  */
    {(yyval.node_list) = new Statements(); (yyval.node_list)->list.push_back((yyvsp[0].node)); printf("statements -> statement\n");}
#line 1461 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 107 "parser.ypp" /* yacc.c:1646  */
    {(yyval.node_list) = (yyvsp[-1].node_list); (yyval.node_list)->list.push_back((yyvsp[0].node)); printf("statements -> statements statement\n");}
#line 1467 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 109 "parser.ypp" /* yacc.c:1646  */
    {(yyval.node) = new AssignmentStatement((yyvsp[-3].node), (yyvsp[-1].node)); start = (yyval.node); printf("statement -> location EQUALS expr SEMICOLON \n"); }
#line 1473 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 110 "parser.ypp" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node); printf("statement -> method_call SEMICOLON \n"); }
#line 1479 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 111 "parser.ypp" /* yacc.c:1646  */
    { (yyval.node) = new IfThenStatement((yyvsp[-2].node), (yyvsp[0].node)); printf("statement -> IF LEFT_ROUND expr RIGHT_ROUND statement \n");}
#line 1485 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 112 "parser.ypp" /* yacc.c:1646  */
    {(yyval.node) = new IfThenElseStatement((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node)); printf("statement -> IF LEFT_ROUND expr RIGHT_ROUND statement ELSE statement \n");}
#line 1491 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 113 "parser.ypp" /* yacc.c:1646  */
    {(yyval.node) = new TernaryIfStatement((yyvsp[-4].node),(yyvsp[-2].node), (yyvsp[0].node)); printf("statement -> expr  QUESTION_MARK statement COLON statement \n");}
#line 1497 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 114 "parser.ypp" /* yacc.c:1646  */
    {(yyval.node) = new WhileStatement((yyvsp[-2].node), (yyvsp[0].node)); printf("statement -> WHILE LEFT_ROUND expr RIGHT_ROUND statement \n");}
#line 1503 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 115 "parser.ypp" /* yacc.c:1646  */
    {(yyval.node) = new ForStatement((yyvsp[-10].symbol), (yyvsp[-8].node), (yyvsp[-6].node), (yyvsp[-4].symbol), (yyvsp[-2].node), (yyvsp[0].node)); printf("statement -> FOR LEFT_ROUND ID EQUALS expr SEMICOLON expr SEMICOLON ID EQUALS expr RIGHT_ROUND statement \n");}
#line 1509 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 116 "parser.ypp" /* yacc.c:1646  */
    {(yyval.node) = new ReturnStatement((yyvsp[-1].node)); printf("statement -> RETURN expr SEMICOLON \n");}
#line 1515 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 117 "parser.ypp" /* yacc.c:1646  */
    {(yyval.node) = new BreakStatement(); printf("statement -> BREAK SEMICOLON \n");}
#line 1521 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 118 "parser.ypp" /* yacc.c:1646  */
    {(yyval.node) = new ContinueStatement(); printf("statement -> CONTINUE SEMICOLON \n");}
#line 1527 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 121 "parser.ypp" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1533 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 122 "parser.ypp" /* yacc.c:1646  */
    {(yyval.node) = new ArithmeticExpression((yyvsp[-2].node), (yyvsp[-1].symbol), (yyvsp[0].node)); }
#line 1539 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 123 "parser.ypp" /* yacc.c:1646  */
    {(yyval.node) = new RelationalExpression((yyvsp[-2].node), (yyvsp[-1].symbol), (yyvsp[0].node)); }
#line 1545 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 124 "parser.ypp" /* yacc.c:1646  */
    {(yyval.node) = new EqualExpression((yyvsp[-2].node), (yyvsp[-1].symbol), (yyvsp[0].node)); }
#line 1551 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 125 "parser.ypp" /* yacc.c:1646  */
    {(yyval.node) = new ConditionalExpression((yyvsp[-2].node), (yyvsp[-1].symbol), (yyvsp[0].node)); }
#line 1557 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 126 "parser.ypp" /* yacc.c:1646  */
    {(yyval.node) = new UnaryExpression((yyvsp[-1].symbol), (yyvsp[0].node)); }
#line 1563 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 127 "parser.ypp" /* yacc.c:1646  */
    {(yyval.node) = new UnaryExpression((yyvsp[-1].symbol), (yyvsp[0].node)); }
#line 1569 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 128 "parser.ypp" /* yacc.c:1646  */
    {(yyval.node) = new EnclosedExpression((yyvsp[-1].node));}
#line 1575 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 129 "parser.ypp" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1581 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 130 "parser.ypp" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node); printf("expr -> method_call \n");}
#line 1587 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 132 "parser.ypp" /* yacc.c:1646  */
    {(yyval.node) = new IntLiteral((yyvsp[0].int_val));}
#line 1593 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 133 "parser.ypp" /* yacc.c:1646  */
    {(yyval.node) = new CharLiteral((yyvsp[0].char_val));}
#line 1599 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 134 "parser.ypp" /* yacc.c:1646  */
    {(yyval.node) = new BoolLiteral((yyvsp[0].bool_val));}
#line 1605 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 135 "parser.ypp" /* yacc.c:1646  */
    {(yyval.node) = new StringLiteral((yyvsp[0].str_val));}
#line 1611 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 143 "parser.ypp" /* yacc.c:1646  */
    {(yyval.node) = new Identifier((yyvsp[0].symbol));}
#line 1617 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 144 "parser.ypp" /* yacc.c:1646  */
    {printf("location -> ID LEFT_SQUARE expr RIGHT_SQUARE \n");}
#line 1623 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 145 "parser.ypp" /* yacc.c:1646  */
    {printf("location -> ID LEFT_SQUARE expr RIGHT_SQUARE LEFT_SQUARE expr RIGHT_SQUARE \n");}
#line 1629 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 148 "parser.ypp" /* yacc.c:1646  */
    {printf("method_call -> CALLOUT LEFT_ROUND STRING_LITERAL COMMA\n"); (yyval.node) =new MethodCall((yyvsp[-3].str_val), (yyvsp[-1].node_list));}
#line 1635 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 149 "parser.ypp" /* yacc.c:1646  */
    {printf("method_call -> CALLOUT LEFT_ROUND STRING_LITERAL RIGHT_ROUND \n");}
#line 1641 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 152 "parser.ypp" /* yacc.c:1646  */
    {printf("callout_args -> exp\n"); (yyval.node_list) = new CalloutArgs(); (yyval.node_list)->list.push_back((yyvsp[0].node));}
#line 1647 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 153 "parser.ypp" /* yacc.c:1646  */
    {printf("callout_args -> callout_args COMMA expr\n"); (yyval.node_list) = (yyvsp[-2].node_list); (yyval.node_list)->list.push_back((yyvsp[0].node));}
#line 1653 "parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 1657 "parser.tab.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 155 "parser.ypp" /* yacc.c:1906  */

void yyerror(const char *s)
{
        fprintf(stderr, "error: %s\n", s);
}

int main(int argc, char **argv)
{
        yyparse();
        printf("Parsing Over\n");

        PrettyPrint printer;
        start->doOp(&printer);
        cout << endl;
        
        return 0;
}

