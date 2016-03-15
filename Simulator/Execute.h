#pragma once

#include "Simulator.h"

class Execute{
	public:
		Execute(Simulator *sim);
		void update();
		void execute();
		Instruction *inInstruction;
		Instruction *outInstruction;
	private:
		Simulator *MySim;
};
