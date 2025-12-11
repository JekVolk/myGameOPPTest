#include "user_control.hpp"

UserControl::UserControl(const Vector2 &position, const std::string &imagePath, int radius, float scale, int speed)
    : GameSprite(position, imagePath, radius, scale), _speed(speed) {}

void UserControl::moveUp()
{
  float dt = GetFrameTime();
  _setPosition({getPosition().x, getPosition().y - (_getSpeed() * dt)});
  // TODO: Додати перевірку меж ігрового світу         playerPos.x = Clamp(playerPos.x, -1000, mapWidth);   playerPos.y = Clamp(playerPos.y, -1000, mapHeight);
}

void UserControl::moveDown()
{
  float dt = GetFrameTime();
  _setPosition({getPosition().x, getPosition().y + (_getSpeed() * dt)});
}

void UserControl::moveLeft()
{
  float dt = GetFrameTime();
  _setPosition({getPosition().x + (_getSpeed() * dt), getPosition().y});
}

void UserControl::moveRight()
{
  float dt = GetFrameTime();
  _setPosition({getPosition().x - (_getSpeed() * dt), getPosition().y});
}

void UserControl::setSpeed(int value)
{
  if (_speed < value)
  {
    _speed = value;
  }
}