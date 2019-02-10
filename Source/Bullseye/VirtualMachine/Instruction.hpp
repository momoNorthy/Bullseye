#pragma once

enum InstructionSet : int
{
	PUSH,
	POP,
	TOP,
	MOV,
	ADD,
	SUB,
	JMP
};

namespace bullseye
{
	class Instruction
	{
	public:
		int getInsCode() { return _ins_code; }
	private:
		InstructionSet _ins_code;
	};
}