#pragma once
#include "game_object/auto_control/enemy/enemy.hpp"
#include "game_object/auto_control/award/award.hpp"
#include "game_object/auto_control/enemy/soulmender/soulmender.hpp"
#include <unordered_map>
#include <vector>
#include <memory>

struct CreateEnemyInfo
{
  int countEnemy;
  int randomSoulmender;
  int randomBloodSpawn;
  int randomEternalDuskLord;
  int randomNightStalker;
  int randomCrimsonBrute;
};

class EnemyDispatcher
{
public:
  std::vector<std::unique_ptr<DamagerEnemy>> &getDamagers() { return _damagers; };
  std::vector<std::unique_ptr<Soulmender>> &getSoulmenders() { return _soulmenders; };
  void createEnemys(int level);
  void deleteEnemys(const std::vector<int> &ids);
  bool actionEnemy(Cossack &cossack);

private:
  static const std::unordered_map<int, CreateEnemyInfo>
      _levelWaveMatrix;

  std::vector<std::unique_ptr<DamagerEnemy>> _damagers;
  std::vector<std::unique_ptr<Soulmender>> _soulmenders;

  bool _attackEnemy(Cossack &cossack);
  void _healEnemy();
  void _moveEnemy(Cossack &cossack);
  void _deleteDamagerEnemy(size_t i);
  void _deleteSoulmender(size_t i);
};
