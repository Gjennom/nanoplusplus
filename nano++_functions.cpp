#include "nano++.h"

// reads text from file, and stores as a vector of strings
void read_file(std::string file_name, std::vector<std::string>& result){
  ifstream in_file(file_name);
  std::String line;
  while(std::getline(in_file, line)){
    result.push_back(line);
  }
}

void write_file(std::string destination, std::vector<std::string>& content){
  ofstream out_file(destination);
  if(out_file.is_open()){
    for(string line : content){
      out_file << line << '\n';
    }
  }else{
    std::cout << "File write failed" << std::endl;
  }
}

// checks keyboard to see which keys are held down, shift sensitive
// returns '\0' as default case 
char get_kb_input(void){
  bool shift = IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT);
  switch (true) {
    case IsKeyPressed(KEY_ZERO): return shift ? ')' : '0';
    case IsKeyPressed(KEY_ONE): return shift ? '!' : '1';
    case IsKeyPressed(KEY_TWO): return shift ? '@' : '2';
    case IsKeyPressed(KEY_THREE): return shift ? '#' : '3';
    case IsKeyPressed(KEY_FOUR): return shift ? '$' : '4';
    case IsKeyPressed(KEY_FIVE): return shift ? '%' : '5';
    case IsKeyPressed(KEY_SIX): return shift ? '^' : '6';
    case IsKeyPressed(KEY_SEVEN): return shift ? '&' : '7';
    case IsKeyPressed(KEY_EIGHT): return shift ? '*' : '8';
    case IsKeyPressed(KEY_NINE): return shift ? '(' : '9';
    case IsKeyPressed(KEY_A): return shift ? 'A' : 'a';
    case IsKeyPressed(KEY_B): return shift ? 'B' : 'b';
    case IsKeyPressed(KEY_C): return shift ? 'C' : 'c';
    case IsKeyPressed(KEY_D): return shift ? 'D' : 'd';
    case IsKeyPressed(KEY_E): return shift ? 'E' : 'e';
    case IsKeyPressed(KEY_F): return shift ? 'F' : 'f';
    case IsKeyPressed(KEY_G): return shift ? 'G' : 'g';
    case IsKeyPressed(KEY_H): return shift ? 'H' : 'h';
    case IsKeyPressed(KEY_I): return shift ? 'I' : 'i';
    case IsKeyPressed(KEY_J): return shift ? 'J' : 'j';
    case IsKeyPressed(KEY_K): return shift ? 'K' : 'k';
    case IsKeyPressed(KEY_L): return shift ? 'L' : 'l';
    case IsKeyPressed(KEY_M): return shift ? 'M' : 'm';
    case IsKeyPressed(KEY_N): return shift ? 'N' : 'n';
    case IsKeyPressed(KEY_O): return shift ? 'O' : 'o';
    case IsKeyPressed(KEY_P): return shift ? 'P' : 'p';
    case IsKeyPressed(KEY_Q): return shift ? 'Q' : 'q';
    case IsKeyPressed(KEY_R): return shift ? 'R' : 'r';
    case IsKeyPressed(KEY_S): return shift ? 'S' : 's';
    case IsKeyPressed(KEY_T): return shift ? 'T' : 't';
    case IsKeyPressed(KEY_U): return shift ? 'U' : 'u';
    case IsKeyPressed(KEY_V): return shift ? 'V' : 'v';
    case IsKeyPressed(KEY_W): return shift ? 'W' : 'w';
    case IsKeyPressed(KEY_X): return shift ? 'X' : 'x';
    case IsKeyPressed(KEY_Y): return shift ? 'Y' : 'y';
    case IsKeyPressed(KEY_Z): return shift ? 'Z' : 'z';
    case IsKeyPressed(KEY_LEFT_BRACKET): return shift ? '{' : '[';
    case IsKeyPressed(KEY_RIGHT_BRACKET): return shift ? '}' : ']';
    case IsKeyPressed(KEY_BACKSLASH): return shift ? '|' : '\\';
    case IsKeyPressed(KEY_SEMICOLON): return shift ? ':' : ';';
    case IsKeyPressed(KEY_APOSTROPHE): return shift ? '"' : '\'';
    case IsKeyPressed(KEY_COMMA): return shift ? '<' : ',';
    case IsKeyPressed(KEY_PERIOD): return shift ? '>' : '.';
    case IsKeyPressed(KEY_SLASH): return shift ? '?' : '/';
  }return('\0');
}