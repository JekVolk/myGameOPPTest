#pragma once

enum AlertModeEnum
{
  None,
  Win,
  Defeat
};

class Alert
{
public:
  Alert() { _mode = AlertModeEnum::None; };
  void setMode(AlertModeEnum mode) { _mode = mode; };
  void draw();

private:
  AlertModeEnum _mode;
  void _open(const std::string &text, Color color);
};
