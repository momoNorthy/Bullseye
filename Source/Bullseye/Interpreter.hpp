#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <memory>

#include "lexer/lexer.hpp"

namespace bullseye
{
	namespace script
	{
		class Interpreter
		{
		public:
			Interpreter(const int &arg1, char **arg2)
			{
				// Initialize lexer object.
				_lexer = std::make_shared<lexer::LexerMain>();
				// Parse arguments.
				if (arg1 > 3)
				{
					std::cout << "Error: Unexpected number of arguments" << std::endl;
					std::exit(EXIT_FAILURE);
				}
				// Interprete codes line by line
				else if (arg1 == 1)
				{
					std::cout << "bullseye v1.0 (2019/2/10)\nSee https://github.com/bullseye-soft/bullseye/ for more infomation." << std::endl;
					std::shared_ptr<std::string> p_raw_line = std::make_shared<std::string>();
					while (1)
					{
						std::cout << ">>> " << std::flush;
						std::getline(std::cin, *p_raw_line);
						_lexer->analyze(p_raw_line);
					}
				}
				// Interprete source codes from a file by passing arguments.
				_args_num = arg1;
				for (int i = 1; i < arg1; i++)
				{
					_args.push_back(arg2[i]);
				}
				parseArgs();
				loadFile();
				_lexer->analyze(_p_raw);
			}
			void parseArgs()
			{
				/*
				*	    bullseye script v1.0 only supports "Interpreter <mode> <filepath>"
				*	or "Interpreter <filepath>"
				*	    bullseye script v1.0's Interpreter DO NOT check the arguments.
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
					std::cout << "Error: Invalid path" << std::endl;
					std::exit(EXIT_FAILURE);
				}
				_p_raw = std::make_shared<std::vector<std::string>>();
				std::string buffer;
				while (std::getline(in, buffer))
				{
					_p_raw->push_back(buffer);
				}
				std::cout << "Info: The source file has been loaded." << std::endl;
			}
		private:
			int _args_num = 0;
			int _mode = 0;
			std::string _path;
			std::vector<std::string> _args;
			std::shared_ptr<std::vector<std::string>> _p_raw;
			std::shared_ptr<lexer::LexerMain> _lexer;
		};
	}
}
