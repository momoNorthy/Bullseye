#pragma once
#include <memory>
#include <string>

namespace Bullseye
{
	class B7Lexer
	{
	public:
		B7Lexer(const std::shared_ptr<std::string> &p_raw) :_raw(p_raw) {}
	private:
		std::shared_ptr<std::string> _raw;
	};
}