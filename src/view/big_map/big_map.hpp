#pragma once
#include "overlay.hpp"
#include "alert.hpp"

class BigMap
{
public:
  BigMap(Overlay overlay, Alert alert);
  Alert draw();

private:
  Overlay _overlay;
  Alert _alert;
  void _drawSelf();
};
