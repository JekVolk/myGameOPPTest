#include "damager_enemy.hpp"

DamagerEnemy::DamagerEnemy(const Vector2 &position, const std::string &imagePath, int radius,
                           float scale, int maxHp, int speed,
                           int xp, int damage) : Enemy(position, imagePath, radius, scale, maxHp, speed, xp), _damage(damage) {}

bool DamagerEnemy::attack(Cossack &cossack)
{
  return _attack(cossack);
}
bool DamagerEnemy::_attack(Cossack &cossack)
{
  // Implementation of movement logic
  return false;
}
