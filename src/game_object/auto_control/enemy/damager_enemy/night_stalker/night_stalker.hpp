#pragma once
#include "damager_enemy.hpp"

class NightStalker : DamagerEnemy
{
public:
  void move(Cossack cossack) { _moveAll(cossack); };

private:
  static const EnemyType _type = NightStalkerType;
};
