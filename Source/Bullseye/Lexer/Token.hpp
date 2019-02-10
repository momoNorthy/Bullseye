#pragma once

namespace bullseye
{
	namespace script
	{
		namespace lexer
		{
			class Token
			{
			public:
				Token(const int &tag) :_tag(tag) {}
				int getTag() const { return _tag; }
			private:
				const int _tag = 0;
			};
		}
	}
}