#ifndef NAME_ERROR_EXCEPTION_H
#define NAME_ERROR_EXCEPTION_H

#include "interperterException.h"
#include <string>



class NameErrorException : public InterperterException
{
private:
	std::string _name;

public:
	NameErrorException(std::string name) : _name(name) {}

	virtual const char* what()const throw() override;
};

#endif // NAME_ERROR_EXCEPTION_H