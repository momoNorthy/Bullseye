#include "Interpreter.hpp"
#include "Lexer/Token.hpp"
//#include "VirtualMachine/VirtualMachine.hpp"
//#include "VirtualMachine/Instruction.hpp"

int main(int argc, char *argv[])
{
	/*bullseye::B7VirtualMachine bvm;
	bvm.executeCode(
		{
		}
	);
	bvm.printRegValues();
	*/
	bullseye::script::Interpreter Interpreter(argc, argv);
	return 0;
}