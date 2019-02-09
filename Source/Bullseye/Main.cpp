#include <cstdlib>
#include "Interpreter.hpp"
#include "VirtualMachine/VirtualMachine.hpp"
#include "VirtualMachine/Instruction.hpp"

int main(int argc, char *argv[])
{
	Bullseye::B7VirtualMachine bvm;
	bvm.executeCode(
		{
		}
	);
	bvm.printRegValues();
	//Bullseye::B7Interpreter interpreter(argc, argv);
	return EXIT_SUCCESS;
}