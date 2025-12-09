#include "overlay.hpp"
#include "raylib.h"
#include <string>

void Overlay::draw(int level)
{
  DrawText("WASD to move — camera follows smoothly", 10, 10, 20, DARKGRAY);
  DrawText("Press SPACE — nothing breaks now :)", 10, 40, 20, DARKGRAY);
  DrawText(("Level: " + std::to_string(level)).c_str(), 10, 40, 20, DARKGRAY);
}
