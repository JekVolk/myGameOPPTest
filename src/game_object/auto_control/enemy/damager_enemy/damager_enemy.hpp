#pragma once
#include "game_object/auto_control/enemy/enemy.hpp"

class DamagerEnemy : public Enemy
{
public:
  DamagerEnemy(const Vector2 &position, const std::string &imagePath, int radius, float scale,
               int maxHp, int speed, int xp, int damage);
  bool attack(Cossack &cossack);

protected:
  int _getDamage() { return _damage; };
  bool _attack(Cossack &cossack);

private:
  const int _damage;
};
