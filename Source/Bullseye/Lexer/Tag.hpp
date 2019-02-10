#pragma once

namespace bullseye
{
	namespace script
	{
		namespace lexer
		{
			enum Tag :int
			{
				WITH, CREATE, VAR,
				WAVELINE, IF, ELSE,
				BREAK, CONTINUE, AND,
				OR, ID, TRUE,
				FALSE, NUM
			};
		}
	}
}