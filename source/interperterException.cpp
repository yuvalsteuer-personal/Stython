#include "stdafx.h"
#include "interperterException.h"

const char* InterperterException::what()const throw()
{
	return "InterperterError: unexpected behavior Incountered!";
}