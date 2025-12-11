#include "game.hpp"

Game::Game() : _isRunning(true), _gameDispatcher(), _big_map() {}

void Game::run()
{
  _isRunning = true;
  while (_isRunning && !WindowShouldClose())
  {
    {
      Alert alert = _big_map.draw();
      _gameDispatcher.keyLoop();
      _gameDispatcher.update(alert);
    }
  }
  _isRunning = false;
}

void Game::stop()
{
  _isRunning = false;
}
