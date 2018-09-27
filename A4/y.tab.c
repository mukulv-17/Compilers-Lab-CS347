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
#line 1 "parser.y" /* yacc.c:339  */

    #include <stdio.h>
    #include <stdlib.h>
    #include <iostream>
    #include <fstream>
    #include <list>
    #include <string>
    #include "functions.cpp"
    using namespace std;


    int yylex(void);
    void yyerror(const char* s);
    void yyerror2(const char* error_msg);

    #define YYDEBUG_VAL 1

    int flag = 0, level=0,sem_flag=0, offset, param_offset;
    int label = 0 ;
    vector<function> func_table;
    vector<variable> global_var_table;
    vector<int> dim_list;
    function *active_func_ptr;
    function call_name_ptr;
    vector<val_type> args_list;
    vector<variable> patch_list;
    val_type data_type;
    extern int  yylex();
    extern int yylineno;
    extern int lineno;
    FILE *fout = fopen("output.asm","w");
    // fclose(fout);
    // fout = fopen("output.asm","a");

#line 101 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INTEGER = 258,
    TYPE_SPECIFIER = 259,
    RETURN = 260,
    PRINT = 261,
    IF = 262,
    ELSE = 263,
    WHILE = 264,
    BREAK = 265,
    BOOL_VAL = 266,
    IDENTIFIER = 267,
    COMMA = 268,
    SEMICOLON = 269,
    OCB = 270,
    ORB = 271,
    CCB = 272,
    CRB = 273,
    OSB = 274,
    CSB = 275,
    CHARVAL = 276,
    STRING_LITERAL = 277,
    INC_OP = 278,
    DEC_OP = 279,
    AND_OP = 280,
    OR_OP = 281,
    LE_OP = 282,
    GE_OP = 283,
    EQ_OP = 284,
    NE_OP = 285,
    LESS = 286,
    GREATER = 287,
    ASSIGN = 288,
    AND = 289,
    OR = 290,
    MINUS = 291,
    PLUS = 292,
    DIV = 293,
    TIMES = 294,
    MOD = 295,
    NOT = 296
  };
#endif
/* Tokens.  */
#define INTEGER 258
#define TYPE_SPECIFIER 259
#define RETURN 260
#define PRINT 261
#define IF 262
#define ELSE 263
#define WHILE 264
#define BREAK 265
#define BOOL_VAL 266
#define IDENTIFIER 267
#define COMMA 268
#define SEMICOLON 269
#define OCB 270
#define ORB 271
#define CCB 272
#define CRB 273
#define OSB 274
#define CSB 275
#define CHARVAL 276
#define STRING_LITERAL 277
#define INC_OP 278
#define DEC_OP 279
#define AND_OP 280
#define OR_OP 281
#define LE_OP 282
#define GE_OP 283
#define EQ_OP 284
#define NE_OP 285
#define LESS 286
#define GREATER 287
#define ASSIGN 288
#define AND 289
#define OR 290
#define MINUS 291
#define PLUS 292
#define DIV 293
#define TIMES 294
#define MOD 295
#define NOT 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 36 "parser.y" /* yacc.c:355  */

    node *Node;

#line 227 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 244 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   188

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  151

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    52,    52,    82,    85,    90,    97,   102,   107,   111,
     164,   168,   175,   191,   202,   210,   216,   227,   226,   285,
     290,   297,   301,   307,   321,   326,   332,   337,   342,   353,
     357,   357,   365,   365,   375,   380,   386,   393,   407,   424,
     440,   448,   460,   466,   509,   518,   528,   539,   550,   561,
     567,   571,   579,   601,   607,   631,   641,   657,   667,   671,
     675,   679,   683,   687,   692,   705,   743,   749,   754,   761,
     811,   817,   823,   828,   835,   874,   882,   886,   892,   917,
     923,   930,   939,   948,   955,   962,   971,   976,   979,   984,
     987,   991,   993,   999,  1003
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "TYPE_SPECIFIER", "RETURN",
  "PRINT", "IF", "ELSE", "WHILE", "BREAK", "BOOL_VAL", "IDENTIFIER",
  "COMMA", "SEMICOLON", "OCB", "ORB", "CCB", "CRB", "OSB", "CSB",
  "CHARVAL", "STRING_LITERAL", "INC_OP", "DEC_OP", "AND_OP", "OR_OP",
  "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "LESS", "GREATER", "ASSIGN", "AND",
  "OR", "MINUS", "PLUS", "DIV", "TIMES", "MOD", "NOT", "$accept",
  "translation_unit", "empty", "declaration_list", "declaration",
  "variable_declaration", "variable_declaration_list", "id_array", "id",
  "dimlist", "function_declaration", "$@1", "parameters", "parameter_list",
  "parameter_type_list", "statement", "$@2", "compound_stmt", "$@3",
  "stmt_list", "expression_stmt", "conditional_stmt", "iteration_stmt",
  "return_stmt", "break_stmt", "expression", "expr_suffix",
  "simple_expression", "logical_and_expr", "unary_relational_expression",
  "relational_expression", "additive_expression", "SUM_OP", "term",
  "MUL_OP", "postfix_expression", "func_call", "args", "arg_list",
  "constant", "open_round", "close_round", "close_curly", "comma",
  "semicolon", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296
};
# endif

#define YYPACT_NINF -82

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-82)))

#define YYTABLE_NINF -31

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      42,   -82,    27,    21,    14,   -82,   -82,   -82,    10,    39,
     -82,    28,   -82,   -82,   -82,   -82,   -82,   -82,    38,   -82,
      57,    62,   -82,   -82,    55,    58,    74,   -82,     9,    55,
     -82,    57,   -82,   -82,   -82,   -82,    80,    62,   -82,   -82,
     -82,   -82,   -82,   -82,    60,   -82,   -82,     8,    12,    12,
      11,   -82,    84,   114,   -82,   -82,   133,   142,   -82,    95,
     -82,   -82,   -82,   -82,   -82,   -82,    11,   -82,    79,   -82,
     -82,   135,    89,   -82,   -82,   -82,   -82,    11,   -82,   -82,
     -82,   114,   114,   -82,   114,     9,    82,   114,   -82,   -82,
     114,    81,    81,    81,    81,    81,    38,   -82,   -82,   133,
     140,   140,   140,   140,   140,   140,   -82,   -82,   140,   -82,
     -82,   -82,   140,   -82,     9,     9,   -82,   -82,     9,    55,
     -82,   133,   -82,   114,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,    -5,    -5,    -5,    -5,    -5,    -5,    89,   -82,   100,
     100,   -82,   114,     5,   -82,    98,   -82,   -82,   -82,   100,
     -82
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     8,     0,     0,     0,     5,     7,     6,    14,     0,
      11,    13,     1,     4,    17,    94,    92,    93,     0,     9,
       0,     3,    14,    10,    16,     0,     0,    20,     0,    19,
      22,     0,    12,    23,    89,    88,     0,     0,    15,    32,
      18,    21,     3,    35,     0,    91,    83,     0,     0,     0,
       0,    84,    14,     0,    90,    85,     0,    74,    34,     0,
      25,    24,    26,    27,    28,    29,     0,    49,    53,    55,
      57,    64,    66,    70,    76,    77,    33,     0,    40,    87,
      86,     0,     0,    42,     3,     0,    49,     0,    74,    56,
       0,     0,     0,     0,     0,     0,     0,    31,    36,     0,
       0,     0,     0,     0,     0,     0,    68,    67,     0,    72,
      71,    73,     0,    41,     0,     0,    80,    82,     0,    79,
      75,     0,    43,     0,    45,    50,    44,    47,    46,    48,
      54,    62,    61,    60,    63,    59,    58,    65,    69,    30,
      30,    78,     0,     0,    51,    37,    39,    81,    52,    30,
      38
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -82,   -82,   -40,   -82,   109,    59,   -82,    -2,   -82,    88,
     -82,   -82,   -82,   -82,    87,   -66,   -82,    96,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -46,    -4,   -36,    13,   -51,
     -82,    83,   -82,    23,   -82,    30,   -82,   -82,   -82,   -82,
      97,   -81,   -82,   -21,    73
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,    27,     4,     5,     6,     9,    88,    11,    25,
       7,    21,    28,    29,    30,    58,    59,    60,    42,    44,
      61,    62,    63,    64,    65,    66,   124,    67,    68,    69,
      70,    71,   108,    72,   112,    73,    74,   118,   119,    75,
      81,    36,    76,    18,    19
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      10,    77,    43,    31,   120,    89,    34,    85,    37,    15,
      34,    46,    15,    79,    -2,     1,    23,    86,     2,    51,
      52,    12,    17,    35,    53,    17,    14,    35,    80,    55,
      99,   106,   107,   139,   140,   114,   115,   141,   117,     8,
      15,    85,    57,     1,   116,    57,     2,    20,   130,    56,
      22,    57,    16,    17,   122,   125,   125,   125,   125,   125,
      24,    45,   148,    46,   -30,    47,    26,    48,    16,    49,
      50,    51,    52,   145,   146,    39,    53,    54,    32,    57,
      57,    55,    57,   150,    46,    57,    33,   144,   126,   127,
     128,   129,    51,    52,    10,    39,   147,    53,   142,    96,
      84,    56,    55,    46,    99,    47,   149,    48,   121,    49,
      50,    51,    52,    13,   123,    39,    53,    46,    97,    38,
      78,    55,    56,    83,    41,    51,    52,   109,   110,   111,
      53,   137,    40,     0,   143,    55,    46,    57,    57,    98,
      57,    56,   138,    46,    51,    52,    82,    57,     0,    87,
     113,    51,    52,     0,    55,    56,    87,     0,     0,     0,
       0,    55,   100,   101,   102,   103,   104,   105,     0,     0,
       0,   106,   107,     0,    56,    90,     0,     0,    91,    92,
      93,    94,    95,   131,   132,   133,   134,   135,   136
};

static const yytype_int16 yycheck[] =
{
       2,    47,    42,    24,    85,    56,     1,    53,    29,     1,
       1,     3,     1,     1,     0,     1,    18,    53,     4,    11,
      12,     0,    14,    18,    16,    14,    16,    18,    16,    21,
      25,    36,    37,   114,   115,    81,    82,   118,    84,    12,
       1,    87,    44,     1,    84,    47,     4,    19,    99,    41,
      12,    53,    13,    14,    90,    91,    92,    93,    94,    95,
       3,     1,   143,     3,     4,     5,     4,     7,    13,     9,
      10,    11,    12,   139,   140,    15,    16,    17,    20,    81,
      82,    21,    84,   149,     3,    87,    12,   123,    92,    93,
      94,    95,    11,    12,    96,    15,   142,    16,   119,     4,
      16,    41,    21,     3,    25,     5,     8,     7,    26,     9,
      10,    11,    12,     4,    33,    15,    16,     3,    59,    31,
      47,    21,    41,    50,    37,    11,    12,    38,    39,    40,
      16,   108,    36,    -1,   121,    21,     3,   139,   140,    66,
     142,    41,   112,     3,    11,    12,    49,   149,    -1,    16,
      77,    11,    12,    -1,    21,    41,    16,    -1,    -1,    -1,
      -1,    21,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    36,    37,    -1,    41,    33,    -1,    -1,    36,    37,
      38,    39,    40,   100,   101,   102,   103,   104,   105
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     4,    43,    45,    46,    47,    52,    12,    48,
      49,    50,     0,    46,    16,     1,    13,    14,    85,    86,
      19,    53,    12,    49,     3,    51,     4,    44,    54,    55,
      56,    85,    20,    12,     1,    18,    83,    85,    51,    15,
      59,    56,    60,    44,    61,     1,     3,     5,     7,     9,
      10,    11,    12,    16,    17,    21,    41,    49,    57,    58,
      59,    62,    63,    64,    65,    66,    67,    69,    70,    71,
      72,    73,    75,    77,    78,    81,    84,    67,    86,     1,
      16,    82,    82,    86,    16,    67,    69,    16,    49,    71,
      33,    36,    37,    38,    39,    40,     4,    47,    86,    25,
      27,    28,    29,    30,    31,    32,    36,    37,    74,    38,
      39,    40,    76,    86,    67,    67,    44,    67,    79,    80,
      83,    26,    69,    33,    68,    69,    68,    68,    68,    68,
      71,    73,    73,    73,    73,    73,    73,    75,    77,    83,
      83,    83,    85,    70,    69,    57,    57,    67,    83,     8,
      57
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    44,    45,    45,    46,    46,    46,    47,
      48,    48,    49,    49,    50,    51,    51,    53,    52,    54,
      54,    55,    55,    56,    57,    57,    57,    57,    57,    57,
      58,    57,    60,    59,    61,    61,    62,    63,    63,    64,
      65,    65,    66,    67,    67,    67,    67,    67,    67,    67,
      68,    68,    69,    69,    70,    70,    71,    71,    72,    72,
      72,    72,    72,    72,    72,    73,    73,    74,    74,    75,
      75,    76,    76,    76,    77,    77,    77,    77,    78,    79,
      79,    80,    80,    81,    81,    81,    82,    82,    83,    83,
      84,    84,    85,    86,    86
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     1,     3,
       3,     1,     4,     1,     1,     3,     1,     0,     7,     1,
       1,     3,     1,     2,     1,     1,     1,     1,     1,     1,
       0,     2,     0,     4,     2,     1,     2,     5,     7,     5,
       2,     3,     2,     3,     3,     3,     3,     3,     3,     1,
       1,     2,     5,     1,     3,     1,     2,     1,     3,     3,
       3,     3,     3,     3,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     3,     1,     1,     4,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1
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
        case 2:
#line 53 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("translation_unit",(yyvsp[0].Node));
    (yyval.Node)->code = (yyvsp[0].Node)->code;
    (yyval.Node)->code = generate_final_code((yyval.Node)->code,global_var_table);
    if(flag==0&&sem_flag==0)
    {
        printf("Compilation successful.\n");
        ofstream output;
        output.open("tree.txt");
        // print_nodes($$,output);
        // print_symbol(global_var_table);
        // print_func(func_table);
        output.close();
        fprintf(fout,(yyval.Node)->code.c_str());
        printf("ASM file generated.\n");
    }
    else if(flag==1&&sem_flag==0)
    {
        printf("Syntax error(s) found.\n");
    }
    else if(flag==0&&sem_flag==1)
    {
        printf("Semantic error(s) found.\n");
    }
}
#line 1472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 82 "parser.y" /* yacc.c:1646  */
    {(yyval.Node) = NULL; }
#line 1478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 86 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("declaration_list",(yyvsp[-1].Node),(yyvsp[0].Node));
    (yyval.Node)->code = (yyvsp[-1].Node)->code + (yyvsp[0].Node)->code;
}
#line 1487 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 91 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("declaration_list",(yyvsp[0].Node));
    (yyval.Node)->code = (yyvsp[0].Node)->code;
}
#line 1496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 98 "parser.y" /* yacc.c:1646  */
    {
   (yyval.Node) = add_node("declaration",(yyvsp[0].Node));
   (yyval.Node)->code = (yyvsp[0].Node)->code;
}
#line 1505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 103 "parser.y" /* yacc.c:1646  */
    {
   (yyval.Node) = add_node("declaration",(yyvsp[0].Node));
   (yyval.Node)->code = (yyvsp[0].Node)->code;
}
#line 1514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 107 "parser.y" /* yacc.c:1646  */
    {yyerror2("Missing Type Specifier "); flag = 1;(yyval.Node) = NULL; exit(1);  }
#line 1520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 112 "parser.y" /* yacc.c:1646  */
    {
    string temp_code = "li $a0, 0\n";
    (yyval.Node) = add_node("variable_declaration",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
    if(level)
    {
        for(int i=0; i< patch_list.size();i++)
        {
            if(check_varlist(global_var_table, func_table, patch_list[i].name) &&
             (!level || check_func_varlist(active_func_ptr, level, patch_list[i].name)))
            {
                variable k = patch_list[i];
                k.ele_type = (yyvsp[-2].Node)->type;
                for (size_t i = 0; i < k.offset/4; i++) {
                    temp_code += "sw $a0, -"+to_string(offset + i*4)+"($fp)\n";
                }
                offset += k.offset;
                k.offset = -(offset - k.offset);
                active_func_ptr->local_var.push_back(k);

            }
            else
            {
                yyerror2("Function or variable with same name already declared");
                sem_flag = 1;
            }
        }
    }
    else
    {
        for(int i=0;i<patch_list.size();i++)
        {
            if(check_varlist(global_var_table, func_table, patch_list[i].name) && (!level || check_func_varlist(active_func_ptr, level, patch_list[i].name)))
            {
                    variable k = patch_list[i];
                    k.ele_type = (yyvsp[-2].Node)->type;
                    k.offset = -1;
                    global_var_table.push_back(k);
            }
            else
            {
                    yyerror2("Function or variable with same name already declared");
                    sem_flag = 1;
            }
        }

    }
    (yyval.Node)->code = temp_code;
    patch_list.clear();
}
#line 1574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 165 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("variable_declaration_list",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 1582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 170 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("variable_declaration_list",(yyvsp[0].Node));
}
#line 1590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 176 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node( "id_array" ,(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
    int temp_offset = 1;
    (yyval.Node)->name = (yyvsp[-3].Node)->name;
    variable k((yyval.Node)->name,ARRAY,NONE,level);
    k.offset = temp_offset;
    for (size_t i = 0; i < dim_list.size(); i++) {
        k.dim_ptr.push_back(dim_list[i]);
        temp_offset *= dim_list[i];
    }
    k.offset = temp_offset*4;
    dim_list.clear();
    patch_list.push_back(k);
}
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 192 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("id_array" ,(yyvsp[0].Node));
    (yyval.Node)->name = (yyvsp[0].Node)->name;
    variable k((yyval.Node)->name,SIMPLE,NONE,level);
    k.offset = 4;
    patch_list.push_back(k);

}
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 203 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("id",(yyvsp[0].Node));
    (yyval.Node)->name = (yyvsp[0].Node)->name;
}
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 211 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("dimlist",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
    dim_list.insert(dim_list.begin(), (yyvsp[-2].Node)->val);
}
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 218 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("dimlist",(yyvsp[0].Node));
    dim_list.push_back((yyvsp[0].Node)->val);
}
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 227 "parser.y" /* yacc.c:1646  */
    {
    level++;
    offset = 4;
    if((yyvsp[-1].Node)->name == "main")
        param_offset = 4;
    else
        param_offset = 8;
    // offset = 8;
    // param_offset = 0;
    if(check_varlist(global_var_table, func_table, (yyvsp[-1].Node)->name))
    {
        function cur_func((yyvsp[-1].Node)->name ,(yyvsp[-2].Node)->type);
        func_table.push_back(cur_func);
        active_func_ptr = &func_table.back();
    }
    else
    {
        yyerror2("Function or variable with same name is already declared.");
        sem_flag=1;
        function cur_func((yyvsp[-1].Node)->name ,(yyvsp[-2].Node)->type);
        active_func_ptr = &cur_func;
    }

}
#line 1678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 251 "parser.y" /* yacc.c:1646  */
    {
    level--;
    string temp_code;
    if(active_func_ptr->name == "main")
        temp_code = "main:\n";
    else
        temp_code = "func_"+(yyvsp[-5].Node)->name+":\n";
    temp_code += std::string("move $fp, $sp\n")
                + "sw $ra, 0($sp)\n"
                + "addiu $sp, $sp, -4\n";
    temp_code += "addiu $sp, $sp, -"+to_string(offset - 4) + "\n";
    // 
    temp_code += (yyvsp[0].Node)->code;
    temp_code += "lw $ra, 0($fp)\n";
    temp_code += "lw $fp, 4($fp)\n";
    if(active_func_ptr->name == "main")
        temp_code += "addiu $sp, $sp, 4\n";
    else
        temp_code += "addiu $sp, $sp, "+to_string(offset + param_offset)+"\n";
    temp_code += "jr $ra\n";
    // if(active_func_ptr->name == "main")
    //     temp_code += "li $v0,10\nsyscall";
    // else
    //     temp_code += "jr $ra\n";
    (yyval.Node) = add_node("function_declaration",(yyvsp[-6].Node),(yyvsp[-5].Node),(yyvsp[-4].Node),(yyvsp[-2].Node),(yyvsp[0].Node));
    // print_local_var(active_func_ptr);
    (yyval.Node)->code = temp_code;

}
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 286 "parser.y" /* yacc.c:1646  */
    {
    // param_offset = 0;
    (yyval.Node) = add_node("parameters",(yyvsp[0].Node));
}
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 291 "parser.y" /* yacc.c:1646  */
    {
    // param_offset = 0;
    (yyval.Node) = add_node("parameters",(yyvsp[0].Node));
}
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 298 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("parameter_list",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 302 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("parameter_list",(yyvsp[0].Node));
}
#line 1746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 308 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("parameter_type_list",(yyvsp[-1].Node),(yyvsp[0].Node));
   variable k((yyvsp[0].Node)->name, SIMPLE, (yyvsp[-1].Node)->type, 1);
   k.offset = param_offset;
   active_func_ptr->params.push_back(k);
   param_offset += 4;
}
#line 1758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 322 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("statement",(yyvsp[0].Node));
    (yyval.Node)->code = (yyvsp[0].Node)->code;
}
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 327 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("statement",(yyvsp[0].Node));
    (yyval.Node)->code = (yyvsp[0].Node)->code;
}
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 333 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("statement",(yyvsp[0].Node));
    (yyval.Node)->code = (yyvsp[0].Node)->code;
}
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 338 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("statement",(yyvsp[0].Node));
    (yyval.Node)->code = (yyvsp[0].Node)->code;
}
#line 1794 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 343 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("statement",(yyvsp[0].Node));
    (yyval.Node)->type = (yyvsp[0].Node)->type;
    (yyval.Node)->val = (yyvsp[0].Node)->val;
    if(active_func_ptr->return_type != (yyval.Node)->type)
    {
        printf("Warning: Return type mismatch at line %d.\n",lineno);
    }
    (yyval.Node)->code = (yyvsp[0].Node)->code;
}
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 354 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("statement",(yyvsp[0].Node));
}
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 357 "parser.y" /* yacc.c:1646  */
    {patch_list.clear();}
#line 1823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 358 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("statement",(yyvsp[0].Node));
    //patch_list.clear();
    (yyval.Node)->code = (yyvsp[0].Node)->code;
}
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 365 "parser.y" /* yacc.c:1646  */
    { level++; }
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 366 "parser.y" /* yacc.c:1646  */
    {
    clear_vars(active_func_ptr, level);
    level--;
    (yyval.Node) = add_node("compound_stmt",(yyvsp[-3].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
    (yyval.Node)->code = (yyvsp[-1].Node)->code;

}
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 376 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("stmt_list",(yyvsp[-1].Node), (yyvsp[0].Node));
    (yyval.Node)->code = (yyvsp[-1].Node)->code + (yyvsp[0].Node)->code;
}
#line 1860 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 381 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("stmt_list",(yyvsp[0].Node));
}
#line 1868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 387 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("expression_stmt",(yyvsp[-1].Node),(yyvsp[0].Node));
    (yyval.Node)->code = (yyvsp[-1].Node)->code;
}
#line 1877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 394 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("conditional_stmt",(yyvsp[-4].Node),(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));

    (yyval.Node)->code= (yyvsp[-2].Node)->code 
            + "li $t0,1" + "\n"
            + "blt  $a0,$t0," + "L_"+to_string(label)+"\n"
            + (yyvsp[0].Node)->code
            + "L_"+to_string(label)+":\n";
    label++;


}
#line 1894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 408 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("conditional_stmt",(yyvsp[-6].Node),(yyvsp[-5].Node),(yyvsp[-4].Node),(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
    (yyval.Node)->code = (yyvsp[-4].Node)->code 
             + "li $t0,1" + "\n"
             + "blt $a0,$t0, " + "L_"+to_string(label)+"\n";
    label++;

    (yyval.Node)->code = (yyval.Node)->code 
            +  (yyvsp[-2].Node)->code
            +  "b L_" +to_string(label)+"\n"
            +  "L_"+to_string(label-1)+":"+ (yyvsp[0].Node)->code
            +  "L_"+to_string(label)+":";
    label++;
}
#line 1913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 425 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("iteration_stmt",(yyvsp[-4].Node),(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
    (yyval.Node)->code= "\nL_"
        + to_string(label)+":\n"
        + (yyvsp[-2].Node)->code 
        + "li $t0,1\n";
    label++;
    (yyval.Node)->code= (yyval.Node)->code + "blt $a0,$t0, " + "L_"+to_string(label)+"\n"
            + (yyvsp[0].Node)->code 
            + "j "+"L_"+to_string(label-1)+"\n"
            + "L_"+to_string(label)+":\n";
    label++;
}
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 441 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("return_stmt",(yyvsp[-1].Node),(yyvsp[0].Node));
        (yyval.Node)->code=   std::string("lw $ra, 0($fp)\n")
            + "lw $fp, 4($fp)\n"
            + "addiu $sp, $sp, "+to_string(offset + param_offset)+"\n"
            + "jr $ra\n";
}
#line 1943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 449 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("return_stmt",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
    // see if need to update $a
    (yyval.Node)->code= (yyvsp[-1].Node)->code 
        + "lw $ra, 0($fp)\n"
        + "lw $fp, 4($fp)\n"
        + "addiu $sp, $sp, "+to_string(offset + param_offset)+"\n"
        + "jr $ra\n";
    (yyval.Node)->type = (yyvsp[-1].Node)->type;
}
#line 1958 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 461 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("break_stmt",(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 1966 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 467 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("expression",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
    if( check_declared(active_func_ptr,global_var_table,level,(yyvsp[-2].Node)->name)) {
        variable var1 = retrieve_declared(active_func_ptr,global_var_table,level,(yyvsp[-2].Node)->name);

         if(check_dimension(var1,patch_list, lineno)){
            int arr_offset = 0;
            arr_offset = cal_arr_offset(patch_list[patch_list.size()-1],var1);
            // printf("%d\n" ,cal_arr_offset(patch_list[patch_list.size()-1],var1));

            if(!coercible(var1.ele_type,(yyvsp[0].Node)->type)){
                yyerror2("Non-coercible types. Assignment failed.");
                sem_flag = 1;
            }
            else{
                if(var1.offset == -1){
                     (yyvsp[-2].Node)->val = (yyvsp[0].Node)->val;
                    (yyval.Node)->type = BOOL;
                    (yyval.Node)->val = 1;
                    (yyval.Node)->code= (yyvsp[0].Node)->code 
                            + "la $t1," + var1.name + "\n"
                            + "sw $a0,($t1)\n";
                }
                else{
                    (yyvsp[-2].Node)->val = (yyvsp[0].Node)->val;
                    (yyval.Node)->type = BOOL;
                    (yyval.Node)->val = 1;
                    (yyval.Node)->code= (yyvsp[0].Node)->code 
                            + "sw $a0,"+to_string(var1.offset+arr_offset)+"($fp)"+"\n"
                            + "li $a0,1\n";
                    //var1.offset($fp)
                }
            }
        }
    }
    else{
        yyerror2("Variable not declared");
        (yyval.Node)->type = ERROR;
        sem_flag = 1;
    }
}
#line 2012 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 510 "parser.y" /* yacc.c:1646  */
    {    
    ARITH_EXPR_NODE((yyval.Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node), "la $t1," + var1.name + "\n"
                                + "lw $t2,($t1)\n"
                                + "add $a0,$a0,$t2\n"
                                ,"move $t1,$a0\n"
                                + "lw $a0,"+to_string(var1.offset)+"($fp)"+"\n"
                                + "add $a0,$a0,$t1\n");
}
#line 2025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 519 "parser.y" /* yacc.c:1646  */
    {
    
    ARITH_EXPR_NODE((yyval.Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node), "la $t1," + var1.name + "\n"
                                + "lw $t2,($t1)\n"
                                + "sub $a0,$a0,$t2\n"
                                , "move $t1,$a0\n"
                                + "lw $a0,"+to_string(var1.offset)+"($fp)"+"\n"
                                + "sub $a0,$a0,$t1\n");
}
#line 2039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 529 "parser.y" /* yacc.c:1646  */
    {
    ARITH_EXPR_NODE((yyval.Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node),"la $t1," + var1.name + "\n"
                                + "lw $t2,($t1)\n"
                                + "mult $a0,$t2\n"
                                + "mflo $a0\n"
                                , "move $t1,$a0\n"
                                + "lw $a0,"+to_string(var1.offset)+"($fp)"+"\n"
                                + "mult $a0,$t1\n"
                                + "mflo $a0\n");
}
#line 2054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 540 "parser.y" /* yacc.c:1646  */
    {
    ARITH_EXPR_NODE((yyval.Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node), "la $t1," + var1.name + "\n"
                                + "lw $t2,($t1)\n"
                                + "div $a0,$t2\n"
                                + "mflo $a0\n"
                                , "move $t1,$a0\n"
                                + "lw $a0,"+to_string(var1.offset)+"($fp)"+"\n"
                                + "div $a0,$t1\n"
                                + "mflo $a0\n");
}
#line 2069 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 551 "parser.y" /* yacc.c:1646  */
    {
    ARITH_EXPR_NODE((yyval.Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node), "la $t1," + var1.name + "\n"
                                + "lw $t2,($t1)\n"
                                + "div $a0,$t2\n"
                                + "mfhi $a0\n"
                                , "move $t1,$a0\n"
                                + "lw $a0,"+to_string(var1.offset)+"($fp)"+"\n"
                                + "div $a0,$t1\n"
                                + "mfhi $a0\n");
}
#line 2084 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 562 "parser.y" /* yacc.c:1646  */
    {
    SIMPLE_NODE("expression",(yyval.Node),(yyvsp[0].Node));
}
#line 2092 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 568 "parser.y" /* yacc.c:1646  */
    {
    SIMPLE_NODE("expr_suffix",(yyval.Node),(yyvsp[0].Node));
}
#line 2100 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 572 "parser.y" /* yacc.c:1646  */
    {
    // traverse
    // $$ = add_node("expr_suffix",$1,$2);
    SIMPLE_NODE("expr_suffix",(yyval.Node),(yyvsp[0].Node));
}
#line 2110 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 580 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("simple_expression",(yyvsp[-4].Node),(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
     (yyval.Node)->type = BOOL;
    (yyval.Node)->val = (yyvsp[-3].Node)->val || (yyvsp[-1].Node)->val;
    int label1 = label++;
    int label2 = label++;
    (yyval.Node)->code= (yyvsp[-3].Node)->code 
            + "sw $a0,0($sp)\n"
            + "addiu $sp,$sp,-4\n"
            + (yyvsp[-1].Node)->code 
            + "lw $t1,4($sp)\n"
            + "addiu $sp,$sp,4\n"
            + "move $t2,$a0\n"
            + "add $t1,$t1,$t2\n"
            + "li $t2,0\n"
            + "beq $t1,$t2,L_" + to_string(label1) + "\n"
            + "li $a0,1\n"
            + "b L_" + to_string(label2) +"\n"
            + "L_" + to_string(label1) + ": li $a0,0\n"
            + "L_" + to_string(label2) + ":\n";
}
#line 2136 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 602 "parser.y" /* yacc.c:1646  */
    {
    SIMPLE_NODE("simple_expression",(yyval.Node),(yyvsp[0].Node));
}
#line 2144 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 608 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("logical_and_expr",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
     (yyval.Node)->type = BOOL;
    (yyval.Node)->val = (yyvsp[-2].Node)->val && (yyvsp[0].Node)->val;
    int label1 = label++;
    int label2 = label++;
    
    (yyval.Node)->code= (yyvsp[-2].Node)->code 
            + "sw $a0,0($sp)\n"
            + "addiu $sp,$sp,-4\n"
            + (yyvsp[0].Node)->code 
            + "lw $t1,4($sp)\n"
            + "addiu $sp,$sp,4\n"
            + "move $t2,$a0\n"
            + "mult $t1,$t2\n"
            + "mflo $t1\n"
            + "li $t2,0\n"
            + "beq $t1,$t2,L_" + to_string(label1) + "\n"
            + "li $a0,1\n"
            + "b L_" + to_string(label2) +"\n"
            + "L_" + to_string(label1) + ": li $a0,0\n"
            + "L_" + to_string(label2) + ":\n";
}
#line 2172 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 632 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("logical_and_expr",(yyvsp[0].Node));
    (yyval.Node)->type = (yyvsp[0].Node)->type;
    (yyval.Node)->val = (yyvsp[0].Node)->val;
    (yyval.Node)->code = (yyvsp[0].Node)->code;
}
#line 2183 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 642 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("unary_relational_expression",(yyvsp[-1].Node),(yyvsp[0].Node));
     (yyval.Node)->type = BOOL;
    (yyval.Node)->val = ((yyvsp[0].Node)->val+1)%2;
    int label1 = label++;
    int label2 = label++;
    (yyval.Node)->code= (yyvsp[0].Node)->code 
            + "move $t1,$a0\n"
            + "li $t2,0\n"
            + "beq $t1,$t2,L_" + to_string(label1) + "\n"
            + "li $a0,1\n"
            + "b L_" + to_string(label2) +"\n"
            + "L_" + to_string(label1) + ": li $a0,0\n"
            + "L_" + to_string(label2) + ":\n";
}
#line 2203 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 658 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("unary_relational_expression",(yyvsp[0].Node));
    (yyval.Node)->type = (yyvsp[0].Node)->type;
    (yyval.Node)->val = (yyvsp[0].Node)->val;
    (yyval.Node)->code = (yyvsp[0].Node)->code;
}
#line 2214 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 668 "parser.y" /* yacc.c:1646  */
    {
    COMP_EXPR_NODE(>,"ble",(yyval.Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node))
}
#line 2222 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 672 "parser.y" /* yacc.c:1646  */
    {
    COMP_EXPR_NODE(<,"bge",(yyval.Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node))
}
#line 2230 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 676 "parser.y" /* yacc.c:1646  */
    {
    COMP_EXPR_NODE(==,"bne",(yyval.Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node))
}
#line 2238 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 680 "parser.y" /* yacc.c:1646  */
    {
    COMP_EXPR_NODE(>=,"blt",(yyval.Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node))
}
#line 2246 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 684 "parser.y" /* yacc.c:1646  */
    {
    COMP_EXPR_NODE(<=,"bgt",(yyval.Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node))
}
#line 2254 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 688 "parser.y" /* yacc.c:1646  */
    {
    COMP_EXPR_NODE(!=,"beq",(yyval.Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node))
}
#line 2262 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 693 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("relational_expression",(yyvsp[0].Node));

    (yyval.Node)->type = (yyvsp[0].Node)->type;
    if((yyvsp[0].Node)->type == BOOL)
        (yyval.Node)->val = (yyvsp[0].Node)->val;
    else
        (yyval.Node)->val = ((yyvsp[0].Node)->val > 0);
    (yyval.Node)->code = (yyvsp[0].Node)->code;
}
#line 2277 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 706 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("additive_expression",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
    if(coercible((yyvsp[-2].Node)->type,(yyvsp[0].Node)->type)==0)
    {
        yyerror2("Operation on non-coercible types");
        sem_flag = 1;
        (yyval.Node)->type = ERROR;
    }
    else
    {
        (yyval.Node)->type = compare_types((yyvsp[-2].Node)->type,(yyvsp[0].Node)->type);
        if((yyvsp[-1].Node)->val == 0)
        {
            
            (yyval.Node)->code= (yyvsp[-2].Node)->code 
                    + "sw $a0,0($sp)\n"
                    + "addiu $sp,$sp,-4\n"
                    + (yyvsp[0].Node)->code 
                    + "lw $t1,4($sp)\n"
                    + "add $a0,$a0,$t1\n"
                    + "addiu $sp,$sp,4\n";
            (yyval.Node)->val = (yyvsp[-2].Node)->val + (yyvsp[0].Node)->val;
        }
        else if((yyvsp[-1].Node)->val == 1)
        {
            
            (yyval.Node)->code= (yyvsp[-2].Node)->code 
                    + "sw $a0,0($sp)\n"
                    + "addiu $sp,$sp,-4\n"
                    + (yyvsp[0].Node)->code 
                    + "lw $t1,4($sp)\n"
                    + "sub $a0,$t1,$a0\n"
                    + "addiu $sp,$sp,4\n";
            (yyval.Node)->val = (yyvsp[-2].Node)->val - (yyvsp[0].Node)->val;
        }
    }
}
#line 2319 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 744 "parser.y" /* yacc.c:1646  */
    {
    KEEP_VAL("additive_expression",(yyval.Node),(yyvsp[0].Node));
}
#line 2327 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 750 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("SUM_OP",(yyvsp[0].Node));
    (yyval.Node)->val = 0;
}
#line 2336 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 755 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("SUM_OP",(yyvsp[0].Node));
    (yyval.Node)->val = 1;
}
#line 2345 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 762 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("term",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
    if(coercible((yyvsp[-2].Node)->type,(yyvsp[0].Node)->type)==0)
    {
        yyerror2("Operation on non-coercible types.");
        sem_flag = 1;
        (yyval.Node)->type = ERROR;
    }
    else
    {
        (yyval.Node)->type = compare_types((yyvsp[-2].Node)->type,(yyvsp[0].Node)->type);
        if((yyvsp[-1].Node)->val == 0)
        {
            (yyval.Node)->code= (yyvsp[-2].Node)->code 
                    + "sw $a0,0($sp)\n"
                    + "addiu $sp,$sp,-4\n"
                    + (yyvsp[0].Node)->code 
                    + "lw $t1,4($sp)\n"
                    + "mult $a0,$t1\n"
                    + "mflo $a0\n"
                    + "addiu $sp,$sp,4\n";
            (yyval.Node)->val = (yyvsp[-2].Node)->val * (yyvsp[0].Node)->val;
        }
        else if((yyvsp[-1].Node)->val == 1)
        {
            (yyval.Node)->code = (yyvsp[-2].Node)->code 
            + "sw $a0,0($sp)\n"
            + "addiu $sp,$sp,-4\n"
            + (yyvsp[0].Node)->code 
            + "lw $t1,4($sp)\n"
            + "div $t1,$a0\n"
            + "mflo $a0\n"
            + "addiu $sp,$sp,4\n";
            (yyval.Node)->val = (yyvsp[-2].Node)->val / (yyvsp[0].Node)->val;
        }
        else if((yyvsp[-1].Node)->val==2)
        {
            (yyval.Node)->code = (yyvsp[-2].Node)->code 
            + "sw $a0,0($sp)\n"
            + "addiu $sp,$sp,-4\n"
            + (yyvsp[0].Node)->code 
            + "lw $t1,4($sp)\n"
            + "div $t1,$a0\n"
            + "mfhi $a0\n"
            + "addiu $sp,$sp,4\n";
            (yyval.Node)->val = (yyvsp[-2].Node)->val % (yyvsp[0].Node)->val;
        }
    }
}
#line 2399 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 812 "parser.y" /* yacc.c:1646  */
    {
    KEEP_VAL("term",(yyval.Node),(yyvsp[0].Node));
}
#line 2407 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 818 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("MUL_OP",(yyvsp[0].Node));
    (yyval.Node)->val = 0;
}
#line 2416 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 824 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("MUL_OP",(yyvsp[0].Node));
    (yyval.Node)->val = 1;
}
#line 2425 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 829 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("MUL_OP",(yyvsp[0].Node));
    (yyval.Node)->val = 2;
}
#line 2434 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 836 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("postfix_expression",(yyvsp[0].Node));
    if( check_declared(active_func_ptr,global_var_table,level,(yyvsp[0].Node)->name)) {
        variable var1 = retrieve_declared(active_func_ptr,global_var_table,level,(yyvsp[0].Node)->name);
       // printf("%d %d\n" ,patch_list.size() , var1.dim_ptr.size());
        //printf("%s\n",patch_list[patch_list.size()].name.c_str());
        if(patch_list[patch_list.size()-1].dim_ptr.size() == var1.dim_ptr.size() ){
            int res = 1;
            for(int i=0;i< var1.dim_ptr.size() ;i++){
                if(patch_list[patch_list.size()-1].dim_ptr[i] >= var1.dim_ptr[i]){
                    res=0;
                }
            }
            if(res == 1){
                if(var1.offset == -1){
                    (yyval.Node)->val = (yyvsp[0].Node)->val;
                    (yyval.Node)->type = var1.ele_type;
                    (yyval.Node)->code = "la $t1," + var1.name + "\nlw $a0,($t1)\n";
                }
                else{
                    (yyval.Node)->type = var1.ele_type;
                    (yyval.Node)->code= "lw $a0,"+to_string(var1.offset)+"($fp)\n";
                }
            }
            else{
                 yyerror2("indexes are out of bound\n");
            }
        }
        else{
            yyerror2("dimension mismatch\n");
        }
    }
    else{
        yyerror2("Variable not declared");
        (yyval.Node)->type = ERROR;
        sem_flag = 1;
    }
}
#line 2477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 875 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("postfix_expression",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
    (yyval.Node)->type = (yyvsp[-1].Node)->type;
    (yyval.Node)->val  =(yyvsp[-1].Node)->val;
    (yyval.Node)->code = (yyvsp[-1].Node)->code;
}
#line 2488 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 883 "parser.y" /* yacc.c:1646  */
    {
    KEEP_VAL("postfix_expression",(yyval.Node),(yyvsp[0].Node))
}
#line 2496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 887 "parser.y" /* yacc.c:1646  */
    {
    SIMPLE_NODE("postfix_expression",(yyval.Node),(yyvsp[0].Node))
}
#line 2504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 893 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("func_call",(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
    if(check_func_name(func_table, (yyvsp[-3].Node)->name)) {
        yyerror2("Function not declared.");
        sem_flag = 1;
    }
    else {
        call_name_ptr = get_func(func_table, (yyvsp[-3].Node)->name);
        if(match_args(call_name_ptr, args_list)) {
            (yyval.Node)->type = call_name_ptr.return_type;
            (yyval.Node)->code = (yyvsp[-1].Node)->code + "jal func_" + call_name_ptr.name+"\n";
            // printf("hello %s\n", $$->code.c_str());
        }
        else
        {
            yyerror2("Argument mismatch in function call");
            sem_flag = 1;
            (yyval.Node)->type = ERROR;
        }
        args_list.clear();
    }
}
#line 2531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 918 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("args",(yyvsp[0].Node));
    (yyval.Node)->code = (yyvsp[0].Node)->code + "sw $fp, 0($sp)\naddiu $sp, $sp, -4\n";
}
#line 2540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 924 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("args",(yyvsp[0].Node));
    (yyval.Node)->code = "sw $fp, 0($sp)\naddiu $sp, $sp, -4\n";
}
#line 2549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 931 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("arg_list",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
    args_list.push_back((yyvsp[0].Node)->type);
    string temp_code = (yyvsp[0].Node)->code + "sw $a0, 0($sp)\naddiu $sp, $sp, -4\n";
    (yyval.Node)->code = temp_code + (yyvsp[-2].Node)->code;


}
#line 2562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 940 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("arg_list",(yyvsp[0].Node));
    args_list.push_back((yyvsp[0].Node)->type);
    (yyval.Node)->type = (yyvsp[0].Node)->type;
    (yyval.Node)->code = (yyvsp[0].Node)->code + "sw $a0, 0($sp) \naddiu $sp, $sp, -4\n";
}
#line 2573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 949 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("constant",(yyvsp[0].Node));
    (yyval.Node)->type = INT;
    (yyval.Node)->val = (yyvsp[0].Node)->val;
    (yyval.Node)->code = "li $a0,"+to_string((yyvsp[0].Node)->val)+"\n";
}
#line 2584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 956 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("constant",(yyvsp[0].Node));
    (yyval.Node)->type = BOOL;
    (yyval.Node)->val = (yyvsp[0].Node)->val;
    (yyval.Node)->code = "li $a0,"+to_string((yyvsp[0].Node)->val)+"\n";
}
#line 2595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 963 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("constant" ,(yyvsp[0].Node));
    (yyval.Node)->type = CHAR;
    (yyval.Node)->val = (yyvsp[0].Node)->val;
    (yyval.Node)->code = "li $a0,"+to_string((yyvsp[0].Node)->val)+"\n";
}
#line 2606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 973 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("open_round",(yyvsp[0].Node));
}
#line 2614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 976 "parser.y" /* yacc.c:1646  */
    {yyerror2("'(' expected after IF or WHILE "); flag = 1; (yyval.Node) = NULL; }
#line 2620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 981 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("close_round",(yyvsp[0].Node));
}
#line 2628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 984 "parser.y" /* yacc.c:1646  */
    {yyerror2("Missing ')' "); flag = 1; (yyval.Node) = NULL;}
#line 2634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 988 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("close_curly",(yyvsp[0].Node));
}
#line 2642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 991 "parser.y" /* yacc.c:1646  */
    {yyerror2("Missing '}' "); flag = 1; (yyval.Node) = NULL;}
#line 2648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 994 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("comma",(yyvsp[0].Node));
}
#line 2656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1000 "parser.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_node("semicolon",(yyvsp[0].Node));
}
#line 2664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1003 "parser.y" /* yacc.c:1646  */
    {lineno--;yyerror2("Missing ';' or ',' ");lineno++; flag = 1; (yyval.Node) = NULL;
}
#line 2671 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2675 "y.tab.c" /* yacc.c:1646  */
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
#line 1006 "parser.y" /* yacc.c:1906  */

extern char* yytext;
extern int lineno;
extern int column;
char* input_filename="test.txt";
extern FILE* yyin;

void printLine(int lineno){
    int line = 1;
    char temp[500];//line buffer
    FILE* yyerrFile = fopen(input_filename,"r");

    while(fgets(temp,sizeof temp, yyerrFile)!=NULL){
        if(line == lineno){
            printf("%s",temp);
            if(temp[strlen(temp)-1]!='\n')
                printf("\n");
            break;
        }else{
            line++;
        }

    }
    fclose(yyerrFile);
}
void yyerror(const char* error_msg)
{
    //called by bison on syntax error
    fflush(stdout);
}
void yyerror2(const char* error_msg)
{
    fflush(stdout);
    printf("\tError: %s near line number: %d\n", error_msg,lineno);
    printLine(lineno);
//  printf("%*s\n%*s\n", column, "^", column, error_msg);
    exit(1);
}

int main(int argc, char* argv[]){
    if(argc>1)
        input_filename = argv[1];
    yyin = fopen(input_filename,"r");

    #if YYDEBUG
        yydebug=YYDEBUG_VAL;
    #endif
    int err;
    do { 
        err = yyparse();
    } while(!feof(yyin));
    if(err==0)
        printf("Done parsing file\n");
    fclose(yyin);
    return 0;
}
