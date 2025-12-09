#pragma once
#include "award.hpp"

class CossackBoots : public Award
{
protected:
  void _activate(Cossack &cossack)
  {
    cossack.setSpeed(getValue());
  };
}
