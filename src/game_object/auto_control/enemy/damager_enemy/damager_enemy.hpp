#pragma once
#include "enemy.hpp"

class DamagerEnemy : Enemy
{
public:
  DamagerEnemy(const Vector2 &position, const std::string &imagePath, int radius, float scale,
               int hp, int maxHp, int speed, int xp, int damage);
  void attack(Cossack cossack) {};

protected:
  int _getDamage() { return _damage; };
  void _attack(Cossack cossack) {};

private:
  const int _damage;
};
