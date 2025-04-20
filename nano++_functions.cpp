#include "nano++.h"

// reads text from file, and stores as a vector of strings
void read_file(std::string file_name, std::vector<std::string>& result){
  std::ifstream in_file(file_name);
  std::string line;
  while(std::getline(in_file, line)){
    result.push_back(line);
  }
}

void write_file(std::string destination, std::vector<std::string>& content){
  std::ofstream out_file(destination);
  if(out_file.is_open()){
    for(std::string line : content){
      out_file << line << '\n';
    }
  }else{
    std::cout << "File write failed" << std::endl;
  }
}

//displays a window of text
void display(std::vector<std::string> page, float scale, int col_top, int row_top, int cursor_x, int cursor_y, Details details){
  BeginDrawing();
  ClearBackground(details.background);
  std::string line;
  for(int i = col_top; i < row_top + details.num_rows && i < page.size(); i++){
    if(page[i].length() > col_top + details.num_cols)
      line = page[i].substr(col_top, col_top + details.num_cols);
    else
      line = page[i].substr(col_top, page[i].length());
    DrawTextEx(details.font, line.c_str(), {0, i * details.text_size}, details.text_size, 5, details.text_default);
  }EndDrawing();
}

// checks keyboard to see which keys are held down, shift sensitive
// returns '\0' as default if 
char get_kb_input(void){
  bool shift = IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT);
  if (IsKeyPressed(KEY_ZERO)) return shift ? ')' : '0';
  if (IsKeyPressed(KEY_ONE)) return shift ? '!' : '1';
  if (IsKeyPressed(KEY_TWO)) return shift ? '@' : '2';
  if (IsKeyPressed(KEY_THREE)) return shift ? '#' : '3';
  if (IsKeyPressed(KEY_FOUR)) return shift ? '$' : '4';
  if (IsKeyPressed(KEY_FIVE)) return shift ? '%' : '5';
  if (IsKeyPressed(KEY_SIX)) return shift ? '^' : '6';
  if (IsKeyPressed(KEY_SEVEN)) return shift ? '&' : '7';
  if (IsKeyPressed(KEY_EIGHT)) return shift ? '*' : '8';
  if (IsKeyPressed(KEY_NINE)) return shift ? '(' : '9';
  if (IsKeyPressed(KEY_A)) return shift ? 'A' : 'a';
  if (IsKeyPressed(KEY_B)) return shift ? 'B' : 'b';
  if (IsKeyPressed(KEY_C)) return shift ? 'C' : 'c';
  if (IsKeyPressed(KEY_D)) return shift ? 'D' : 'd';
  if (IsKeyPressed(KEY_E)) return shift ? 'E' : 'e';
  if (IsKeyPressed(KEY_F)) return shift ? 'F' : 'f';
  if (IsKeyPressed(KEY_G)) return shift ? 'G' : 'g';
  if (IsKeyPressed(KEY_H)) return shift ? 'H' : 'h';
  if (IsKeyPressed(KEY_I)) return shift ? 'I' : 'i';
  if (IsKeyPressed(KEY_J)) return shift ? 'J' : 'j';
  if (IsKeyPressed(KEY_K)) return shift ? 'K' : 'k';
  if (IsKeyPressed(KEY_L)) return shift ? 'L' : 'l';
  if (IsKeyPressed(KEY_M)) return shift ? 'M' : 'm';
  if (IsKeyPressed(KEY_N)) return shift ? 'N' : 'n';
  if (IsKeyPressed(KEY_O)) return shift ? 'O' : 'o';
  if (IsKeyPressed(KEY_P)) return shift ? 'P' : 'p';
  if (IsKeyPressed(KEY_Q)) return shift ? 'Q' : 'q';
  if (IsKeyPressed(KEY_R)) return shift ? 'R' : 'r';
  if (IsKeyPressed(KEY_S)) return shift ? 'S' : 's';
  if (IsKeyPressed(KEY_T)) return shift ? 'T' : 't';
  if (IsKeyPressed(KEY_U)) return shift ? 'U' : 'u';
  if (IsKeyPressed(KEY_V)) return shift ? 'V' : 'v';
  if (IsKeyPressed(KEY_W)) return shift ? 'W' : 'w';
  if (IsKeyPressed(KEY_X)) return shift ? 'X' : 'x';
  if (IsKeyPressed(KEY_Y)) return shift ? 'Y' : 'y';
  if (IsKeyPressed(KEY_Z)) return shift ? 'Z' : 'z';
  if (IsKeyPressed(KEY_LEFT_BRACKET)) return shift ? '{' : '[';
  if (IsKeyPressed(KEY_RIGHT_BRACKET)) return shift ? '}' : ']';
  if (IsKeyPressed(KEY_BACKSLASH)) return shift ? '|' : '\\';
  if (IsKeyPressed(KEY_SEMICOLON)) return shift ? ':' : ';';
  if (IsKeyPressed(KEY_APOSTROPHE)) return shift ? '"' : '\'';
  if (IsKeyPressed(KEY_COMMA)) return shift ? '<' : ',';
  if (IsKeyPressed(KEY_PERIOD)) return shift ? '>' : '.';
  if (IsKeyPressed(KEY_SLASH)) return shift ? '?' : '/';
  return('\0');
}