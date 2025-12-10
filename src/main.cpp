#include "game/game.hpp"
#include "dispatcher/game/game_dispatcher.hpp"
#include "dispatcher/enemy/enemy_dispatcher.hpp"
#include "dispatcher/award/award_dispatcher.hpp"
#include "game_object/user_control/sight/sight.hpp"
#include "game_object/user_control/cossack/cossack.hpp"
#include "view/big_map/big_map.hpp"
#include "view/overlay/overlay.hpp"
#include "view/alert/alert.hpp"

int main()
{
  InitWindow(800, 600, "Козак проти мороку");
  SetTargetFPS(60);
  EnemyDispatcher enemyDispatcher;
  AwardDispatcher awardDispatcher;
  Cossack cossack({0, 0}, "Graphics/cossack/cossack.png", 20, 0.1, 100, 50);
  Sight sight({200, 200}, "Graphics/sight/sight.png", 20, 0.1, 100, 5);

  GameDispatcher gameDispatcher(std::move(enemyDispatcher), std::move(awardDispatcher), std::move(cossack), std::move(sight));

  Alert alert;
  Overlay overlay;
  BigMap bigMap(std::move(overlay), std::move(alert));

  Game game(std::move(gameDispatcher), std::move(bigMap));

  game.run();
  CloseWindow();

  return 0;
}