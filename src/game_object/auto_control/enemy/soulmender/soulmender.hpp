#pragma once
#include "enemy.hpp"
#include "damager_enemy.hpp"
#include <vector>
#include <memory>

class Soulmender : Enemy
{
public:
  Soulmender(const Vector2 &position, const std::string &imagePath, int radius, float scale,
             int hp, int maxHp, int speed, int xp, int restoreHP);
  void heal(std::vector<std::unique_ptr<DamagerEnemy>> enemys);
  void move(Cossack cossack);

private:
  static const EnemyType _type = SoulmenderType;
  const int _restoreHP;
  bool _isHeal(DamagerEnemy &enemy);
};