#pragma once

class LiveObject
{
public:
  LiveObject(int hp, int maxHp) : _hp(hp), _maxHp(maxHp) {};
  bool takeDamage(int value);
  void treatment(int value);

private:
  int _hp;
  int _maxHp;
  bool _checkDead() { return _hp < 1; };
};
