#include "award.hpp"

Award::Award(const Vector2 &position, const std::string &imagePath, int radius, float scale, int value)
    : AutoControl(position, imagePath, radius, scale), _value(value) {}

Award::~Award() {}

bool Award::activate(Cossack &cossack)
{
  if (_isEntersZone(cossack))
  {
    _activate(cossack);
    return true;
  }
  return false;
}

bool Award::_isEntersZone(Cossack &cossack)
{
  // const int cosPos = cossack.getPosition();
  //  TODO:
  return false;
}