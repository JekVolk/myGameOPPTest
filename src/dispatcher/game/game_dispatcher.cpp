#include "game_dispatcher.hpp"

GameDispatcher::GameDispatcher(EnemyDispatcher enemyDispatcher, AwardDispatcher awardDispatcher, Cossack cossack,
                               Sight sight) : _enemyDispatcher(std::move(enemyDispatcher)), _awardDispatcher(std::move(awardDispatcher)), _cossack(std::move(cossack)), _sight(std::move(sight)) {}

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
    _enemyDispatcher.deleteEnemys(_sight.shot(_enemyDispatcher.getEnemys()));
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