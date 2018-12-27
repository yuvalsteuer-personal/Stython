#include "stdafx.h"
#include "integer.h"


bool Integer::isPrintable()const
{
	return true;
}
std::string Integer::type() const
{
	return std::string("<type \'int\'>");
}
std::string Integer::toString()const
{
	return std::to_string(_value);
}

int Integer::getValue() const
{
	return _value;
}

void Integer::setValue(int value)
{
	_value = value;
}
