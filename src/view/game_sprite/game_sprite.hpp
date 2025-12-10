#pragma once
#include <vector>
#include <string>
#include <raylib.h>

class GameSprite
{
public:
  GameSprite(const Vector2 &position, const std::string &imagePath, int radius, float scale);
  virtual ~GameSprite();
  void draw();
  Vector2 getPosition() { return _position; };

  static void drawAll();

protected:
  void _setPosition(const Vector2 &position) { _position = position; };
  int _getRadius() { return _radius; };

private:
  Texture2D _texture;
  Vector2 _position;
  static std::vector<GameSprite *> _sprites;
  const int _radius;
};
