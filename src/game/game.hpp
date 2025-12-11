#pragma once
#include "dispatcher/game/game_dispatcher.hpp"
#include "view/big_map/big_map.hpp"

class Game
{
public:
  Game();
  void run();
  void stop();

private:
  bool _isRunning;
  GameDispatcher _gameDispatcher;
  BigMap _big_map;
};
