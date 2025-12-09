#include "game.hpp"
#include "game_dispatcher.hpp"
#include "enemy_dispatcher.hpp"
#include "award_dispatcher.hpp"
#include "sight.hpp"
#include "cossack.hpp"
#include "big_map.hpp"
#include "overlay.hpp"
#include "alert.hpp"

int main()
{
  EnemyDispatcher enemyDispatcher;
  AwardDispatcher awardDispatcher;
  Cossack cossack({100, 100}, "Graphics/cossack/cossack.png", 20, 0.2, 100, 100, 5);
  Sight sight({100, 100}, "Graphics/sight/sight.png", 20, 0.2, 100, 5);

  GameDispatcher gameDispatcher(std::move(enemyDispatcher), std::move(awardDispatcher), std::move(cossack), std::move(sight));

  Alert alert;
  Overlay overlay;
  BigMap bigMap(std::move(overlay), std::move(alert));

  Game game(std::move(gameDispatcher), std::move(bigMap));

  game.run();

  return 0;
}