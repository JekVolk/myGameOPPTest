#pragma once
#include "game_object/auto_control/enemy/damager_enemy/damager_enemy.hpp"

class NightStalker : public DamagerEnemy
{
public:
  using DamagerEnemy::DamagerEnemy;
  void move(Cossack &cossack) override { _moveAll(cossack); };

private:
  static const EnemyType _type = NightStalkerType;
};
