#include "stdafx.h"
#include "typeException.h"

TypeException::TypeException(Type * typeEx)
{
	std::string typeStr;
	if (!typeEx)
		typeStr = "<type \'Unknown\'>";
	else
		typeStr = typeEx->type();

	typeStr = typeStr.substr(1, typeStr.length() - 2);

	_strException = std::string("TypeError : object of ");
	_strException += typeStr;
	_strException += " has no len()";
}

const char * TypeException::what() const throw()
{
	return _strException.c_str();
}
