#pragma once
#include "game_sprite.hpp"

class UserControl : public GameSprite
{
public:
  UserControl(const Vector2 &position, const std::string &imagePath, int radius, float scale, int speed);
  void moveUp();
  void moveDown();
  void moveLeft();
  void moveRight();
  void setSpeed(int value);

private:
  int _speed;
  int _getSpeed() { return _speed; };
};
