#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <sstream>
#include <memory>

#include "Lexer/Lexer.hpp"

namespace Bullseye
{
	class B7Interpreter final
	{
	public:
		B7Interpreter(const int &arg1, char **arg2)
		{
			if (arg1 == 1 || arg1 > 3)
			{
				std::cout << "Unexpected number of arguments" << std::endl;
				std::exit(EXIT_FAILURE);
				// TODO: To let user input again.
			}
			_args_num = arg1;
			for (int i = 1; i < arg1; i++)
			{
				_args.push_back(arg2[i]);
			}
			parseArgs();
			loadFile();
			lexicalAnalysis();
		}
		void parseArgs()
		{
			/*
			*	    Bullseye Script v1.0 only supports "B7Interpreter <mode> <filepath>"
			*	or "B7Interpreter <filepath>"
			*	    Bullseye Script v1.0's B7Interpreter DO NOT check the arguments. 
			*/
			if (_args_num == 2)
			{
				_path = _args[1];
			}
			else
			{
				_mode = std::atoi(_args[1].c_str());
				_path = _args[2];
			}
		}
		void loadFile()
		{
			std::ifstream in(_path, std::ifstream::in);
			if (!in)
			{
				std::cout << "Invalid path" << std::endl;
				std::exit(EXIT_FAILURE);
				// TODO: To let user input again.
			}
			std::stringstream ssm;
			ssm << in.rdbuf();
			_p_raw = std::make_shared<std::string>(ssm.str());
			std::cout << "The source file has been loaded." << std::endl;
		}
		void lexicalAnalysis()
		{
			_lexer = std::make_shared<B7Lexer>(_p_raw);
		}
	private:
		int _args_num = 0;
		int _mode = 0;
		std::string _path;
		std::shared_ptr<std::string> _p_raw;
		std::vector<std::string> _args;

		std::shared_ptr<B7Lexer> _lexer;
	};
}
