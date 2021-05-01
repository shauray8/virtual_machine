#include "stack-vm.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]){
  if (argc < 2){
    cout << "Usage: " << "argv[0]" << "filename>" << "\n";
    return 0;
  }
  
  ifstream r(argv[1], ios::binary);
  i32 i;
  vector<i32> prog;

  while(r.read((char*)&i, sizeof(i))) { 
    prog.push_back(i);
  }
  
  StackVM vm;
  vm.loadProgram(prog);
  vm.run();
  return 0;
}

