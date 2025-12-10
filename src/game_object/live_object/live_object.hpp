#pragma once

class LiveObject
{
public:
  LiveObject(int maxHp) : _hp(maxHp), _maxHp(maxHp) {};
  bool takeDamage(int value);
  void treatment(int value);

private:
  int _hp;
  int _maxHp;
  bool _checkDead() { return _hp < 1; };
};
