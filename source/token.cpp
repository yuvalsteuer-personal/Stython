//#include "stdafx.h"
#include "token.h"


Token::Token(TokenType type,std::string value) :_value(value), _tokenType(type) {}
Token::Token(TokenType type,char* value) :_value(std::string(value)), _tokenType(type) {}
Token::Token() : _value(""), _tokenType(UNKNOWN) {}


//getters and setters
std::string Token::getValue() const
{
	return _value;
}
Token::TokenType Token::getTokenType() const
{
	return _tokenType;
}
