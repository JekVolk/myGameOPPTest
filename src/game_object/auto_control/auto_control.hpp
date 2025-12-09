#pragma once
#include "game_sprite.hpp"

class AutoControl : public GameSprite
{
public:
  AutoControl(const Vector2 &position, const std::string &imagePath, int radius, float scale);
  int getId() { return _id; };

private:
  const int _id;
  static int _nextId;
};
