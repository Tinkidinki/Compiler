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

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    BAD_CHAR = 258,
    COMMA = 259,
    SEMICOLON = 260,
    EQUALS = 261,
    QUESTION_MARK = 262,
    COLON = 263,
    INT_LITERAL = 264,
    CHAR_LITERAL = 265,
    BOOL_LITERAL = 266,
    STRING_LITERAL = 267,
    ARITH_OP = 268,
    REL_OP = 269,
    EQ_OP = 270,
    COND_OP = 271,
    MINUS = 272,
    NOT = 273,
    LEFT_ROUND = 274,
    RIGHT_ROUND = 275,
    LEFT_SQUARE = 276,
    RIGHT_SQUARE = 277,
    LEFT_CURLY = 278,
    RIGHT_CURLY = 279,
    ID = 280,
    CALLOUT = 281,
    IF = 282,
    ELSE = 283,
    FOR = 284,
    WHILE = 285,
    RETURN = 286,
    BREAK = 287,
    CONTINUE = 288
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

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
