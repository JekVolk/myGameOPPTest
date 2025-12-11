#include "game_sprite.hpp"
#include <algorithm>

std::vector<GameSprite *> GameSprite::_sprites;

GameSprite::GameSprite(const Vector2 &position, const std::string &imagePath, int radius, float scale) : _position(position), _radius(radius)
{
  Image image = LoadImage(imagePath.c_str());
  int originalWidth = image.width;
  int originalHeight = image.height;

  int newWidth = static_cast<int>(originalWidth * scale);
  int newHeight = static_cast<int>(originalHeight * scale);

  ImageResize(&image, newWidth, newHeight);
  _texture = LoadTextureFromImage(image);
  UnloadImage(image);
  _sprites.push_back(this);
}

GameSprite::~GameSprite()
{
  auto it = std::find(_sprites.begin(), _sprites.end(), this);
  if (it != _sprites.end())
  {
    _sprites.erase(it);
  }
  UnloadTexture(_texture);
}

void GameSprite::draw()
{
  DrawTextureV(_texture, _position, WHITE);
}

void GameSprite::drawAll()
{
  for (auto it = _sprites.rbegin(); it != _sprites.rend(); ++it)
  {
    (*it)->draw();
  }
}