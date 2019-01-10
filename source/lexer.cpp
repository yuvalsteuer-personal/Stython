//#include "stdafx.h"
#include "lexer.h"
#include "usefulFunctions.h"
#include "syntaxException.h"




//matchs the next word according to the pattern and removes it from the string.
std::string Lexer::matchNextWord(std::string& input, const std::regex& pattern)
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
//matchs the next word according to name pattern. returns "" if name isn't next word.
std::string Lexer::matchNextName(std::string & input)
{
	static std::regex namePattern(R"cr([a-zA-Z_]\w*)cr");
	return Lexer::matchNextWord(input,namePattern);
}

//gets the next word according to the integer pattern, returns "" if integer isn't the next word.
std::string Lexer::matchNextIntegerLiteral(std::string & input)
{
	static std::regex integerLiteralPattern(R"st(-?\d+)st");
	return Lexer::matchNextWord(input,integerLiteralPattern);
}

//gets the next word according to the integer pattern, returns "" if integer isn't the next word.
std::string Lexer::matchNextBinaryLiteral(std::string & input)
{
	std::regex binaryLiteralPattern(R"st(0b(0|1)+)st");
	return Lexer::matchNextWord(input, binaryLiteralPattern);
}

std::string Lexer::matchNextHexadecimalLiteral(std::string & input)
{
	std::regex hexadecimalLiteralPattern(R"st(0(x|X)([0-9]|[A-F]|[a-f])+)st");
	return Lexer::matchNextWord(input, hexadecimalLiteralPattern);
}

//gets the next word according to the float pattern, returns "" if the next word isn't a float literal.
std::string Lexer::matchNextFloatLiteral(std::string & input)
{
	static std::regex floatLiteralPattern(R"st(-?\d+\.\d*)st");
	return Lexer::matchNextWord(input, floatLiteralPattern);
}

//gets the next word according to the string literal pattern, returns "" if the next word isn't a string literal.
std::string Lexer::matchNextStringLiteral(std::string & input)
{
	std::regex stringLiteralPattern(R"st(("|')(?:[^"'\\]|\\.)*\1)st");
	return Lexer::matchNextWord(input, stringLiteralPattern);
}

//gets the next operator word, if the next word isn't a operator returns "".
std::string Lexer::matchNextOperator(std::string & input)
{
	std::regex operatorPattern(R"st((~|\.|(!=)|(&|\||\^|\+|\-|\/|\*|=|>|<|\*\*)=?)st");
	return Lexer::matchNextWord(input, operatorPattern);
}

//gets the next seperator word, if the next word isn't a operator returns "".
std::string Lexer::matchNextSeperator(std::string & input)
{
	std::regex seperatorPattern(R"st([\(\)\[\]\{\}\,\:\;])st");
	return Lexer::matchNextWord(input, seperatorPattern);
}

Token Lexer::makeToken(const std::string & input, Token::TokenType tokenType)
{
	return Token(tokenType,input);
}



Token Lexer::matchNextToken(std::string & input)
{
	std::string lexeme;
	
	if (!input.empty())
	{
		char nextChar = input[0];
		std::string op;
		if(input.length() > 1)
			op = std::to_string(input[0]) + std::to_string(input[1]);
		
		if ((Useful::isLetter(nextChar) || Useful::isUnderscore(nextChar)) && (lexeme = matchNextName(input)) != "")
		{
			if (Useful::isBoolean(lexeme))
				return Token( Token::BOOLEAN,lexeme);
			return Token( Token::NAME,lexeme);
		}
		else if (Useful::isDigit(nextChar) && (lexeme = matchNextIntegerLiteral(input)) != "")
			return Token(Token::INTEGER,lexeme);
		else if (Useful::isDigit(nextChar) && (lexeme = matchNextFloatLiteral(input)) != "")
			return Token(Token::FLOAT,lexeme);
		else if (Useful::isDigit(nextChar) && (lexeme = matchNextBinaryLiteral(input)) != "")
			return Token(Token::BINARY,lexeme);
		else if (Useful::isDigit(nextChar) && (lexeme = matchNextHexadecimalLiteral(input)) != "")
			return Token(Token::HEXADECIMAL,lexeme);
		else if ((nextChar == '\'' || nextChar == '\"') && (lexeme = matchNextStringLiteral(input)) != "")
			return Token(Token::STRING,lexeme);
		else if (Useful::isSeperator(nextChar) && (lexeme = matchNextSeperator(input)) != "")
			return Token(Token::SEPERATOR,lexeme);
		else if (Useful::isOperator(op) && (lexeme = matchNextOperator(input)) != "")
			return Token(Token::OPERATOR,lexeme);
		else if (input[0] == '\n')
			return Token(Token::NEWLINE,lexeme);
		else
			throw SyntaxException();
	}


	
	return Token();
}
