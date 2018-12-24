#ifndef INDENTATION_EXCEPTION_H
#define INDENTATION_EXCEPTION_H

#include "interperterException.h"




class IndentationException : public InterperterException
{
public:
	virtual const char* what() const throw() override;
};

#endif // INDENTATION_EXCEPTION_H