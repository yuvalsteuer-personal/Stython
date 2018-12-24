#ifndef INTEGER_H
#define INTEGER_H

#include "type.h"
#include <string>



class Integer : public Type
{
private:
	int _value = 0;

public:
	Integer(int value = 0,bool isTemp = false) : _value(value), Type(isTemp) {}

	int getValue()const;
	void setValue(int value);
	
	//virtuals
public:
	virtual std::string toString()const override;
	virtual bool isPrintable()const override;
	virtual std::string type()const override;
};
#endif // INTEGER_H