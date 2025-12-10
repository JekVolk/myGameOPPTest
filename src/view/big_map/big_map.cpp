#include "view/big_map/big_map.hpp"
#include "view/game_sprite/game_sprite.hpp"
#include "game_object/user_control/cossack/cossack.hpp"

BigMap::BigMap(Overlay overlay, Alert alert)
    : _overlay(std::move(overlay)), _alert(std::move(alert))
{
}

Alert BigMap::draw()
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
  for (int x = -1000; x <= 1000; x += 50)
    DrawLine(x, -1000, x, 1000, BLACK);
  for (int y = -1000; y <= 1000; y += 50)
    DrawLine(-1000, y, 1000, y, BLACK);
}
