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

bool Useful::isFloat(const std::string & str)
{
	std::regex pattern(R"st((\d|)\.(\d)*)st");
	std::smatch match;
	bool isFound = std::regex_search(str, match, pattern);//find match.
	return isFound && (str == match.str());//check if the string matched is equal to str, and that thre's a match at all.
}

bool Useful::isBinary(const std::string & str)
{
	std::regex pattern(R"st(0b(0|1)+)st");
	std::smatch match;
	bool isFound = std::regex_search(str, match, pattern);//find match.
	return isFound && (str == match.str());//check if the string matched is equal to str, and that thre's a match at all.
}

bool Useful::isHexadecimal(const std::string & str)
{
	std::regex pattern(R"st(0(x|X)([0-9]|[A-F]|[a-f])+)st");
	std::smatch match;
	bool isFound = std::regex_search(str, match, pattern);//find match.
	return isFound && (str == match.str());//check if the string matched is equal to str, and that thre's a match at all.
}

bool Useful::isBoolean(const std::string & str)
{
	return (str == "True") || (str == "False");
}

bool Useful::isString(const std::string & str)
{
	std::regex pattern(R"st(("|')(?:[^"'\\]|\\.)*\1)st");
	std::smatch match;
	bool isFound = std::regex_search(str, match, pattern);//find match.
	return isFound && (str == match.str());//check if the string matched is equal to str, and that thre's a match at all.
}

std::vector<Type*> Useful::toList(std::string & str)
{
	std::vector<Type*> lst;
	toList(str, false, false, lst, '\0');
	return lst;
}


void Useful::toList(std::string str, bool IS_LIST, bool IS_STRING, std::vector<Type*>& vec, char dl)
{
	
	bool strFlag = false, listFlag = false;
	std::string temp;
	for (size_t  i = 0; i < str.length(); ++i)
	{
		if (!IS_STRING)
		{
			
			if (str[0] == '[')
			{
				toList(str.substr(1), true, false, vec, dl);
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
				dl = str[0];
				IS_STRING = true;
			}
		}
		else
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
	
}
bool Useful::isList(std::string str, bool IS_LIST, bool IS_STRING, std::vector<Type*>& vec, char dl)
{
	
	bool strFlag = false, listFlag = false;
	bool is_list = false;
	std::string temp;
	for (size_t i = 0; i < str.length(); ++i)
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
	return c >= 'a' && c<='z';
}

bool Useful::isUpperLetter(char c)
{
	return c >= 'A' && c<= 'Z';
}

bool Useful::isLetter(char c)
{
	return isUpperLetter(c) || isLowerLetter(c);
}

bool Useful::isUnderscore(char c)
{
	return c == '_';
}


bool Useful::isSeperator(char c)
{
	static char seperators[] = { '(',')','[',']','{','}',',',':',';' };
	for (char sep : seperators)
	{
		if (sep == c)
			return true;
	}
	return false;
}


bool Useful::isOperator(const std::string & str)
{
	static std::string operators[] = { "&", "|" , "~" , "^", "+","-","/","*","=",".",">","<" "%", "**" , "*=","<=", ">=", "==", "<>", "!=", "&=", "|=", "^=", "%=" };
	for (auto& op : operators)
	{
		if (str == op)
			return true;
	}
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

std::string Useful::trim(std::string str)
{
	str = ltrim(str);
	str = rtrim(str);
	return str;
}

std::string Useful::rtrim(const std::string & str)
{
	int indexLast = str.find_last_not_of(' ');
	if (indexLast == std::string::npos)
		indexLast = str.find_first_not_of('\t');
	if (indexLast != std::string::npos)
		return str.substr(0,indexLast+1);
	return str;
}
std::string Useful::ltrim(const std::string & str)
{
	int indexFirst = str.find_first_not_of(' ');
	if (indexFirst == std::string::npos)
		indexFirst = str.find_first_not_of('\t');
	if (indexFirst != std::string::npos)
		return str.substr(indexFirst);
	return str;
}

std::string Useful::removeLeadingZeros(std::string str)
{
	int indexFirst = str.find_first_not_of('0');
	if (indexFirst != std::string::npos)
		return str.substr(indexFirst);
	return str;
}

