#include "stdafx.h"
#include "list.h"
#include "usefulFunctions.h"


List::List(const std::string & strList, bool isTemp) : Sequence(isTemp)
{
	
	std::string str;
	for (const auto& ch : strList)
	{
		if ((ch != '['))
		{
			if (ch != ',' && ch != ']')
			{
				str += ch;
			}
			else if (ch == ',' || ch == ']')
			{
				if(!str.empty())
				{
					Useful::trim(str);
					_lst.push_back(Parser::getType(str, false));
					str = "";
				}
			}
		}
	}
}

List::~List()
{
	for (auto& var : _lst)
	{
		delete var;
	}
}

bool List::isPrintable() const
{
	return true;
}

std::string List::toString() const
{
	std::string str("[");
	if (!_lst.empty())
	{
		for (const auto& var : _lst)
		{
			
			str += var->toString();
			str += ',';
		}

		if (str[str.size() - 1] == ',')
		{
			str[str.size() - 1] = ']';
		}
	}
	else
	{
		str += ']';
	}

	return str;
}

std::string List::type() const
{
	return std::string("<type \'list\'>");
}

size_t List::length() const
{
	return _lst.size();
}
