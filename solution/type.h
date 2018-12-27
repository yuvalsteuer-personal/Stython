#ifndef TYPE_H
#define TYPE_H


#include <string>


class Type
{
private:
	bool _isTemp = false;


public:

	Type(bool isTemp = false) : _isTemp(isTemp) {}



	void setTemp(bool status);
	bool getIsTemp()const;

	//virtuals
	virtual bool isPrintable()const = 0;
	virtual std::string toString()const = 0;
	virtual std::string type()const = 0;
	virtual bool isSequence()const;
};


#endif //TYPE_H
