#pragma once
#include "auto_control.hpp"
#include "live_object.hpp"
#include "cossack.hpp"

class Award : public AutoControl
{
public:
  Award(const Vector2 &position, const std::string &imagePath, int radius, float scale, int value);
  bool activate(Cossack cossack);

protected:
  int getValue() { return _value; };
  virtual void _activate(Cossack cossack);

private:
  const int _value;
  bool _isEntersZone(Cossack cossack);
};
