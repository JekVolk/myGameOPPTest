#include "sight.hpp"
#include "utils/utils.hpp"

Sight::Sight(const Vector2 &position, const std::string &imagePath, int radius, float scale, int damage, int speed) : UserControl(position, imagePath, radius, scale, speed), _damage(damage)
{
}

std::vector<int> Sight::shot(std::vector<std::unique_ptr<DamagerEnemy>> &damagers, std::vector<std::unique_ptr<Soulmender>> &soulmenders)
{
  std::vector<int> hits;

  for (auto &enemy : damagers)
  {
    if (_isAttackZone(*enemy))
    {
      if (enemy->takeDamage(_damage))
      {
        hits.push_back(enemy->getId());
      }
    }
  }

  for (auto &enemy : soulmenders)
  {
    if (_isAttackZone(*enemy))
    {
      if (enemy->takeDamage(_damage))
      {
        hits.push_back(enemy->getId());
      }
    }
  }

  return hits;
}

bool Sight::_isAttackZone(Enemy &enemy)
{
  return Utils::IsPointInCircle(getPosition(), enemy.getPosition(), _getRadius());
  ;
}
