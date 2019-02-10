#pragma once
#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include "Token.hpp"

namespace bullseye
{
	namespace script
	{
		namespace lexer
		{
			class LexerMain
			{
			public:
				void analyze(const std::shared_ptr<std::vector<std::string>> &p_raw)
				{
					std::string line;

				}
				void analyze(const std::shared_ptr<std::string> &p_raw)
				{

				}
				Token scan()
				{

				}
			private:
			};
		}
	}
}