#ifndef STRING_H
#define STRING_H

#include "sequence.h"
#include <string>



class String : public Sequence
{
private:
	std::string _str = "";

public:
	String(std::string str = "", bool isTemp = false) : _str(str), Sequence(isTemp) {}

	//virtual
	virtual bool isPrintable()const override;
	virtual std::string toString()const override;
	virtual std::string type()const override;
	virtual size_t length()const override;
};

#endif // STRING_H