#pragma once
#include "enemy.hpp"
#include "award.hpp"
#include "enemy_dispatcher.hpp"
#include "soulmender.hpp"
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
  std::vector<std::unique_ptr<Enemy>> getEnemys();
  void createEnemys(int level);
  void deleteEnemys(std::vector<int> ids);
  bool actionEnemy(Cossack &cossack);

private:
  static const std::unordered_map<int, CreateEnemyInfo>
      _levelWaveMatrix;

  std::vector<std::unique_ptr<DamagerEnemy>> _damagers;
  std::vector<std::unique_ptr<Soulmender>> _soulmenders;

  bool _attackEnemy(Cossack &cossack);
  void _healEnemy(Cossack &cossack);
  void _moveEnemy(Cossack &cossack);
  void _deleteDamagerEnemy(size_t i);
  void _deleteSoulmender(size_t i);
};
