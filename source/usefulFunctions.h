#ifndef USEFUL_FUNCTIONS_H
#define USEFUL_FUNCTIONS_H

#include <string>
#include <vector>
#include "type.h"
#include "list.h"

class Useful
{
public:
	// check if the parameter is valid Integer value
	static bool isInteger(const std::string& str);

	// check if the parameter is valid Boolean value
	static bool isBoolean(const std::string& str);

	// check if the parameter is valid String value
	static bool isString(const std::string& str);

	// check if the parameter is valid List value
	static bool isList(std::string str, bool IS_LIST, bool IS_STRING, std::vector<Type*>& vec, char dl);

	// check if the parameter is digit
	static bool isDigit(char c);

	// check if the parameter is lower letter
	static bool isLowerLetter(char c);

	// check if the parameter is upper letter
	static bool isUpperLetter(char c);

	// check if the parameter is  letter
	static bool isLetter(char c);

	// check if the parameter is underscore ('_')
	static bool isUnderscore(char c);


	//split the string according to the dilimiter.
	static std::vector<std::string> split(std::string str, char delimiter);

	// remove whitespace from the begining and the end of the string
	static std::string trim(std::string &str);

	// remove whitespace from the end of the string
	static std::string rtrim(std::string &str);

	// remove whitespace from the beginning of the string
	static std::string ltrim(std::string &str);

	// remove leading zeros from the beginning of the string
	static std::string removeLeadingZeros(std::string& str);

};

#endif