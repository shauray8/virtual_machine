#ifndef STACK_VM_H
#define STACK_VM_H

#include <iostream>
#include <vector>

using namespace std;

typedef int32_t i32;

class StackVM {
  i32 pc = 100; //program counter
  i32 sp = 0; //stack pointer
  vector<i32> memory;

  

}
