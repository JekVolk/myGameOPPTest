#pragma once
#include "game_object/auto_control/enemy/damager_enemy/damager_enemy.hpp"

class EternalDuskLord : public DamagerEnemy
{
public:
  using DamagerEnemy::DamagerEnemy;
  void move(Cossack &cossack) { _moveAll(cossack); };
  bool takeDamage(int damage);

private:
  static const EnemyType _type = EternalDuskLordType;
  static const int _explosionDamage = 30;
  static const int _explosionRadius = 5;

  void _attackExplosion(Cossack &cossack);
};
