#include "stdafx.h"
#include "token.h"


Token::Token(std::string value, TokenType type) :_value(value), _tokenType(type) {}
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
