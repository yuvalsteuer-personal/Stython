#ifndef SYNTAX_EXCEPTION_H
#define SYNTAX_EXCEPTION_H

#include "interperterException.h"
#include <string>



class SyntaxException : public InterperterException
{
private:
	std::string _strExceptionDetails = std::string("invalid syntax!");
	std::string _strException = "SyntaxError: ";
public:
	SyntaxException(std::string strException = "invalid syntax!") : _strExceptionDetails(strException), _strException(std::string("SyntaxError: ") + std::string(strException)){}
	virtual const char* what()const throw() override;
};
#endif // SYNTAX_EXCEPTION_H