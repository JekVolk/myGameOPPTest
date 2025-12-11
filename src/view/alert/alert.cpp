#include "alert.hpp"
#include "raylib.h"
#include <string>

void Alert::draw()
{
  switch (_mode)
  {
  case AlertModeEnum::Win:
    _open("YOU WIN! 🎉", GREEN);
    break;
  case AlertModeEnum::Defeat:
    _open("DEFEAT 💀", RED);
    break;
  default:
    break;
  }
}

void Alert::_open(const std::string &text, Color color)
{
  int screenW = GetScreenWidth();
  int screenH = GetScreenHeight();

  int fontSize = 30;
  int textWidth = MeasureText(text.c_str(), fontSize);

  DrawText(text.c_str(), (screenW - textWidth) / 2, screenH / 2 - fontSize / 2, fontSize, color);
}
