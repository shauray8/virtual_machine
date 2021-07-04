#include "stack-vm.h"

//instuction format
//header: 2bits
//body: 30bits
//header format: 0 --> positive integer, 1 --> primitive instruction, 2 --> negative integer, 3 --> undefined

using namespace std;
// functions
StackVM::StackVM() {
	memory.reserve(1000000);
}

i32 StackVM::getType(i32 instruction) {
	i32 type = 0xc0000000;
	type = (type & instruction) >> 30;
	return type;
}

i32 StackVM::getData(i32 instruction) {
	i32 data = 0x3fffffff;
	data = data & instruction;
	return data;
}

void StackVM::fetch() {
	pc++;
}

void StackVM::decode() {
	typ = getType(memory[pc]);
	dat = getData(memory[pc]);
}

void StackVM::execute() {
	if (typ == 0 || typ == 2) {
		sp++;
		memory[sp] = dat;
	} else {
		doPrimitive();
	}
}

void StackVM::doPrimitive() {
	switch (dat) {
		case 0: // halt
			cout << "halt" << "\n";
			running = 0;
			break;
		case 1: // add
			cout << "add " << memory[sp - 1] << " " << memory[sp] << "\n";
			memory[sp - 1] = memory[sp - 1] + memory[sp];
			sp--;
			break;
    case 2: // sub
      cout << "sub " << memory[sp-1] << " " << memory[sp] << "\n";
      memory[sp-1] = memory[sp-1] - memory[sp];
      sp--;
      break;
    case 3: // mul
      cout << "mul " << memory[sp-1] << " " << memory[sp] << "\n";
      memory[sp-1] = memory[sp-1] * memory[sp];
      sp--;
      break;
    case 4: // div
      cout << "div " << memory[sp-1] << " " << memory[sp] << "\n";
      memory[sp-1] = memory[sp-1] / memory[sp];
      sp--;
      break;
	}
}

void StackVM::run() {
	pc -= 1;
	while (running == 1) {
		fetch();
		decode();
		execute();
		cout << "tos: " << memory[sp] << "\n";
	}
}

void StackVM::loadProgram(std::vector<i32> prog) {
	for (i32 i = 0; i < prog.size(); i++) {
		memory[pc + i] = prog[i];
	}	

}
