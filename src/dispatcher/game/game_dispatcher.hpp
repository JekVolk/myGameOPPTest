#pragma once
#include "award_dispatcher.hpp"
#include "enemy_dispatcher.hpp"
#include "sight.hpp"
#include "cossack.hpp"
#include "alert.hpp"

class GameDispatcher
{
public:
  GameDispatcher(EnemyDispatcher enemyDispatcher, AwardDispatcher awardDispatcher, Cossack cossack, Sight sight);
  void keyLoop();
  void update(Alert alert);

private:
  EnemyDispatcher _enemyDispatcher;
  AwardDispatcher _awardDispatcher;
  Cossack _cossack;
  Sight _sight;
};
