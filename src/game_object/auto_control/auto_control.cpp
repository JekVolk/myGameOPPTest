#include "auto_control.hpp"

int AutoControl::_nextId = 0;

AutoControl::AutoControl(const Vector2 &position, const std::string &imagePath, int radius, float scale)
    : GameSprite(position, imagePath, radius, scale), _id(_nextId++) {}