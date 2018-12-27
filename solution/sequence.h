#ifndef SEQUENCE_H
#define SEQUENCE_H

#include "type.h"
#include <string>



class Sequence : public Type
{

public:
	Sequence(bool isTemp = false) : Type(isTemp) {}
	virtual size_t length()const;
	virtual bool isPrintable()const override = 0;
	virtual std::string toString()const override = 0;
	virtual std::string type()const override;
	virtual bool isSequence() const override;
};
#endif // SEQUENCE_H