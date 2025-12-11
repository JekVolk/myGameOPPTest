#pragma once
#include "view/overlay/overlay.hpp"
#include "view/alert/alert.hpp"

class BigMap
{
public:
  BigMap();
  void draw();
  Alert *getAlert() { return &_alert; };

private:
  Overlay _overlay;
  Alert _alert;
  void _drawSelf();
};
