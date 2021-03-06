#pragma once

class Simulator;
class Fetch;
class Decode;
class Execute;
class MemAccess;
class Writeback;
enum Stages{FETCH, DECODE, EXECUTE, MEMORY, WRITEBACK};

#include "PipelineStage.h"
#include <vector>
#include <cstdlib>
#include <map>
#include <set>
#include <string>
#include <stdlib.h>
#include "Instruction.h"
#include "Fetch.h"
#include "Decode.h"
#include "Execute.h"
#include "MemAccess.h"
#include "Writeback.h"



using namespace std;
const int memorySize = 1000;
class Simulator{
	public:
		
		Simulator();
		void addInstruction(Instructions I, 
							Registers reg1,
							Registers reg2, 
							Registers reg3,
							int reg_3_val=0);
		void addInstruction(Instructions I, 
							Registers reg1,
							Registers reg2, 
							string label);
		void addInstruction();
		void removeInstruction(int num);
		void parseInstructionFile(string file_name);
		void flushInstructionBuffer();
		void run();
		// Pipline Stage Objects
		Fetch *MyFetch;
		Decode *MyDecode;
		Execute *MyExecute;
		MemAccess *MyMemAccess;
		Writeback *MyWriteback;
		// Instruction Buffer 
		vector<Instruction*> instructionBuffer;
		// Register status array
		bool *registerStatus;	
		// The number of total registers
		int numRegisters;
		// Pipline Configuration Featur States
		int numCycles;
		bool fullForwarding;
		bool registerBypassing;
		bool branchPredictedNotTaken;
		bool branchesResolveInID;
		int branchesTakenIn; // 0:Fetch, 1:Decode, 2:Execute
		// TODO: add these configurations (non binary options?)
		/* - Stage where branches are taken
		   - Stage where branches are resloved */
		map<string, int> labels;
		map<int, int> registerVals;
		vector<set<int> > busyRegisters;
		map<int,int > forwardedValues;
		vector<int> memory;
		int instructionCount;
		int PC;
		int CYCLE;
	private:
};
