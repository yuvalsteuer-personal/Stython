#include "stdafx.h"
#include "string.h"



String::String(std::string str, bool isTemp) : _str(str), Sequence(isTemp)
{
	if ((_str[0] == '\"' || _str[0] == '\'') && (_str[str.length() - 1] == '\"' || _str[str.length() - 1] == '\''))
	{
		_str[0] = '\'';
		_str[_str.length() - 1] = '\'';
	}
}

bool String::isPrintable()const
{
	return true;
}

std::string String::toString()const
{
	return _str;
}

std::string String::type() const
{
	return std::string("<type \'str\'>");
}

size_t String::length() const
{
	return _str.length()-2;
}
