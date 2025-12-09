#include "soulmender.hpp"

Soulmender::Soulmender(const Vector2 &position, const std::string &imagePath, int radius,
                       float scale, int hp, int maxHp, int speed,
                       int xp, int damage) : Enemy(position, imagePath, radius, scale, hp, maxHp, speed, xp), _restoreHP(damage) {}

void Soulmender::heal(std::vector<std::unique_ptr<DamagerEnemy>> enemys)
{
  // Implementation of healing logic
}
void Soulmender::move(Cossack cossack)
{
  // Implementation of movement logic
}

bool Soulmender::_isHeal(DamagerEnemy &enemy)
{
  // Implementation of healing condition check
}