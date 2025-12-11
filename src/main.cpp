#include "raylib.h"
#include "game/game.hpp"

int main()
{
  InitWindow(0, 0, "Козак проти мороку");
  SetTargetFPS(60);

  Game game;
  game.run();
  CloseWindow();

  return 0;
}