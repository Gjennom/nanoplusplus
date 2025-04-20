#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "raylib.h"

/*
  open files are stored as a vector of strings, each containing a line of text.
*/

struct Details{
  int num_cols;
  int num_rows;
  int text_size;
  Color background;
  Color text_default;
  Font font;
};

void read_file(std::string file_name, std::vector<std::string>& result);

void write_file(std::string destination, std::vector<std::string>& content);

void display(std::vector<std::string> page, float scale, int col_top, int row_top, int cursor_x, int cursor_y, Details details);

char get_kb_input(void);

