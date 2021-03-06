#pragma once

#include "Simulator.h"
#include "PipelineStage.h"

class MemAccess : public PipelineStage{
	public:
		MemAccess(Simulator *sim);
		void update();
		void execute();
		void flush();
		int inA, inData, outData;
	private:
};
