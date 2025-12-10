#include "game.hpp"

Game::Game(GameDispatcher gameDispatcher, BigMap bigMap) : _isRunning(true),
                                                           _gameDispatcher(std::move(gameDispatcher)),
                                                           _big_map(std::move(bigMap)) {}

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
