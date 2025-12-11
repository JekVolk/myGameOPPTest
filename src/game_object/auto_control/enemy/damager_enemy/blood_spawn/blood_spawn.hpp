#pragma once
#include "game_object/auto_control/enemy/damager_enemy/damager_enemy.hpp"

class Bloodspawn : public DamagerEnemy
{
public:
  using DamagerEnemy::DamagerEnemy;
  void move(Cossack &cossack) override { _moveLine(cossack); };

private:
  static const EnemyType _type = BloodspawnType;
};
