#pragma once
#include "dispatcher/award/award_dispatcher.hpp"
#include "dispatcher/enemy/enemy_dispatcher.hpp"
#include "game_object/user_control/sight/sight.hpp"
#include "game_object/user_control/cossack/cossack.hpp"
#include "view/alert/alert.hpp"

class GameDispatcher
{
public:
  GameDispatcher(Alert *alert);
  void keyLoop();
  void update();

private:
  EnemyDispatcher _enemyDispatcher;
  AwardDispatcher _awardDispatcher;
  Cossack _cossack;
  Sight _sight;
  Alert *_alert;
};
