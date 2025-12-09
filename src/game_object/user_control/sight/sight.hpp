#pragma once
#include "user_control.hpp"
#include <vector>
#include "enemy.hpp"
#include <memory>

class Sight : public UserControl
{
public:
  Sight(const Vector2 &position, const std::string &imagePath, int radius, float scale, int damage, int speed);
  std::vector<int> shot(std::vector<std::unique_ptr<Enemy>> enemys);

private:
  int _damage;
  bool _isAttackZone(Enemy &enemy);
};
