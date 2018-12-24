#include "stdafx.h"
#include "sequence.h"

size_t Sequence::length() const
{
	return 0;
}

std::string Sequence::type() const
{
	return std::string("<type \'Sequence\'>");
}

bool Sequence::isSequence() const
{
	return true;
}
