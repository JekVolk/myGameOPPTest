#pragma once
#include "game_object/auto_control/award/award.hpp"

class XPBook : public Award
{
public:
  using Award::Award;

protected:
  void _activate(Cossack &cossack) override { cossack.receivingXP(getValue()); };
};
