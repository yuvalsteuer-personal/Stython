#ifndef USEFUL_FUNCTIONS_H
#define USEFUL_FUNCTIONS_H

#include <string>
#include <vector>
#include "type.h"
#include "list.h"

class Useful
{
public:


	// check if the parameter is a valid Integer value.
	static bool isInteger(const std::string& str);
	
	// check if the parameter is a valid Floating point value.
	static bool isFloat(const std::string& str);

	// check if the parameter is a valid Binary value.
	static bool isBinary(const std::string& str);

	// check if the parameter is a valid Hexadecimal value.
	static bool isHexadecimal(const std::string& str);

	// check if the parameter is a valid Boolean value.
	static bool isBoolean(const std::string& str);

	// check if the parameter is a valid String value.
	static bool isString(const std::string& str);

	static std::vector<Type*> toList(std::string& str);

	static void toList(std::string str, bool IS_LIST, bool IS_STRING, std::vector<Type*>& vec, char dl);

	// check if the parameter is a valid List value.
	static bool isList(std::string str, bool IS_LIST, bool IS_STRING, std::vector<Type*>& vec, char dl);

	// check if the parameter is a digit.
	static bool isDigit(char c);

	// check if the parameter is a lower letter.
	static bool isLowerLetter(char c);

	// check if the parameter is a upper letter.
	static bool isUpperLetter(char c);

	// check if the parameter is a letter.
	static bool isLetter(char c);

	// check if the parameter is a underscore ('_')
	static bool isUnderscore(char c);

	//checks if the parameter is a seperator.
	static bool isSeperator(char c);

	//checks if the parameter is a operator.
	static bool isOperator(const std::string& str);

	//split the string according to the dilimiter.
	static std::vector<std::string> split(std::string str, char delimiter);

	// remove whitespace from the begining and the end of the string.
	static std::string trim(std::string str);

	// remove whitespace from the end of the string.
	static std::string rtrim(const std::string &str);

	// remove whitespace from the beginning of the string.
	static std::string ltrim(const std::string &str);

	// remove leading zeros from the beginning of the string.
	static std::string removeLeadingZeros(std::string str);



};

#endif