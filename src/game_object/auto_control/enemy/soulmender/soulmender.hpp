#pragma once
#include "game_object/auto_control/enemy/enemy.hpp"
#include "game_object/auto_control/enemy/damager_enemy/damager_enemy.hpp"
#include <vector>
#include <memory>

class Soulmender : public Enemy
{
public:
  Soulmender(const Vector2 &position, const std::string &imagePath, int radius, float scale,
             int maxHp, int speed, int xp, int restoreHP);
  void heal(std::vector<std::unique_ptr<DamagerEnemy>> &enemies);
  void move(Cossack &cossack) override;

private:
  static const EnemyType _type = SoulmenderType;
  const int _restoreHP;
  bool _isHeal(DamagerEnemy &enemy);
};