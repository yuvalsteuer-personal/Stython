#ifndef LEXER_H
#define LEXER_H

#include "token.h"
#include <string>
#include <regex>
class Lexer
{
private:

private:
	//gets the next word according to the pattern and removes it from the string.
	std::string getNextWord(std::string& input, const std::regex& pattern);

	//gets the next word according to name pattern. returns "" if name isn't next word.
	std::string getNextName(std::string& input);

	//gets the next word according to the integer pattern, returns "" if integer isn't the next word.
	std::string getNextIntegerLiteral(std::string& input);

	//gets the next word according to the binary pattern, returns "" if binary isn't the next word.
	std::string getNextBinaryLiteral(std::string & input);

	//gets the next word according to the hexacedimal pattern, returns "" if hexadecimal isn't the next word.
	std::string getNextHexadecimalLiteral(std::string & input);

	//gets the next word according to the float pattern, returns "" if the next word isn't a float literal.
	std::string getNextFloatLiteral(std::string& input);

	//gets the next word according to the string literal pattern, returns "" if the next word isn't a string literal.
	std::string getNextStringLiteral(std::string& input);

	//gets the next operator word, if the next word isn't a operator returns "".
	std::string getNextOperator(std::string & input);

	//gets the next seperator word, if the next word isn't a operator returns "".
	std::string getNextSeperator(std::string & input);

	//makes a new token.
	Token makeToken(const std::string& input, Token::TokenType tokenType);

public:
	//returns the next token in the stream. 
	Token getNextToken(std::string& input);
	void pushToken(Token &token)
	{

	}

};



#endif
