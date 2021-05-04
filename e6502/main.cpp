#include <stdio.h>
#include <stdlib.h>

using namespace std;
using Byte = unsigned char;
using Word = unsigned short;
using u32 = unsigned int;

struct Mem {
  static constexpr u32 MAX_MEM = 1024 * 64;
  Byte Data[MAX_MEM];


  void Initialise(){
    for (u32 i = 0; i < MAX_MEM; i++){
      Data[i] = 0;
    }
  }
};

struct CPU {


  Word PC; //program counter
  Word SP; // stack pointer

  Byte A, X, Y; // registers 
  
  Byte C : 1;  // status flag
  Byte Z : 1;  // status flag
  Byte I : 1;  // status flag
  Byte D : 1;  // status flag
  Byte B : 1;  // status flag
  Byte V : 1;  // status flag
  Byte N : 1;  // status flag

  void Reset(Mem& memory){
    PC = 0xFFFC;
    SP = 0x0100;
    C = Z = I = B = V = N = D = 0;
    A = X = Y = 0;
    memory.Initialise();
    

  }

};

int main(){
  Mem mem;
  CPU cpu;
  cpu.Reset(mem);
  return 0;
}
