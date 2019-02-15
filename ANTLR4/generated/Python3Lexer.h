


// Generated from Python3.g4 by ANTLR 4.7.2

#pragma once

 	/* lexer postinclude section */
	#include "Python3Parser.h"
	#include <regex>
	#include <memory>
	#ifndef _WIN32
		#pragma GCC diagnostic ignored "-Wunused-parameter"
	#endif
	/* lexer precinclude section */


#include "antlr4-runtime.h"

 

namespace antlrcpptest {

/* lexer context section */

class  Python3Lexer : public antlr4::Lexer {
public:
  enum {
    STRING = 1, NUMBER = 2, INTEGER = 3, DEF = 4, RETURN = 5, RAISE = 6, 
    FROM = 7, IMPORT = 8, AS = 9, GLOBAL = 10, NONLOCAL = 11, ASSERT = 12, 
    IF = 13, ELIF = 14, ELSE = 15, WHILE = 16, FOR = 17, IN = 18, TRY = 19, 
    FINALLY = 20, WITH = 21, EXCEPT = 22, LAMBDA = 23, OR = 24, AND = 25, 
    NOT = 26, IS = 27, NONE = 28, TRUE = 29, FALSE = 30, CLASS = 31, YIELD = 32, 
    DEL = 33, PASS = 34, CONTINUE = 35, BREAK = 36, ASYNC = 37, AWAIT = 38, 
    NEWLINE = 39, NAME = 40, STRING_LITERAL = 41, BYTES_LITERAL = 42, DECIMAL_INTEGER = 43, 
    OCT_INTEGER = 44, HEX_INTEGER = 45, BIN_INTEGER = 46, FLOAT_NUMBER = 47, 
    IMAG_NUMBER = 48, DOT = 49, ELLIPSIS = 50, STAR = 51, OPEN_PAREN = 52, 
    CLOSE_PAREN = 53, COMMA = 54, COLON = 55, SEMI_COLON = 56, POWER = 57, 
    ASSIGN = 58, OPEN_BRACK = 59, CLOSE_BRACK = 60, OR_OP = 61, XOR = 62, 
    AND_OP = 63, LEFT_SHIFT = 64, RIGHT_SHIFT = 65, ADD = 66, MINUS = 67, 
    DIV = 68, MOD = 69, IDIV = 70, NOT_OP = 71, OPEN_BRACE = 72, CLOSE_BRACE = 73, 
    LESS_THAN = 74, GREATER_THAN = 75, EQUALS = 76, GT_EQ = 77, LT_EQ = 78, 
    NOT_EQ_1 = 79, NOT_EQ_2 = 80, AT = 81, ARROW = 82, ADD_ASSIGN = 83, 
    SUB_ASSIGN = 84, MULT_ASSIGN = 85, AT_ASSIGN = 86, DIV_ASSIGN = 87, 
    MOD_ASSIGN = 88, AND_ASSIGN = 89, OR_ASSIGN = 90, XOR_ASSIGN = 91, LEFT_SHIFT_ASSIGN = 92, 
    RIGHT_SHIFT_ASSIGN = 93, POWER_ASSIGN = 94, IDIV_ASSIGN = 95, SKIP_ = 96, 
    UNKNOWN_CHAR = 97
  };

  Python3Lexer(antlr4::CharStream *input);
  ~Python3Lexer();


  	// A queue where extra tokens are pushed on (see the NEWLINE lexer rule).
    public:
  	std::vector<std::unique_ptr<antlr4::Token>> tokens;

  	// The stack that keeps track of the indentation level.
  	std::stack<int> indents;

  	// The amount of opened braces, brackets and parenthesis.
  	int opened = 0;

  	// The most recently produced token.
  	std::unique_ptr<antlr4::Token> lastToken;
  	

    public:
  	virtual void emit(std::unique_ptr<antlr4::Token> newToken) override
  	{
  		Lexer::setToken(std::move(newToken));
  		antlr4::CommonToken* tk = new antlr4::CommonToken(antlr4::Lexer::token.get());
  		std::unique_ptr<antlr4::Token> uniqueToken = std::make_unique<antlr4::CommonToken>(tk);;
  		tokens.push_back(std::move(uniqueToken));
  	}
  	//virtual std::unique_ptr<Token> nextToken() override;
  	virtual std::unique_ptr<antlr4::Token> nextToken() override
  	{
  		if (_input->LA(1) == EOF && !this->indents.empty())
  		{
  			// Remove any trailing EOF tokens from our buffer.
  			auto it = tokens.end();
  			for (int i = tokens.size() - 1; i >= 0; i--, it--)
  			{
  				if (tokens[i]->getType() == EOF)
  				{
  					tokens.erase(it);
  				}
  			}

  			// First emit an extra line break that serves as the end of the statement.
  			this->emit(std::unique_ptr<antlr4::Token>(dynamic_cast<antlr4::Token*>(commonToken(NEWLINE, "\n"))));

  			// Now emit as much DEDENT tokens as needed.
  			while (!this->indents.empty())
  			{
  				this->emit(createDedent());
  				this->indents.pop();
  			}

  			// Put the EOF back on the token stream.
  			this->emit(std::unique_ptr<antlr4::Token>(dynamic_cast<antlr4::Token*>(commonToken(EOF, "<EOF>"))));
  		}

  		std::unique_ptr<antlr4::Token> next = antlr4::Lexer::nextToken();

  		if (next->getChannel() == antlr4::Token::DEFAULT_CHANNEL)
  		{
  			// Keep track of the last token on the default channel.
  			this->lastToken = std::move(next);
  		}
  		if (tokens.empty())
  		{
  			return next;
  		}
  		else
  		{
  			std::unique_ptr<antlr4::Token> u_ptr = std::move(tokens.front());
  			tokens.erase(tokens.begin());
  			return u_ptr;
  		}
  	}

    private:
  	std::unique_ptr<antlr4::Token> createDedent()
  	{
  		std::unique_ptr<antlr4::Token> dedent = std::make_unique<antlr4::CommonToken>(commonToken(antlrcpptest::Python3Parser::DEDENT, ""));
  		antlr4::Lexer::setLine(this->lastToken->getLine());
  		return dedent;
  	}
  	#define _tokenFactorySourcePair {dynamic_cast<TokenSource *>(this), dynamic_cast<antlr4::CharStream*>(Lexer::_input)}

  	antlr4::CommonToken *commonToken(size_t type, std::string text)
  	{
  		size_t stop = Lexer::getCharIndex() - 1;
  		size_t start = text.empty() ? stop : stop - text.length() + 1;
  		std::cout << "flag: line: 125, antlr4::CommonToken *commonToken(size_t type, std::string text)" << std::endl;
  		return new antlr4::CommonToken(_tokenFactorySourcePair, type, antlr4::Token::DEFAULT_CHANNEL, start,stop);
  	}

  	// Calculates the indentation of the provided spaces, taking the
  	// following rules into account:
  	//
  	// "Tabs are replaced (from left to right) by one to eight spaces
  	//  such that the total number of characters up to and including
  	//  the replacement is a multiple of eight [...]"
  	//
  	//  -- https://docs.python.org/3.1/reference/lexical_analysis.html#indentation
  	static int getIndentationCount(std::string spaces)
  	{
  		int count = 0;
  		for (char ch : spaces)
  		{
  			switch (ch)
  			{
  				case '\t':
  					count += 8 - (count % 8);
  					break;
  				default:
  					// A normal space char.
  					count++;
  			}
  		}
  		return count;
  	}

  	bool atStartOfInput()
  	{
  		return antlr4::Lexer::getCharPositionInLine() == 0 && antlr4::Lexer::getLine() == 1;
  	}

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

  virtual void action(antlr4::RuleContext *context, size_t ruleIndex, size_t actionIndex) override;
  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;

  /* private lexer declarations/members section */

  // Individual action functions triggered by action() above.
  void NEWLINEAction(antlr4::RuleContext *context, size_t actionIndex);
  void OPEN_PARENAction(antlr4::RuleContext *context, size_t actionIndex);
  void CLOSE_PARENAction(antlr4::RuleContext *context, size_t actionIndex);
  void OPEN_BRACKAction(antlr4::RuleContext *context, size_t actionIndex);
  void CLOSE_BRACKAction(antlr4::RuleContext *context, size_t actionIndex);
  void OPEN_BRACEAction(antlr4::RuleContext *context, size_t actionIndex);
  void CLOSE_BRACEAction(antlr4::RuleContext *context, size_t actionIndex);

  // Individual semantic predicate functions triggered by sempred() above.
  bool NEWLINESempred(antlr4::RuleContext *_localctx, size_t predicateIndex);

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace antlrcpptest
