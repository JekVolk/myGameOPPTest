#include "cossack.hpp"
#include <raymath.h>

int Cossack::_level = 1;
Camera2D Cossack::_camera = {};
const float Cossack::_smoothSpeed = 5.0f;

Cossack::Cossack(const Vector2 &position,
                 const std::string &imagePath,
                 int radius,
                 float scale,
                 int maxHp,
                 int speed) : LiveObject(maxHp),
                              UserControl(position, imagePath, radius, scale, speed)
{
  _xp = 0;

  // Ініціалізація камери
  _camera.target = getPosition();
  _camera.offset = {GetScreenWidth() / 2, GetScreenHeight() / 2};
  _camera.zoom = 1.0f;
}

void Cossack::_updateCamera()
{
  float dt = GetFrameTime();
  _camera.target = Vector2Lerp(_camera.target, getPosition(), _smoothSpeed * dt);
}

void Cossack::receivingXP(int value)
{
  _xp += value;
  _upLevel();
}

void Cossack::_upLevel()
{
  const int xpForNextLevel = 100 * (_level + 1);
  if (_xp >= xpForNextLevel)
  {
    _level++;
    _xp -= xpForNextLevel;
    // Можна додати додаткову логіку при підвищенні рівня, наприклад, збільшення характеристик
  }
}

void Cossack::moveUp()
{
  UserControl::moveUp();
  _updateCamera();
}
void Cossack::moveDown()
{
  UserControl::moveDown();
  _updateCamera();
}
void Cossack::moveLeft()
{
  UserControl::moveLeft();
  _updateCamera();
}
void Cossack::moveRight()
{
  UserControl::moveRight();
  _updateCamera();
}