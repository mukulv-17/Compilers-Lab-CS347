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
#line 1 "main.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char* s);
extern int yylex();
extern int yyparse();

#define YYDEBUG_VAL 1


#line 79 "main.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "main.tab.h".  */
#ifndef YY_YY_MAIN_TAB_H_INCLUDED
# define YY_YY_MAIN_TAB_H_INCLUDED
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
    TYPE_NAME = 258,
    VOID = 259,
    CONSTANT = 260,
    LEFT_OP = 261,
    RIGHT_OP = 262,
    IDENTIFIER = 263,
    FLOAT_CONST = 264,
    BOOL = 265,
    STRING_LITERAL = 266,
    CONST = 267,
    CHAR = 268,
    INT = 269,
    LONG = 270,
    RETURN = 271,
    SHORT = 272,
    SIGNED = 273,
    UNSIGNED = 274,
    INTEGER = 275,
    FLOAT = 276,
    DOUBLE = 277,
    ADD_ASSIGN = 278,
    SUB_ASSIGN = 279,
    MUL_ASSIGN = 280,
    DIV_ASSIGN = 281,
    MOD_ASSIGN = 282,
    AND_ASSIGN = 283,
    XOR_ASSIGN = 284,
    OR_ASSIGN = 285,
    INC_OP = 286,
    DEC_OP = 287,
    PTR_OP = 288,
    AND_OP = 289,
    OR_OP = 290,
    LE_OP = 291,
    GE_OP = 292,
    EQ_OP = 293,
    NE_OP = 294,
    DO = 295,
    WHILE = 296,
    ELSE = 297,
    FOR = 298,
    IF = 299,
    BREAK = 300,
    CONTINUE = 301,
    MF_GET_MEMORY = 302,
    MF_IS_RUNNING = 303,
    MF_SUBMIT_JOBS = 304,
    MF_GET_CS = 305,
    MF_RUN = 306,
    MF_DISCARD_JOB = 307,
    MF_GAV = 308,
    P_NAME = 309,
    P_ISA = 310,
    P_CLOCK_SPEED = 311,
    P_MEM_OBJ_1 = 312,
    P_MEM_OBJ_2 = 313,
    P_START_POINT = 314,
    P_END_POINT = 315,
    P_BANDWIDTH = 316,
    P_CHANNEL_CAP = 317,
    P_MEM_TYPE = 318,
    P_MEM_SIZE = 319,
    P_JOB_ID = 320,
    P_FLOPS_REQ = 321,
    P_DEADLINE = 322,
    P_MEM_REQ = 323,
    P_AFFINITY = 324,
    P_PROCESSORS = 325,
    P_LINK_BANDW = 326,
    P_LINK_CAP = 327,
    P_TOPOLOGY = 328,
    C_PROC = 329,
    C_CLUSTER = 330,
    C_LINK = 331,
    C_MEMORY = 332,
    C_JOB = 333
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MAIN_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 209 "main.tab.c" /* yacc.c:358  */

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
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1121

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  103
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  81
/* YYNRULES -- Number of rules.  */
#define YYNRULES  201
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  405

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   334

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    89,     2,     2,     2,    91,    85,     2,
      79,    80,    86,    87,    81,    88,    84,    90,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    97,    99,
      92,    98,    93,    96,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    82,     2,    83,    94,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   100,    95,   101,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,   102
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    33,    33,    34,    38,    39,    43,    44,    48,    49,
      54,    55,    56,    57,    61,    62,    65,    66,    69,    70,
      74,    75,    76,    77,    78,    79,    80,    85,    86,    87,
      88,    89,    90,    98,    99,   100,   101,   109,   110,   111,
     112,   113,   117,   118,   122,   123,   124,   125,   129,   130,
     131,   135,   136,   137,   141,   142,   143,   144,   145,   149,
     150,   151,   155,   156,   160,   161,   165,   166,   170,   171,
     175,   176,   183,   184,   191,   192,   193,   194,   195,   196,
     201,   202,   207,   208,   212,   213,   217,   218,   222,   223,
     227,   228,   233,   234,   235,   236,   237,   238,   239,   240,
     245,   246,   247,   248,   249,   250,   251,   252,   256,   257,
     261,   262,   266,   267,   274,   275,   276,   277,   278,   282,
     283,   287,   288,   292,   293,   297,   298,   302,   303,   307,
     308,   309,   310,   311,   312,   316,   317,   318,   319,   324,
     325,   332,   333,   334,   335,   341,   346,   347,   353,   354,
     359,   360,   364,   365,   369,   370,   371,   375,   376,   380,
     383,   386,   389,   392,   397,   400,   401,   404,   405,   408,
     409,   414,   418,   419,   422,   423,   427,   432,   436,   437,
     440,   441,   444,   445,   448,   449,   452,   453,   457,   458,
     463,   468,   471,   472,   475,   476,   479,   480,   483,   484,
     487,   488
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TYPE_NAME", "VOID", "CONSTANT",
  "LEFT_OP", "RIGHT_OP", "IDENTIFIER", "FLOAT_CONST", "BOOL",
  "STRING_LITERAL", "CONST", "CHAR", "INT", "LONG", "RETURN", "SHORT",
  "SIGNED", "UNSIGNED", "INTEGER", "FLOAT", "DOUBLE", "ADD_ASSIGN",
  "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "AND_ASSIGN",
  "XOR_ASSIGN", "OR_ASSIGN", "INC_OP", "DEC_OP", "PTR_OP", "AND_OP",
  "OR_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "DO", "WHILE", "ELSE",
  "FOR", "IF", "BREAK", "CONTINUE", "MF_GET_MEMORY", "MF_IS_RUNNING",
  "MF_SUBMIT_JOBS", "MF_GET_CS", "MF_RUN", "MF_DISCARD_JOB", "MF_GAV",
  "P_NAME", "P_ISA", "P_CLOCK_SPEED", "P_MEM_OBJ_1", "P_MEM_OBJ_2",
  "P_START_POINT", "P_END_POINT", "P_BANDWIDTH", "P_CHANNEL_CAP",
  "P_MEM_TYPE", "P_MEM_SIZE", "P_JOB_ID", "P_FLOPS_REQ", "P_DEADLINE",
  "P_MEM_REQ", "P_AFFINITY", "P_PROCESSORS", "P_LINK_BANDW", "P_LINK_CAP",
  "P_TOPOLOGY", "C_PROC", "C_CLUSTER", "C_LINK", "C_MEMORY", "C_JOB",
  "'('", "')'", "','", "'['", "']'", "'.'", "'&'", "'*'", "'+'", "'-'",
  "'!'", "'/'", "'%'", "'<'", "'>'", "'^'", "'|'", "'?'", "':'", "'='",
  "';'", "'{'", "'}'", "\"None\"", "$accept", "translation_unit",
  "external_declaration", "function_definition", "declaration_list",
  "primary_expression", "id_or_float", "id_or_int",
  "argument_expression_list", "postfix_expression", "special_function",
  "unary_expression", "unary_operator", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "special_expression", "assignment_expression",
  "expression", "declaration", "init_declarator_list", "init_declarator",
  "declaration_specifiers", "type_specifier", "declarator",
  "parameter_list", "parameter_declaration", "identifier_list",
  "statement", "compound_statement", "block_item_list", "block_item",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "cidentifers", "cstrings", "processor",
  "processor_isa", "processor_clock_speed", "processor_l1", "l1",
  "processor_optional", "P_MEM_OBJ_2_EQ", "is_running", "submit_jobs",
  "get_clock_speed", "run", "discard_job", "link", "link_start_point",
  "link_end_point", "link_bandwidth", "memory", "P_MEM_TYPE_EQ",
  "P_MEM_SIZE_EQ", "get_available_memory", "job", "job_id",
  "job_flops_required", "job_deadline", "job_memory_required",
  "job_affinity", "affinity", "get_memory", "cluster",
  "cluster_processors", "cluster_topology", "cluster_link_bandwidth",
  "cluster_link_capacity", "cluster_array", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,    40,
      41,    44,    91,    93,    46,    38,    42,    43,    45,    33,
      47,    37,    60,    62,    94,   124,    63,    58,    61,    59,
     123,   125,   334
};
# endif

#define YYPACT_NINF -293

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-293)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     279,  -293,  -293,  -293,  -293,  -293,  -293,  -293,  -293,   265,
    -293,  -293,  -293,    -4,   279,  -293,  -293,  -293,     1,  -293,
     -51,  -293,    49,  -293,   182,     1,  -293,    79,   556,  1000,
     159,    30,  -293,    -4,  -293,  -293,  -293,   -57,  -293,  -293,
       1,    97,  -293,   102,  -293,  -293,  -293,  -293,  1032,  1032,
     -59,   -25,   -22,   -18,    -7,    65,   539,  -293,  -293,    75,
    -293,  -293,  -293,  -293,  -293,  -293,   110,    66,  1000,  -293,
      60,   124,   210,   116,   203,    86,    93,   101,   164,    70,
    -293,  -293,   123,  -293,  -293,  -293,  -293,  -293,  -293,  -293,
    -293,   114,   407,   425,   144,   146,   151,   129,  -293,  -293,
    -293,   -44,  -293,  -293,  -293,   324,  -293,  -293,  -293,  -293,
    -293,  -293,  -293,   -33,  -293,   279,  -293,   224,  1000,  -293,
    -293,     0,    24,    -1,    17,   180,   589,   176,   171,  -293,
    -293,  -293,   638,  1000,     7,  1000,  -293,  -293,  1000,  1000,
    1000,  1000,  1000,  1000,  1000,  1000,  1000,  1000,  1000,  1000,
    1000,  1000,  1000,  1000,  1000,  1000,  1000,  -293,  -293,  -293,
     -39,   212,  1000,   375,  1000,  -293,  1000,  -293,  -293,  -293,
    -293,  -293,  -293,   259,   201,  -293,   190,   214,   216,   218,
    -293,  -293,   219,   234,   220,   305,   225,  -293,   243,  -293,
    1032,  -293,   193,  -293,   105,   245,   248,  -293,  -293,  -293,
    -293,  -293,  -293,  -293,  -293,  -293,  -293,  -293,    60,    60,
     124,   124,   210,   210,   210,   210,   116,   116,   203,    86,
      93,   101,   164,    64,  -293,   251,   196,   507,   507,   204,
    -293,   250,   253,  -293,   331,   677,     0,    67,   332,    13,
    -293,   266,  1000,   726,  -293,  -293,  1000,  -293,   202,     0,
    1000,  1000,   425,   759,   775,   425,   259,  -293,  -293,   252,
    -293,   269,  -293,  -293,   254,   272,  -293,  -293,   256,   276,
     294,  -293,   261,  -293,   280,  -293,   281,   283,   287,   292,
     297,   293,  -293,   217,  -293,   425,   226,   425,   228,   335,
    -293,  1000,   128,   367,   848,   369,   877,   284,  1000,  1000,
     909,   301,   307,   311,   385,   314,  -293,   306,  -293,   425,
    -293,   425,   425,  -293,  -293,   310,    21,  -293,  -293,  -293,
     316,  -293,   323,  -293,   319,  -293,   338,  -293,    22,  -293,
     322,  -293,   340,  -293,  -293,  -293,   342,  -293,  -293,  -293,
    -293,  -293,     9,  -293,   -31,  -293,   348,  1000,   938,  1000,
    1000,   376,   349,  1000,   970,  -293,  -293,   333,   334,    -3,
    -293,  -293,   337,  -293,    22,  -293,    22,  -293,  -293,   339,
    -293,   359,    -5,  -293,    22,    22,  1000,   362,   363,  1000,
       8,  -293,  -293,  -293,  -293,  -293,  -293,  -293,  -293,  -293,
     346,  1000,   366,  -293,     6,   374,  -293,  -293,  1000,   378,
    1000,   386,  1000,   364,  -293
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    92,    99,    93,    95,    96,    94,    97,    98,     0,
       2,     4,     5,     0,    90,     1,     3,   100,     0,    84,
       0,    86,    89,    91,     0,     0,    85,     0,     0,     0,
       0,     0,     8,     0,     7,   101,    87,    89,   112,   107,
     111,     0,   108,     0,    17,    14,    11,    16,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   104,    37,    38,
      39,    40,    41,    20,    10,    15,    33,    42,     0,    44,
      48,    51,    54,    59,    62,    64,    66,    68,    70,    72,
      80,    13,     0,    74,    75,    76,    77,    78,    79,    38,
      88,    17,     0,     0,     0,     0,     0,     0,   125,   119,
      82,     0,   123,   124,   114,     0,   121,   115,   116,   117,
     118,     9,     6,   110,   105,     0,   106,     0,     0,    34,
      35,     0,     0,     0,     0,   173,     0,     0,     0,   103,
      25,    26,     0,     0,     0,     0,    42,    36,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   102,   135,   137,
       0,     0,     0,     0,     0,   136,     0,   126,   120,   122,
     109,   113,   200,     0,     0,   147,     0,     0,     0,     0,
     193,   166,     0,     0,     0,     0,     0,   179,     0,    12,
       0,    22,     0,    18,     0,     0,     0,    24,    27,    28,
      29,    30,    31,    32,    81,    45,    46,    47,    49,    50,
      52,    53,    57,    58,    55,    56,    60,    61,    63,    65,
      67,    69,    71,     0,   138,     0,     0,     0,     0,     0,
      83,   139,     0,   162,     0,     0,     0,     0,     0,     0,
     172,     0,     0,     0,    43,    23,     0,    21,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   201,   146,     0,
     149,     0,   192,   195,     0,     0,   165,   168,     0,     0,
     175,   178,     0,   181,     0,    19,     0,     0,     0,     0,
       0,     0,    73,     0,   129,     0,     0,     0,     0,   127,
     140,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   160,     0,   133,     0,
     131,     0,     0,   148,   152,     0,   144,   151,   153,   194,
       0,   197,     0,   167,     0,   170,     0,   174,   144,   180,
       0,   183,     0,   190,   159,   161,     0,   176,   130,   134,
     132,   128,     0,   141,   158,   156,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   163,   150,     0,     0,     0,
     145,   196,     0,   199,   144,   169,   144,   171,   182,     0,
     185,     0,     0,   157,   144,   144,     0,     0,     0,     0,
       0,   142,   143,   155,   154,   198,   191,   164,   184,   188,
       0,     0,     0,   187,     0,     0,   177,   186,     0,     0,
       0,     0,     0,     0,   189
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -293,  -293,   439,  -293,  -293,  -293,  -293,  -293,  -293,  -293,
    -293,   -30,  -293,    16,   149,   167,   157,   163,   320,   321,
     325,   318,   336,  -293,   227,  -293,   -28,   -27,   -20,  -293,
     450,    12,   423,    18,  -293,   365,  -293,   -90,   126,  -293,
     382,   -95,  -293,  -293,  -293,   232,  -135,  -293,  -293,  -293,
    -293,  -292,  -293,  -293,  -293,  -293,  -293,  -293,  -293,  -293,
    -293,  -293,  -293,  -158,  -293,  -293,  -293,  -293,  -293,  -293,
    -293,  -293,  -293,    95,  -293,  -293,  -293,  -293,  -293,  -293,
    -110
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     9,    10,    11,    31,    63,    64,    65,   192,    66,
     197,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,   100,   101,    12,    20,
      21,    33,    14,    37,    41,    42,    43,   103,   104,   105,
     106,   107,   108,   109,   110,   232,   345,    83,   177,   261,
     316,   317,   346,   359,   198,   199,   200,    84,   201,    85,
     183,   269,   326,    86,   185,   298,   202,    87,   188,   274,
     332,   371,   392,   393,   203,    88,   179,   265,   322,   364,
     174
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      82,    90,    32,   161,    17,   314,   381,   172,   172,    17,
     102,   111,    13,   180,   389,   195,   389,   314,   119,   120,
     121,    13,    27,   357,   267,    28,    23,   358,   181,   127,
      25,    22,   343,   343,     1,   175,    24,   166,   136,    40,
       2,    29,   166,     3,     4,     5,    27,     6,    26,    28,
     356,     7,     8,     1,   122,   167,   196,   123,   113,     2,
     224,   124,     3,     4,     5,   160,     6,   375,   228,   178,
       7,     8,   125,   268,    54,    18,   182,   390,   263,   176,
      18,   173,   173,     1,   137,   102,    54,    38,   391,     2,
     391,   127,     3,     4,     5,    19,     6,   382,   187,   374,
       7,     8,   344,   351,   193,   155,   194,   204,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   262,    40,    27,   223,
      30,    28,   253,   254,   318,   226,   314,   229,   230,   281,
     264,   130,   131,   227,   126,   166,   138,    29,    34,    30,
     139,   140,   145,   146,   205,   206,   207,   112,   129,    39,
     244,   250,   284,     1,   135,   289,   156,    91,    45,     2,
      46,   151,     3,     4,     5,    92,     6,   114,   115,    47,
       7,     8,   116,   117,   318,   315,   166,   152,   247,   132,
      48,    49,   133,   352,   134,   308,   153,   310,   154,    93,
      94,   318,    95,    96,    97,    54,   157,   260,   147,   148,
      50,   141,   142,   158,   271,   273,   143,   144,   275,   339,
     136,   340,   341,   162,   283,   163,   286,   288,   165,   377,
     164,   378,   171,    51,    52,    53,    54,    55,    56,   383,
     384,   149,   150,   184,    58,    89,    60,    61,    62,   276,
     277,   190,   278,   225,   279,   280,   189,   166,    98,    30,
      99,    27,    35,   313,    28,    15,   321,   231,   325,     1,
     328,   329,   331,   245,   246,     2,   252,   166,     3,     4,
       5,   233,     6,     1,   255,   166,     7,     8,   234,     2,
     208,   209,     3,     4,     5,   235,     6,   307,   166,   237,
       7,     8,   212,   213,   214,   215,   309,   166,   311,   166,
     210,   211,   216,   217,   236,   239,   241,   238,   240,   361,
     363,   365,   366,   242,   243,   368,   370,   249,     1,   248,
     251,   256,    91,    45,     2,    46,   257,     3,     4,     5,
      92,     6,   258,   266,    47,     7,     8,   270,   385,   291,
     292,   388,   293,   294,   295,    48,    49,   296,   297,   299,
     301,   300,   302,   395,    93,    94,   303,    95,    96,    97,
     399,   304,   401,   306,   403,    50,   305,   312,   319,     1,
     323,   333,   327,    44,    45,     2,    46,   334,     3,     4,
       5,   335,     6,   336,   337,    47,     7,     8,    51,    52,
      53,    54,    55,    56,   348,   338,    48,    49,   342,    58,
      89,    60,    61,    62,   347,    44,    45,   349,    46,   350,
     353,   354,   355,    98,    30,   168,    50,    47,   360,   367,
     357,   372,   373,    91,    45,   376,    46,   379,    48,    49,
     380,    92,   386,   387,   394,    47,   396,   404,    16,    51,
      52,    53,    54,    55,    56,   398,    48,    49,    50,   400,
      58,    89,    60,    61,    62,    93,    94,   402,    95,    96,
      97,   218,   221,   219,    98,    36,    50,   282,   220,   128,
     170,    51,    52,    53,    54,    55,    56,   169,   290,   397,
       0,   222,    58,    89,    60,    61,    62,     0,     0,    51,
      52,    53,    54,    55,    56,     0,   159,     0,     0,     0,
      58,    89,    60,    61,    62,    44,    45,     0,    46,     0,
       0,     0,     0,     0,    98,    30,     0,    47,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    48,    49,
       0,     0,     0,     1,     0,     0,     0,    44,    45,     2,
      46,     0,     3,     4,     5,     0,     6,     0,    50,    47,
       7,     8,     0,     0,    44,    45,     0,    46,     0,     0,
      48,    49,     0,     0,     0,     0,    47,     0,     0,     0,
       0,    51,    52,    53,    54,    55,    56,    48,    49,     0,
      50,     0,    58,    89,    60,    61,    62,    44,    45,     0,
      46,     0,     0,     0,     0,     0,    98,    50,     0,    47,
       0,     0,     0,    51,    52,    53,    54,    55,    56,     0,
      48,    49,     0,     0,    58,    89,    60,    61,    62,     0,
      51,    52,    53,    54,    55,    56,     0,     0,     0,    57,
      50,    58,    59,    60,    61,    62,    44,    45,     0,    46,
       0,     0,     0,     0,   186,     0,     0,     0,    47,     0,
       0,     0,     0,    51,    52,    53,    54,    55,    56,    48,
      49,     0,     0,     0,    58,    89,    60,    61,    62,     0,
       0,     0,     0,     0,     0,    44,    45,     0,    46,    50,
       0,     0,     0,     0,     0,     0,     0,    47,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    48,    49,
       0,     0,    51,    52,    53,    54,    55,    56,   191,     0,
       0,     0,     0,    58,    89,    60,    61,    62,    50,     0,
       0,     0,     0,   259,    44,    45,     0,    46,     0,     0,
       0,     0,     0,     0,     0,     0,    47,     0,     0,     0,
       0,    51,    52,    53,    54,    55,    56,    48,    49,     0,
       0,     0,    58,    89,    60,    61,    62,    44,    45,     0,
      46,     0,     0,     0,     0,     0,     0,    50,     0,    47,
       0,     0,     0,    44,    45,     0,    46,     0,     0,     0,
      48,    49,   272,     0,     0,    47,     0,     0,     0,     0,
      51,    52,    53,    54,    55,    56,    48,    49,     0,     0,
      50,    58,    89,    60,    61,    62,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    50,     0,     0,     0,
       0,     0,     0,    51,    52,    53,    54,    55,    56,   285,
       0,     0,     0,     0,    58,    89,    60,    61,    62,    51,
      52,    53,    54,    55,    56,   287,    44,    45,     0,    46,
      58,    89,    60,    61,    62,     0,     0,     0,    47,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
      49,     0,     0,     0,     0,    44,    45,     0,    46,     0,
       0,     0,     0,     0,     0,     0,     0,    47,     0,    50,
       0,     0,     0,     0,     0,     0,     0,     0,    48,    49,
       0,     0,     0,     0,     0,     0,     0,    44,    45,   320,
      46,     0,    51,    52,    53,    54,    55,    56,    50,    47,
       0,     0,     0,    58,    89,    60,    61,    62,   324,     0,
      48,    49,     0,     0,     0,     0,    44,    45,     0,    46,
       0,    51,    52,    53,    54,    55,    56,     0,    47,     0,
      50,     0,    58,    89,    60,    61,    62,     0,     0,    48,
      49,     0,     0,     0,     0,     0,   330,     0,    44,    45,
       0,    46,     0,    51,    52,    53,    54,    55,    56,    50,
      47,     0,     0,     0,    58,    89,    60,    61,    62,     0,
       0,    48,    49,     0,     0,     0,     0,     0,    44,    45,
     362,    46,    51,    52,    53,    54,    55,    56,     0,     0,
      47,    50,     0,    58,    89,    60,    61,    62,     0,     0,
       0,    48,    49,     0,     0,     0,     0,     0,   369,     0,
      44,    45,     0,    46,    51,    52,    53,    54,    55,    56,
       0,    50,    47,     0,     0,    58,    89,    60,    61,    62,
       0,     0,     0,    48,    49,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    51,    52,    53,    54,    55,    56,
       0,     0,     0,    50,     0,    58,    89,    60,    61,    62,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    51,    52,    53,    54,
      55,   118,     0,     0,     0,     0,     0,    58,    89,    60,
      61,    62
};

static const yytype_int16 yycheck[] =
{
      28,    29,    22,    93,     8,     8,    11,     8,     8,     8,
      30,    31,     0,   123,     8,     8,     8,     8,    48,    49,
      79,     9,    79,    54,    11,    82,    14,    58,    11,    56,
      81,    13,    11,    11,     4,    11,    18,    81,    68,    27,
      10,    98,    81,    13,    14,    15,    79,    17,    99,    82,
     342,    21,    22,     4,    79,    99,    49,    79,    40,    10,
      99,    79,    13,    14,    15,    92,    17,   359,   163,    70,
      21,    22,    79,    60,    77,    79,    59,    69,    11,    55,
      79,    82,    82,     4,    68,   105,    77,     8,    82,    10,
      82,   118,    13,    14,    15,    99,    17,   102,   126,   102,
      21,    22,    81,    81,   132,    35,   133,   135,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   236,   115,    79,   156,
     100,    82,   227,   228,   292,   162,     8,   164,   166,   249,
      73,    31,    32,   163,    79,    81,    86,    98,    22,   100,
      90,    91,    36,    37,   138,   139,   140,    31,    83,    80,
     190,    97,   252,     4,    98,   255,    96,     8,     9,    10,
      11,    85,    13,    14,    15,    16,    17,    80,    81,    20,
      21,    22,    80,    81,   342,    57,    81,    94,    83,    79,
      31,    32,    82,   328,    84,   285,    95,   287,    34,    40,
      41,   359,    43,    44,    45,    77,    83,   235,    92,    93,
      51,    87,    88,    99,   242,   243,     6,     7,   246,   309,
     250,   311,   312,    79,   251,    79,   253,   254,    99,   364,
      79,   366,     8,    74,    75,    76,    77,    78,    79,   374,
     375,    38,    39,    63,    85,    86,    87,    88,    89,    47,
      48,    80,    50,    41,    52,    53,    80,    81,    99,   100,
     101,    79,    80,   291,    82,     0,   294,     8,   296,     4,
     298,   299,   300,    80,    81,    10,    80,    81,    13,    14,
      15,    80,    17,     4,    80,    81,    21,    22,    98,    10,
     141,   142,    13,    14,    15,    81,    17,    80,    81,    81,
      21,    22,   145,   146,   147,   148,    80,    81,    80,    81,
     143,   144,   149,   150,    98,    81,    11,    98,    98,   347,
     348,   349,   350,    98,    81,   353,   354,    79,     4,    84,
      79,    81,     8,     9,    10,    11,    83,    13,    14,    15,
      16,    17,    11,    11,    20,    21,    22,    81,   376,    97,
      81,   379,    98,    81,    98,    31,    32,    81,    64,    98,
      79,    81,    79,   391,    40,    41,    79,    43,    44,    45,
     398,    79,   400,    80,   402,    51,    79,    42,    11,     4,
      11,    80,    98,     8,     9,    10,    11,    80,    13,    14,
      15,    80,    17,     8,    80,    20,    21,    22,    74,    75,
      76,    77,    78,    79,    81,    99,    31,    32,    98,    85,
      86,    87,    88,    89,    98,     8,     9,    98,    11,    81,
      98,    81,    80,    99,   100,   101,    51,    20,    80,    80,
      54,    98,    98,     8,     9,    98,    11,    98,    31,    32,
      81,    16,    80,    80,    98,    20,    80,    83,     9,    74,
      75,    76,    77,    78,    79,    81,    31,    32,    51,    81,
      85,    86,    87,    88,    89,    40,    41,    81,    43,    44,
      45,   151,   154,   152,    99,    25,    51,   250,   153,    56,
     115,    74,    75,    76,    77,    78,    79,   105,   256,   394,
      -1,   155,    85,    86,    87,    88,    89,    -1,    -1,    74,
      75,    76,    77,    78,    79,    -1,    99,    -1,    -1,    -1,
      85,    86,    87,    88,    89,     8,     9,    -1,    11,    -1,
      -1,    -1,    -1,    -1,    99,   100,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,
      -1,    -1,    -1,     4,    -1,    -1,    -1,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,    17,    -1,    51,    20,
      21,    22,    -1,    -1,     8,     9,    -1,    11,    -1,    -1,
      31,    32,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,
      -1,    74,    75,    76,    77,    78,    79,    31,    32,    -1,
      51,    -1,    85,    86,    87,    88,    89,     8,     9,    -1,
      11,    -1,    -1,    -1,    -1,    -1,    99,    51,    -1,    20,
      -1,    -1,    -1,    74,    75,    76,    77,    78,    79,    -1,
      31,    32,    -1,    -1,    85,    86,    87,    88,    89,    -1,
      74,    75,    76,    77,    78,    79,    -1,    -1,    -1,    83,
      51,    85,    86,    87,    88,    89,     8,     9,    -1,    11,
      -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,    20,    -1,
      -1,    -1,    -1,    74,    75,    76,    77,    78,    79,    31,
      32,    -1,    -1,    -1,    85,    86,    87,    88,    89,    -1,
      -1,    -1,    -1,    -1,    -1,     8,     9,    -1,    11,    51,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,
      -1,    -1,    74,    75,    76,    77,    78,    79,    80,    -1,
      -1,    -1,    -1,    85,    86,    87,    88,    89,    51,    -1,
      -1,    -1,    -1,    56,     8,     9,    -1,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,
      -1,    74,    75,    76,    77,    78,    79,    31,    32,    -1,
      -1,    -1,    85,    86,    87,    88,    89,     8,     9,    -1,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    20,
      -1,    -1,    -1,     8,     9,    -1,    11,    -1,    -1,    -1,
      31,    32,    66,    -1,    -1,    20,    -1,    -1,    -1,    -1,
      74,    75,    76,    77,    78,    79,    31,    32,    -1,    -1,
      51,    85,    86,    87,    88,    89,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,
      -1,    -1,    -1,    74,    75,    76,    77,    78,    79,    80,
      -1,    -1,    -1,    -1,    85,    86,    87,    88,    89,    74,
      75,    76,    77,    78,    79,    80,     8,     9,    -1,    11,
      85,    86,    87,    88,    89,    -1,    -1,    -1,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    -1,    -1,    -1,    -1,     8,     9,    -1,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,    51,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     8,     9,    71,
      11,    -1,    74,    75,    76,    77,    78,    79,    51,    20,
      -1,    -1,    -1,    85,    86,    87,    88,    89,    61,    -1,
      31,    32,    -1,    -1,    -1,    -1,     8,     9,    -1,    11,
      -1,    74,    75,    76,    77,    78,    79,    -1,    20,    -1,
      51,    -1,    85,    86,    87,    88,    89,    -1,    -1,    31,
      32,    -1,    -1,    -1,    -1,    -1,    67,    -1,     8,     9,
      -1,    11,    -1,    74,    75,    76,    77,    78,    79,    51,
      20,    -1,    -1,    -1,    85,    86,    87,    88,    89,    -1,
      -1,    31,    32,    -1,    -1,    -1,    -1,    -1,     8,     9,
      72,    11,    74,    75,    76,    77,    78,    79,    -1,    -1,
      20,    51,    -1,    85,    86,    87,    88,    89,    -1,    -1,
      -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    68,    -1,
       8,     9,    -1,    11,    74,    75,    76,    77,    78,    79,
      -1,    51,    20,    -1,    -1,    85,    86,    87,    88,    89,
      -1,    -1,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    74,    75,    76,    77,    78,    79,
      -1,    -1,    -1,    51,    -1,    85,    86,    87,    88,    89,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    74,    75,    76,    77,
      78,    79,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,
      88,    89
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    10,    13,    14,    15,    17,    21,    22,   104,
     105,   106,   131,   134,   135,     0,   105,     8,    79,    99,
     132,   133,   136,   134,   136,    81,    99,    79,    82,    98,
     100,   107,   131,   134,   141,    80,   133,   136,     8,    80,
     134,   137,   138,   139,     8,     9,    11,    20,    31,    32,
      51,    74,    75,    76,    77,    78,    79,    83,    85,    86,
      87,    88,    89,   108,   109,   110,   112,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   150,   160,   162,   166,   170,   178,    86,
     129,     8,    16,    40,    41,    43,    44,    45,    99,   101,
     129,   130,   131,   140,   141,   142,   143,   144,   145,   146,
     147,   131,   141,   136,    80,    81,    80,    81,    79,   114,
     114,    79,    79,    79,    79,    79,    79,   130,   135,    83,
      31,    32,    79,    82,    84,    98,   114,   116,    86,    90,
      91,    87,    88,     6,     7,    36,    37,    92,    93,    38,
      39,    85,    94,    95,    34,    35,    96,    83,    99,    99,
     130,   140,    79,    79,    79,    99,    81,    99,   101,   143,
     138,     8,     8,    82,   183,    11,    55,   151,    70,   179,
     183,    11,    59,   163,    63,   167,    65,   129,   171,    80,
      80,    80,   111,   129,   130,     8,    49,   113,   157,   158,
     159,   161,   169,   177,   129,   116,   116,   116,   117,   117,
     118,   118,   119,   119,   119,   119,   120,   120,   121,   122,
     123,   124,   125,   130,    99,    41,   130,   131,   144,   130,
     129,     8,   148,    80,    98,    81,    98,    81,    98,    81,
      98,    11,    98,    81,   114,    80,    81,    83,    84,    79,
      97,    79,    80,   144,   144,    80,    81,    83,    11,    56,
     129,   152,   183,    11,    73,   180,    11,    11,    60,   164,
      81,   129,    66,   129,   172,   129,    47,    48,    50,    52,
      53,   183,   127,   130,   140,    80,   130,    80,   130,   140,
     148,    97,    81,    98,    81,    98,    81,    64,   168,    98,
      81,    79,    79,    79,    79,    79,    80,    80,   140,    80,
     140,    80,    42,   129,     8,    57,   153,   154,   166,    11,
      71,   129,   181,    11,    61,   129,   165,    98,   129,   129,
      67,   129,   173,    80,    80,    80,     8,    80,    99,   140,
     140,   140,    98,    11,    81,   149,   155,    98,    81,    98,
      81,    81,   149,    98,    81,    80,   154,    54,    58,   156,
      80,   129,    72,   129,   182,   129,   129,    80,   129,    68,
     129,   174,    98,    98,   102,   154,    98,   149,   149,    98,
      81,    11,   102,   149,   149,   129,    80,    80,   129,     8,
      69,    82,   175,   176,    98,   129,    80,   176,    81,   129,
      81,   129,    81,   129,    83
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   103,   104,   104,   105,   105,   106,   106,   107,   107,
     108,   108,   108,   108,   109,   109,   110,   110,   111,   111,
     112,   112,   112,   112,   112,   112,   112,   113,   113,   113,
     113,   113,   113,   114,   114,   114,   114,   115,   115,   115,
     115,   115,   116,   116,   117,   117,   117,   117,   118,   118,
     118,   119,   119,   119,   120,   120,   120,   120,   120,   121,
     121,   121,   122,   122,   123,   123,   124,   124,   125,   125,
     126,   126,   127,   127,   128,   128,   128,   128,   128,   128,
     129,   129,   130,   130,   131,   131,   132,   132,   133,   133,
     134,   134,   135,   135,   135,   135,   135,   135,   135,   135,
     136,   136,   136,   136,   136,   136,   136,   136,   137,   137,
     138,   138,   139,   139,   140,   140,   140,   140,   140,   141,
     141,   142,   142,   143,   143,   144,   144,   145,   145,   146,
     146,   146,   146,   146,   146,   147,   147,   147,   147,   148,
     148,   149,   149,   149,   149,   150,   151,   151,   152,   152,
     153,   153,   154,   154,   155,   155,   155,   156,   156,   157,
     158,   159,   160,   161,   162,   163,   163,   164,   164,   165,
     165,   166,   167,   167,   168,   168,   169,   170,   171,   171,
     172,   172,   173,   173,   174,   174,   175,   175,   176,   176,
     177,   178,   179,   179,   180,   180,   181,   181,   182,   182,
     183,   183
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     4,     3,     1,     2,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     3,
       1,     4,     3,     4,     3,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     4,     1,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     5,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     3,     2,     3,     1,     3,     3,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     4,     4,     3,     4,     4,     3,     1,     3,
       2,     1,     1,     3,     1,     1,     1,     1,     1,     2,
       3,     1,     2,     1,     1,     1,     2,     5,     7,     5,
       7,     6,     7,     6,     7,     2,     2,     2,     3,     1,
       3,     1,     4,     4,     0,     9,     3,     1,     3,     1,
       3,     1,     1,     1,     4,     4,     1,     2,     0,     5,
       4,     5,     4,     6,    11,     3,     1,     3,     1,     3,
       1,     9,     2,     0,     2,     0,     5,    12,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     1,     9,
       5,    11,     3,     1,     3,     1,     3,     1,     3,     1,
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
      
#line 1749 "main.tab.c" /* yacc.c:1646  */
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
#line 492 "main.y" /* yacc.c:1906  */

extern char* yytext;
extern int line_no;
extern int column;
char* input_filename="main.in";

void printLine(int line_no){
	int line = 1;
	char temp[500],nl;//line buffer
	FILE* yyerrFile = fopen(input_filename,"r");

	while(fgets(temp,sizeof temp, yyerrFile)!=NULL){
		if(line == line_no){
			if(temp[strlen(temp)-1]!='\n')
				nl='\n';
			printf("%s%c",temp,nl);
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
	printf("Error at line number: %d\n", line_no);
	printLine(line_no);
//	printf("%*s\n%*s\n", column, "^", column, error_msg);
	printf("%s\n",error_msg);
//	exit(1); // it exits by itself anyway
}

extern FILE* yyin;

int main(int argc, char* argv[]){
	if(argc>1)
		input_filename = argv[1];
	yyin = fopen(input_filename,"r");

	int err = 0;
	#if YYDEBUG
		yydebug=YYDEBUG_VAL;
	#endif
	do { 
		err = yyparse();
	} while(!feof(yyin));
	if(err==0)
		printf("File parsed successfully!\n");
	fclose(yyin);
	return 0;
}
