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
    LID = 265,
    ARITH_OP = 266,
    REL_OP = 267,
    EQ_OP = 268,
    COND_OP = 269,
    LEFT_ROUND = 270,
    RIGHT_ROUND = 271,
    TYPE = 272,
    BAD_CHAR = 273,
    COMMA = 274,
    SEMICOLON = 275,
    EQUALS = 276,
    QUESTION_MARK = 277,
    COLON = 278,
    LEFT_SQUARE = 279,
    RIGHT_SQUARE = 280,
    LEFT_CURLY = 281,
    RIGHT_CURLY = 282,
    CALLOUT = 283,
    IF = 284,
    ELSE = 285,
    FOR = 286,
    WHILE = 287,
    RETURN = 288,
    BREAK = 289,
    CONTINUE = 290,
    CLASS = 291,
    PROGRAM = 292
  };
#endif

/* Value type.  */


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_HPP_INCLUDED  */
