
%{
#include <stdio.h>
#include <iostream>

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
FLOAT {DIGIT}+\.{DIGIT}*
STRING ((\")([^"'\\]|\\.)*(\"))|((')([^"'\\]|\\.)*('))


%%

{STRING} return Token(Token::STRING, yytext);
{NAME} return Token(Token::NAME,yytext);
{FLOAT} return Token(Token::FLOAT, yytext);
{INTEGER} return Token(Token::INTEGER, yytext);
{HEX}
%%


int yyFlexLexer::yywrap()
{
	return 1;
}
main()
{
	FlexLexer* lexer = new yyFlexLexer;
    lexer->yylex();
    return 0;
}
