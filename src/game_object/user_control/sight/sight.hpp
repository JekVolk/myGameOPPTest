#pragma once
#include "game_object/user_control/user_control.hpp"
#include <vector>
#include "game_object/auto_control/enemy/damager_enemy/damager_enemy.hpp"
#include "game_object/auto_control/enemy/soulmender/soulmender.hpp"
#include <memory>

class Sight : public UserControl
{
public:
  Sight(const Vector2 &position, const std::string &imagePath, int radius, float scale, int damage, int speed);
  std::vector<int> shot(std::vector<std::unique_ptr<DamagerEnemy>> &damagers, std::vector<std::unique_ptr<Soulmender>> &soulmenders);

private:
  int _damage;
  bool _isAttackZone(Enemy &enemy);
};
