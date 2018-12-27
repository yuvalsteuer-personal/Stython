#include "stdafx.h"
#include "void.h"


bool Void::isPrintable()const
{
	return false;
}

std::string Void::toString() const
{
	return std::string();
}

std::string Void::type() const
{
	return std::string("<type \'void\'>");
}
