#include "enemy.hpp"

Enemy::Enemy(const Vector2 &position, const std::string &imagePath, int radius,
             float scale, int maxHp, int speed,
             int xp) : AutoControl(position, imagePath, radius, scale),
                       LiveObject(maxHp), _xp(xp), _speed(speed) {};

bool Enemy::_isZoneCossack(Cossack &cossack)
{
  // TODO:
  return false;
}
void Enemy::_moveAll(Cossack &cossack)
{
  // TODO:
}
void Enemy::_moveLine(Cossack &cossack)
{
  // TODO:
}