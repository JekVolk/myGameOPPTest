#include "eternal_dusk_lord.hpp"

void EternalDuskLord::_attackExplosion(Cossack &cossack)
{
  // Implementation of explosion attack logic
}

bool EternalDuskLord::takeDamage(int value)
{
  bool died = DamagerEnemy::takeDamage(value);
  /*
  if (died)
  {
    _attackExplosion(cossack);
  }*/
  return died;
}
