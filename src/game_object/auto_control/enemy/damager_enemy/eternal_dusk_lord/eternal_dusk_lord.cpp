#include "eternal_dusk_lord.hpp"

void EternalDuskLord::_attackExplosion(Cossack cossack)
{
  pos_cos = Cossack->getPosition();
  Cossack->takeDamage(_explosionDamage);
  // Implementation of explosion attack logic
}
void EternalDuskLord::takeDamage(int value)
{
  bool died = DamagerEnemy::takeDamage(damage);
  if (died)
  {
    _attackExplosion(cossack);
  }
  return died;
}
