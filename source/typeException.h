#ifndef TYPE_EXCEPTION_H
#define TYPE_EXCEPTION_H

#include <string>
#include "interperterException.h"
#include "type.h"

class TypeException : public InterperterException
{
private:
	std::string _strException = "TypeError : object of type \'int\' has no len()";
public:
	TypeException(Type* typeEx);	
	virtual const char* what() const throw() override;
};
#endif