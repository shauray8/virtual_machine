#include <iostream>
#include <fstream>
#include "hexer.h"

typedef uint32_t i32;

using namespace std;

//functions
vector<i32> compileToInstructions(strings s);
bool isInteger(string s);
bool isPrimitive(string s);
i32 mapToNumber(string s);

int main(int argc, char *argv[]){
  //cheack for input errors
  if (argc != 2){
    cout << "Usage" << argv[0] << "<sasm-filename" << "\n";
    exit(1);
  }
  // read the input file

  ifstream infile;
  infile.open(argv[1]);
  if (!infile.is_open()) {
    cout << "Error: could not open (" << argv[1] << ")" << "\n";
    exit(1);
  }
  string line;
  string contents;
  while (getline(infile, line)) {
    contents += line + "\n";

  }
  infile.close();

  //parse file
  Lexer lexer;
  string lexemes = lexer.lex(contents);

  //compile to bin
  vector<i32> instructions = compileToTheInstructions(lexems);

  //write to bin
  ofstring ofile;
  ofile.open("out.bin", ios::binary);
  for (i32 i = 0; i < instruction.size(); i++){
    ofile.write(reinterpret_cast<char *>(&instruction[i]), sizeof(i32));

  }
  ofile.close()
  return 0;

}

vector<i32> compileToInstructions(string s){
  vector<i32> instructions;
  for(i32 i = 0; i < s.size(); i++){
    if (isInteger(s[i])){
      instructions.push_back(stoi(s[i]));

    }
    else{
      i32 instructions = mapToNumber(s[i]);
      if (instruction != -1){
        instructions.puhs_back(instruction);

      }
      else{
        cout << "Error: Invalid Instruction: " << s[i] << "\n";

      }
    }
  }
  return instructions;
}

bool isInteger(string s){
  for (i32 i = 0; i < s.length(); i++){
    if(!isdigit(s[i])){
      return false;
    }
  }
  return true;
  
}

i32 mapToNumber(string s){
  if (s == "+"){
   return 0x40000001;

 }
  else if (s == "-"){
   return 0x40000002;

 }
  else if(s == "*"){
   return 0x40000003;
 }
  else if(s == "/"){
   return 0x40000004;
 }
 return -1; //invalid operation

}



