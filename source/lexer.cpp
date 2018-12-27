#include "stdafx.h"
#include "lexer.h"
#include "usefulFunctions.h"
#include "syntaxException.h"




//gets the next word according to the pattern and removes it from the string.
std::string Lexer::getNextWord(std::string & input, const std::regex & pattern)
{
	std::smatch match;
	if (std::regex_search(input, match, pattern))
	{
		if (input.substr(0, match.str().length()) == match.str())
		{
			input = input.substr(match.str().length());
			return match.str();
		}
	}
	return "";
}
//gets the next word according to name pattern. returns "" if name isn't next word.
std::string Lexer::getNextName(std::string & input)
{
	static std::regex namePattern(R"cr([a-zA-Z_]\w*)cr");
	return getNextWord(input,namePattern);
}

//gets the next word according to the integer pattern, returns "" if integer isn't the next word.
std::string Lexer::getNextIntegerLiteral(std::string & input)
{
	static std::regex integerLiteralPattern(R"cr(-?\d+)cr");
	return getNextWord(input,integerLiteralPattern);
}

//gets the next word according to the float pattern, returns "" if the next word isn't a float literal.
std::string Lexer::getNextFloatLiteral(std::string & input)
{
	static std::regex floatLiteralPattern(R"cr(-?\d+\.\d*)cr");
	return getNextWord(input, floatLiteralPattern);
}

//gets the next word according to the string literal pattern, returns "" if the next word isn't a string literal.
std::string Lexer::getNextStringLiteral(std::string & input)
{
	std::regex stringLiteralPattern(R"cr(("|')(?:[^"'\\]|\\.)*\1)cr");
	return getNextWord(input, stringLiteralPattern);
}

//gets the next operator word, if the next word isn't a operator returns "".
std::string Lexer::getNextOperator(std::string & input)
{
	std::regex operatorPattern(R"cr((~|\.|(!=)|(&|\||\^|\+|\-|\/|\*|=|>|<|\*\*)=?)cr");
	return getNextWord(input, operatorPattern);
}

//gets the next seperator word, if the next word isn't a operator returns "".
std::string Lexer::getNextSeperator(std::string & input)
{
	std::regex seperatorPattern(R"cr([\(\)\[\]\{\}\,\:\;])cr");
	return getNextWord(input, seperatorPattern);
}

Token Lexer::getNextToken(std::string & input)
{
	std::string tokenValue;
	
	if (!input.empty())
	{
		char nextChar = input[0];
		std::string op;
		if(input.length() > 1)
			op = std::to_string(input[0]) + std::to_string(input[1]);
		
		if ((Useful::isLetter(nextChar) || Useful::isUnderscore(nextChar)) && (tokenValue = getNextName(input)) != "")
		{
			if(tokenValue == "True" || tokenValue == "False")
				return Token(tokenValue, Token::BOOLEAN);
			return Token(tokenValue, Token::NAME);
		}
		else if (Useful::isDigit(nextChar) && (tokenValue = getNextIntegerLiteral(input)) != "")
			return Token(tokenValue, Token::INTEGER);
		else if (Useful::isDigit(nextChar) && (tokenValue = getNextFloatLiteral(input)) != "")
			return Token(tokenValue, Token::FLOAT);
		else if ((nextChar == '\'' || nextChar == '\"') && (tokenValue = getNextStringLiteral(input)) != "")
			return Token(tokenValue, Token::STRING);
		else if (Useful::isSeperator(nextChar) && (tokenValue = getNextSeperator(input)) != "")
			return Token(tokenValue, Token::SEPERATOR);
		else if (Useful::isOperator(op) && (tokenValue = getNextOperator(input)) != "")
			return Token(tokenValue, Token::OPERATOR);
		else
			throw SyntaxException();
	}


	
	return Token();
}
