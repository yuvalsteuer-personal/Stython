#ifndef BOOLEAN_H
#define BOOLEAN_H

#include "type.h"
#include <string>



class Boolean : public Type
{
private:
	bool _value = true;

public:
	Boolean(bool value = true, bool isTemp = false) : _value(value), Type(isTemp) {}

	bool getValue()const;
	void setValue(bool value);


	//virtual
public:
	virtual bool isPrintable()const override;
	virtual std::string toString()const override;
	virtual std::string type()const override;
};


#endif // BOOLEAN_H