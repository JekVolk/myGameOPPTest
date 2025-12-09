#pragma once
#include "enemy.hpp"
#include "award.hpp"
#include <unordered_map>
#include <vector>
#include <memory>

struct CreateAwardInfo
{
  int minXP;
  int maxXP;
  int minHP;
  int maxHP;
  int minSpeed;
  int maxSpeed;
  int hpRandom;
  int speedRandom;
};

class AwardDispatcher
{
public:
  void createAward(EnemyType type, const Vector2 &position);
  void checkAwards(Cossack &cossack);

private:
  static const std::unordered_map<EnemyType, CreateAwardInfo> _awardMatrix;
  std::vector<std::unique_ptr<Award>> _awards;
};
