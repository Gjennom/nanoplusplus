#include "nano++.h"

int main(){
  const int height = 800;
  const int width = 1000;
  InitWindow(width, height, "nano++ version 0.00.0");
  SetTargetFPS(60);
  Details details = {
    width / 50,
    height / 50,
    50,
    BLACK,
    ORANGE,
    LoadFont("resources/fonts/alagard.png")
  };
  std::vector<std::string> page;
  read_file("nano++_functions.cpp", page);
  while(!WindowShouldClose()){
    display(page, 2, 0, 0, 0, 0, details);
  }CloseWindow();
  return 0;
}