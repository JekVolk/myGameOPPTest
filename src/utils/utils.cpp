#include "utils.hpp"
#include <random>

int Utils::getRandomInt(int min, int max)
{
  return min + (std::rand() % (max - min + 1));
}

bool Utils::chance(int chancePercent, int maxPercent = 100)
{
  if (chancePercent <= 0)
    return false;
  if (chancePercent >= maxPercent)
    return true;

  return getRandomInt(1, maxPercent) <= chancePercent;
}
