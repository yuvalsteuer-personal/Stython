#include "stdafx.h"
#include "string.h"



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
