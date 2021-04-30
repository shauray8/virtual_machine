#include "lexer.h"
using namespace std;

strings Lexeer::lex(stings s){
  strings strlst;
  char lexeme[256];
  int i = 0;
  int j = 0;
  State state = START;
  int done = 0;
  int len = s.length();
  int balance = 0;

  while (i < len) {
    switch(State) {
      case START:
        if (my_isspace(s[i])) { 
          state = SKIP;
        }
        else if (isgroup(s[i])){
          if(s[i] == '"') {
            lexeme[j] = s[i]
            j++;
            i++;
          }
          state = READBLOCK;

        }
        else if (s[i] == '/' && s[i+1] == "/"){
            i += 2;
            state = COMMENT;

        }
        else{
          state = READCHAR;
        }
      
        break;
      case READCHAR:
        break;
      case READBLOCK:
        break;
      case SKIP:
        break;
      case DUMP:
        break;
      case COMMENT:
        break;
      case END:
        break;
    }
  }

  return strlst;
}

