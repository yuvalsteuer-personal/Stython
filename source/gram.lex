
%{
#include <stdio.h>
#include <iostream>
#include "token.h"
#include <vector>
#include "lexer.h"

%}


/* Keywords*/
IF "if"
WHILE "while"

/* Other Tokens */
NAME [a-zA-Z_]({DIGIT}|{LETTER}|_)*
DIGIT [0-9]
LETTER [a-zA-Z]

/* Literals */
INTEGER {DIGIT}+
HEX 0(x|X)[[:xdigit:]]+
FLOAT {DIGIT}+\.{DIGIT}*
STRING ((\")([^"'\\]|\\.)*(\"))|((')([^"'\\]|\\.)*('))
INDENT \t|"    "

%%


{STRING} Lexer::tokenStream.push_back(Token(Token::STRING, yytext));
{IF} Lexer::tokenStream.push_back(Token(Token::IF, yytext));
{WHILE} Lexer::tokenStream.push_back(Token(Token::WHILE, yytext));
{NAME} Lexer::tokenStream.push_back(Token(Token::NAME,yytext));
{FLOAT} Lexer::tokenStream.push_back(Token(Token::FLOAT, yytext));
{INTEGER} Lexer::tokenStream.push_back(Token(Token::INTEGER, yytext));
{HEX} Lexer::tokenStream.push_back(Token(Token::HEXADECIMAL, yytext));
{INDENT} {}
%%


int yyFlexLexer::yywrap()
{
	return 1;
}
int main()
{
	FlexLexer* lexer = new yyFlexLexer;
    lexer->yylex();
    return 0;
}
