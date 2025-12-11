#include "utils.hpp"
#include <random>

int Utils::getRandomInt(int min, int max)
{
  return min + (std::rand() % (max - min + 1));
}

Vector2 Utils::getRandomPosition()
{
  return Vector2{
      static_cast<float>(getRandomInt(-_mapWidth, _mapWidth)),
      static_cast<float>(getRandomInt(-_mapHeight, _mapHeight))};
}

bool Utils::chance(int chancePercent, int maxPercent = 100)
{
  if (chancePercent <= 0)
    return false;
  if (chancePercent >= maxPercent)
    return true;

  return getRandomInt(1, maxPercent) <= chancePercent;
}

bool Utils::IsPointInCircle(const Vector2 &center, const Vector2 &point, float radius)
{
  float dx = center.x - point.x;
  float dy = center.y - point.y;

  float distanceSquared = dx * dx + dy * dy;
  float radiusSquared = radius * radius;

  return distanceSquared <= radiusSquared;
}