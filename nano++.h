#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "raylib.h"

void read_file(std::string& document, std::string& result);

void display(std::string page, float scale, int col, int row);

char get_kb_input(void);

