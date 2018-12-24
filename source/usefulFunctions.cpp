#include "stdafx.h"
#include "usefulFunctions.h"
#include <regex>
#include <stack>
#include "type.h"
#include "string.h"
///regex pattern limit will be 'limit'.


bool Useful::isInteger(const std::string & str)
{
	for (char c : str)
		if (!isDigit(c))
			return false;
	return true;
}

bool Useful::isBoolean(const std::string & str)
{
	return (str == "True") || (str == "False");
}

bool Useful::isString(const std::string & str)
{
	std::regex pattern(R"limit(("|')(?:[^"'\\]|\\.)*\1)limit");
	std::smatch match;
	bool isFound = std::regex_search(str, match, pattern);//find match.
	return isFound && (str == match.str());//check if the string matched is equal to str, and that thre's a match at all.
}

bool Useful::isList(std::string str, bool IS_LIST, bool IS_STRING, std::vector<Type*>& vec, char dl)
{
	
	bool strFlag = false, listFlag = false;
	bool is_list = false;
	std::string temp;
	for (int i = 0; i < str.length(); ++i)
	{
		if (IS_STRING == false)
		{
			
			if (str[0] == '[')
			{
				is_list = isList(str.substr(1), true, false, vec, dl);
				temp += str[0];
			}
			if (IS_LIST)
			{
				if (str[0] == ']')
				{
					temp += str[0];
					vec.push_back(new List(temp));
					temp = "";
					IS_LIST = false;
				}
			}
			if (str[0] == '\'' || str[0] == '\"')
			{
				temp += str[0];
				IS_STRING = true;
			}
		}
		else if (IS_STRING == true)
		{
			if (str[0] == dl)
			{
				temp += str[0];
				vec.push_back(new String(temp));
				temp = "";
				IS_STRING = false;
			}
			else
			{
				temp += str[0];
			}
		
		}
		

	}
	return true; // fix
	
}

bool Useful::isDigit(char c)
{
	return c <= '9' && c >= '0';
}

bool Useful::isLowerLetter(char c)
{
	return false;
}

bool Useful::isUpperLetter(char c)
{
	return false;
}

bool Useful::isLetter(char c)
{
	return false;
}

bool Useful::isUnderscore(char c)
{
	return false;
}

std::vector<std::string> Useful::split(std::string str, char delimiter)
{
	str += delimiter;
	std::vector<std::string> vecSplit;
	while (true)
	{
		int nextDelimIndex = str.find_first_of(delimiter);
		if (nextDelimIndex != std::string::npos)
			vecSplit.push_back(str.substr(0, str.find_first_of(delimiter)));
		else //no more delimitter to push so break.
			break;
		str = str.substr(str.find_first_of(delimiter) + 1); // remove the latest addition to the vector.
	}
	return vecSplit;
}

std::string Useful::trim(std::string & str)
{
	return std::string();
}

std::string Useful::rtrim(std::string & str)
{
	return std::string();
}

std::string Useful::ltrim(std::string & str)
{
	return std::string();
}

std::string Useful::removeLeadingZeros(std::string & str)
{
	return std::string();
}

