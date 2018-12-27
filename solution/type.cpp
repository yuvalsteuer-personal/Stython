#include "stdafx.h"
#include "type.h"


void Type::setTemp(bool status)
{
	_isTemp = status;
}
bool Type::getIsTemp()const
{
	return _isTemp;
}

bool Type::isSequence() const
{
	return false;
}

/*std::string Type::type() const
{
	return std::string("<type \'type\'>");
}*/
