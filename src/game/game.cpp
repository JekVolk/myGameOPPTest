#include "game.hpp"

Game::Game() : _isRunning(true), _big_map(), _gameDispatcher(_big_map.getAlert()) {}

void Game::run()
{
  _isRunning = true;
  while (_isRunning && !WindowShouldClose())
  {
    {
      _big_map.draw();
      _gameDispatcher.keyLoop();
      _gameDispatcher.update();
    }
  }
  _isRunning = false;
}

void Game::stop()
{
  _isRunning = false;
}
