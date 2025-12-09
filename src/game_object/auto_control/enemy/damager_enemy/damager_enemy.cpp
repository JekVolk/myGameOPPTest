#include "damager_enemy.hpp"

DamagerEnemy::DamagerEnemy(const Vector2 &position, const std::string &imagePath, int radius,
                           float scale, int hp, int maxHp, int speed,
                           int xp, int damage) : Enemy(position, imagePath, radius, scale, hp, maxHp, speed, xp), _damage(damage) {}

void DamagerEnemy::attack(Cossack cossack)
{
  _attack(cossack);
}
void DamagerEnemy::_attack(Cossack cossack)
{
  // Implementation of movement logic
}
