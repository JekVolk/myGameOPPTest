#include "game.hpp"

Game::Game(GameDispatcher gameDispatcher, BigMap bigMap) : _isRunning(true),
                                                           _gameDispatcher(std::move(gameDispatcher)),
                                                           _big_map(std::move(bigMap)) {}

void Game::run()
{
  _isRunning = true;
  InitWindow(800, 600, "Козак проти мороку");

  SetTargetFPS(60);

  while (_isRunning && !WindowShouldClose())
  {
    {
      Alert alert = _big_map.draw();
      _gameDispatcher.keyLoop();
      _gameDispatcher.update(alert);
    }
    CloseWindow();
  }
  _isRunning = false;
}

void Game::stop()
{
  _isRunning = false;
}
