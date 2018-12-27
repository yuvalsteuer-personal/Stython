#include "stdafx.h"
#include "boolean.h"


bool Boolean::isPrintable()const
{
	return true;
}
std::string Boolean::toString()const
{
	return (_value) ? std::string("True") : std::string("False");
}

std::string Boolean::type() const
{
	return std::string("<type \'bool\'>");
}

bool Boolean::getValue() const
{
	return _value;
}

void Boolean::setValue(bool value)
{
	_value = value;
}
