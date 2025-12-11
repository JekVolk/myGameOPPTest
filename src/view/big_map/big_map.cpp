#include "view/big_map/big_map.hpp"
#include "view/game_sprite/game_sprite.hpp"
#include "game_object/user_control/cossack/cossack.hpp"
#include "utils/utils.hpp"

BigMap::BigMap() : _overlay(), _alert() {}

void BigMap::draw()
{
  ClearBackground(GREEN);
  BeginDrawing();

  BeginMode2D(Cossack::getCamera());
  _drawSelf();

  GameSprite::drawAll();

  EndMode2D();

  _overlay.draw(Cossack::getLevel());
  _alert.draw();

  EndDrawing();
  return _alert;
}

void BigMap::_drawSelf()
{
  for (int x = -Utils::getMapWidth(); x <= Utils::getMapWidth(); x += 50)
  {
    DrawLine(x, -Utils::getMapHeight(), x, Utils::getMapHeight(), BLACK);
  }
  for (int y = -Utils::getMapHeight(); y <= Utils::getMapHeight(); y += 50)
  {
    DrawLine(-Utils::getMapWidth(), y, Utils::getMapWidth(), y, BLACK);
  }
}
