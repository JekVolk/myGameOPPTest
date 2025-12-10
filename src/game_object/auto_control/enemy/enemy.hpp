#pragma once
#include "game_object/auto_control/auto_control.hpp"
#include "game_object/live_object/live_object.hpp"
#include "game_object/user_control/cossack/cossack.hpp"

enum EnemyType
{
  SoulmenderType,
  CrimsonBruteType,
  EternalDuskLordType,
  BloodspawnType,
  NightStalkerType
};

class Enemy : public AutoControl, public LiveObject
{
public:
  Enemy(const Vector2 &position, const std::string &imagePath, int radius, float scale,
        int maxHp, int speed, int xp);
  static const EnemyType getType() { return _type; };
  virtual void move(Cossack &cossack) = 0;

protected:
  bool _isZoneCossack(Cossack &cossack);
  void _moveAll(Cossack &cossack);
  void _moveLine(Cossack &cossack);

private:
  static const EnemyType _type;
  const int _xp;
  int _speed;
  int _getSpeed() { return _speed; };
};
