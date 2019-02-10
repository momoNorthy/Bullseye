#pragma once
#include <array>
#include <cstdint>
#include <iostream>
#include <initializer_list>
#include "Instruction.hpp"
#include "Data.hpp"

namespace bullseye
{
	namespace script
	{
		namespace VM
		{
			constexpr int _memory_size = 1048576; // Memory Size: 4MB.
			class B7VirtualMachine
			{
			public:
				B7VirtualMachine()
				{

				}
				void executeCode(const std::initializer_list<std::int32_t> &code)
				{
					for (const auto &term : code)
					{
						switch (term)
						{
						default:
							break;
						}
					}
				}
				void printRegValues()
				{
					std::cout << "Register EAX: " << reg_eax << std::endl;
					std::cout << "Register EBX: " << reg_ebx << std::endl;
				}
			private:
				// BVM has a memory of 4*_memory_size byte, it decides the instructions that BVM can process.
				// One intrustion takes up 32 bit space.
				std::array<std::int32_t, _memory_size> _memory;
				int32_t reg_eax = 0;
				int32_t reg_ebx = 0;
				int32_t reg_ecx = 0;
				int32_t reg_edx = 0;
			};
		}
	}
}