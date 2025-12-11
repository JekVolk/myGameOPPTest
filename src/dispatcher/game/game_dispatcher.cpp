#include "game_dispatcher.hpp"

GameDispatcher::GameDispatcher() : _enemyDispatcher(),
                                   _awardDispatcher(),
                                   _cossack({0, 0}, "Graphics/cossack/cossack.png", 50, 0.1, 100, 50),
                                   _sight({150, 150}, "Graphics/sight/sight.png", 100, 0.2, 100, 100) {}

void GameDispatcher::keyLoop()
{
  if (IsKeyDown(KEY_W))
  {
    _cossack.moveUp();
  }
  if (IsKeyDown(KEY_S))
  {
    _cossack.moveDown();
  }

  if (IsKeyDown(KEY_A))
  {
    _cossack.moveRight();
  }

  if (IsKeyDown(KEY_D))
  {
    _cossack.moveLeft();
  }

  if (IsKeyDown(KEY_I))
  {
    _sight.moveUp();
  }
  if (IsKeyDown(KEY_K))
  {
    _sight.moveDown();
  }

  if (IsKeyDown(KEY_J))
  {
    _sight.moveRight();
  }

  if (IsKeyDown(KEY_L))
  {
    _sight.moveLeft();
  }

  if (IsKeyDown(KEY_SPACE))
  {
    std::vector<int> killedIds = _sight.shot(
        _enemyDispatcher.getDamagers(),
        _enemyDispatcher.getSoulmenders());

    _enemyDispatcher.deleteEnemys(killedIds);
  }
}

void GameDispatcher::update(Alert alert)
{
  _enemyDispatcher.createEnemys(Cossack::getLevel());

  if (_enemyDispatcher.actionEnemy(_cossack))
  {
    alert.setMode(Defeat);
  }
  _awardDispatcher.checkAwards(_cossack);

  if (Cossack::getLevel() == 20)
  {
    alert.setMode(Win);
  }
}