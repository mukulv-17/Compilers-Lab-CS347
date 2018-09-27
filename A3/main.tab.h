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
