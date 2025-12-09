#pragma once
#include "damager_enemy.hpp"

class EternalDuskLord : DamagerEnemy
{
public:
  void move(Cossack cossack) { _moveAll(cossack); };
  bool takeDamage(int damage) {};

private:
  static const EnemyType _type = EternalDuskLordType;
  static const int _explosionDamage = 30;
  static const int _explosionRadius = 5;

  void _attackExplosion(Cossack cossack);
};
