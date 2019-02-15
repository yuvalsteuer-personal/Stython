/* Copyright (c) 2012-2017 The ANTLR Project. All rights reserved.
 * Use of this file is governed by the BSD 3-clause license that
 * can be found in the LICENSE.txt file in the project root.
 */

//
//  main.cpp
//  antlr4-cpp-demo
//
//  Created by Mike Lischke on 13.03.16.
//

#include <iostream>

#include "antlr4-runtime.h"
#include "Python3Lexer.h"
#include "Python3Parser.h"


using namespace antlrcpptest;
using namespace antlr4;

int main(void)
{
	int line = 26;
	ANTLRInputStream input(R"_(print('hello'))_");
	Python3Lexer lexer(&input);
	
	lexer.nextToken();
	CommonTokenStream tokens(&lexer);
	tokens.fill(); // Problematic line. Breaks code
	std::cout << "blabla\n";
	auto&& ttokens = tokens.getTokens();
	for (auto& token : ttokens)
	{
		std::cout << token->toString() << std::endl;
	}
	Python3Parser parser(&tokens);
	tree::ParseTree *tree = parser.single_input();
	std::cout << tree->toStringTree(&parser) << std::endl;

	return 0;
}
