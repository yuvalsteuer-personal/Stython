#include "stdafx.h"
#include "nameErrorException.h"
#include <string>
#include <iostream>


const char* NameErrorException::what()const throw()
{
	static std::string str = "NameError: name \'" + _name + "\' is not defined";
	str = "NameError: name \'" + _name + "\' is not defined";
	
	return str.c_str();
}