#pragma once
#include "raylib.h"

class Utils
{
public:
  static int getMapWidth() { return _mapWidth; };
  static int getMapHeight() { return _mapHeight; };
  static int getRandomInt(int min, int max);
  static Vector2 getRandomPosition();
  static bool chance(int chancePercent, int maxPercent);

private:
  static const int _mapWidth = 2000;
  static const int _mapHeight = 2000;
};
