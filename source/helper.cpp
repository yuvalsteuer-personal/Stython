#include "stdafx.h"
#include "helper.h"
#include <cctype>




bool Helper::isInteger(const std::string& str)
{
	size_t start = (str[0] == '-') ? 1 : 0;
	for (size_t i = start; i < str.size(); ++i)
	{
		if (!isDigit(str[i]))
		{
			return false;
		}
	}
	if (!str.size())
		return false;
	return true;

}
bool Helper::isBoolean(const std::string& str)
{
	return str == "True" || str == "False";
}
bool Helper::isString(const std::string& str)
{
	size_t end = str.size() - 1;

	if (str[0] == '\"' && end == str.find('\"', 1))
	{
		return true;
	}
	if (str[0] == '\'' && end == str.find('\'', 1))
	{
		return true;
	}

	return false;

}

bool Helper::isList(const std::string& str)
{
	size_t end = str.size() - 1;

	if (str[0] == '[' && end == str.find(']', 1))
	{
		return true;
	}

	return false;
}


bool Helper::isDigit(char c)
{
	return ((c >= '0') && (c <= '9'));
}
bool Helper::isLowerLetter(char c)
{
	return ((c >= 'a') && (c <= 'z'));
}
bool Helper::isUpperLetter(char c)
{
	return ((c >= 'A') && (c <= 'Z'));
}
bool Helper::isLetter(char c)
{
	return (isUpperLetter(c) || isLowerLetter(c));
}
bool Helper::isUnderscore(char c)
{
	return (c == '_');
}

void Helper::trim(std::string& str)
{
	ltrim(str);
	rtrim(str);

}
void Helper::rtrim(std::string& str)
{
	size_t lastCharIndex = str.find_last_not_of(" \t");
	if (std::string::npos != lastCharIndex)
		str = str.substr(0, lastCharIndex+1);
}
void Helper::ltrim(std::string& str)
{
	size_t firstCharIndex = str.find_first_not_of(" \t");
	if(std::string::npos != firstCharIndex)
		str = str.substr(firstCharIndex);
}
void Helper::removeLeadingZeros(std::string &str)
{
	size_t startpos = str.find_first_not_of("0");
	if (std::string::npos != startpos)
	{
		str = str.substr(startpos);
	}
}