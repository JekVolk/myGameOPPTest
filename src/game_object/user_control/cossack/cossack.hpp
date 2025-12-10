#pragma once
#include "game_object/user_control/user_control.hpp"
#include "game_object/live_object/live_object.hpp"
#include "raylib.h"
#include <memory>

class Cossack : public UserControl, public LiveObject
{
public:
  Cossack(const Vector2 &position,
          const std::string &imagePath,
          int radius,
          float scale,
          int maxHp,
          int speed);

  void receivingXP(int value);

  static int getLevel() { return _level; };
  static Camera2D &getCamera() { return _camera; };
  void moveUp();
  void moveDown();
  void moveLeft();
  void moveRight();

private:
  int _xp;
  static int _level;
  static Camera2D _camera;
  static const float _smoothSpeed;
  void _upLevel();
  void _updateCamera();
};