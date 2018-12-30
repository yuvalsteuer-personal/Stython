#ifndef TOKEN_H
#define TOKEN_H

#include <string>

class Token
{
public:
	enum TokenType
	{
		NAME,
		INTEGER,
		FLOAT,
		HEXADECIMAL,
		BINARY,
		BOOLEAN,
		STRING,
		LIST,
		OPERATOR,
		SEPERATOR,
		NEWLINE,
		INDENT,
		DEDENT,
		UNKNOWN
	};
private:
	std::string _value;
	TokenType _tokenType;

public:
	//Default Constructor
	Token();

	//Overloaded Constructor
	Token(std::string value, TokenType type);
	
	//getters and setters
	std::string getValue()const;
	TokenType getTokenType()const;




};



#endif
