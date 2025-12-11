#pragma once
#include "game_object/auto_control/auto_control.hpp"
#include "game_object/live_object/live_object.hpp"
#include "game_object/user_control/cossack/cossack.hpp"

class Award : public AutoControl
{
public:
  Award(const Vector2 &position, const std::string &imagePath, int radius, float scale, int value);
  virtual ~Award();
  bool activate(Cossack &cossack);

protected:
  int getValue() { return _value; };
  virtual void _activate(Cossack &cossack) = 0;

private:
  const int _value;
  bool _isEntersZone(Cossack &cossack);
};
