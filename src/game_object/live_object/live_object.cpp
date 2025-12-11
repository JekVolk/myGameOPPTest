#include "live_object.hpp"

bool LiveObject::takeDamage(int value)
{
  _hp -= value;
  return _checkDead();
};

void LiveObject::treatment(int value)
{
  _hp += value;
  if (_hp > _maxHp)
  {
    _hp = _maxHp;
  }
}