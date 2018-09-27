/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 36 "parser.y" /* yacc.c:1909  */

    node *Node;

#line 140 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
