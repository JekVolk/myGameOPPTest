#pragma once
#include "damager_enemy.hpp"

class CrimsonBrute : DamagerEnemy
{
public:
  void move(Cossack cossack) { _moveLine(cossack); };

private:
  static const EnemyType _type = CrimsonBrute;
};
