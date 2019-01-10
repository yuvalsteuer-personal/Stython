
%{
#include <stdio.h>
#include <iostream>
#include "token.h"
#include <vector>
#include "lexer.h"
TokenStream
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


%%


{STRING} lexerObject.TokenStream.push_back(Token(Token::STRING, yytext));
{IF} lexerObject.TokenStream.push_back(Token(Token::IF, yytext));
{WHILE} lexerObject.TokenStream.push_back(Token(Token::WHILE, yytext));
{NAME} lexerObject.TokenStream.push_back(Token(Token::NAME,yytext));
{FLOAT} lexerObject.TokenStream.push_back(Token(Token::FLOAT, yytext));
{INTEGER} lexerObject.TokenStream.push_back(Token(Token::INTEGER, yytext));
{HEX} lexerObject.TokenStream.push_back(Token(Token::HEXADECIMAL, yytext));
%%


int yyFlexLexer::yywrap()
{
	return 1;
}
int main()
{
	FlexLexer* lexer = new yyFlexLexer;
    lexer->yylex(lexerObject);
    return 0;
}
