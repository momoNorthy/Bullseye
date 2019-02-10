#pragma once
#include "Token.hpp"
#include "Tag.hpp"

namespace bullseye
{
	namespace script
	{
		namespace lexer
		{
			class Num :public Token
			{
			public:
				Num(const int &value) :_value(value), Token(Tag::NUM) {}
			private:
				const int _value = 0;
			};
		}
	}
}