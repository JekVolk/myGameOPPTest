#include "enemy_dispatcher.hpp"
#include "utils/utils.hpp"
#include "game_object/auto_control/enemy/damager_enemy/blood_spawn/blood_spawn.hpp"
#include "game_object/auto_control/enemy/damager_enemy/eternal_dusk_lord/eternal_dusk_lord.hpp"
#include "game_object/auto_control/enemy/damager_enemy/night_stalker/night_stalker.hpp"
#include "game_object/auto_control/enemy/damager_enemy/crimson_brute/crimson_brute.hpp"

const std::unordered_map<int, CreateEnemyInfo> EnemyDispatcher::_levelWaveMatrix = {
    {1, {3, 0, 90, 0, 0, 10}},
    {2, {4, 1, 1, 1, 1, 0}},
    {3, {5, 2, 1, 1, 1, 0}}};

void EnemyDispatcher::createEnemys(int level)
{
  const CreateEnemyInfo &info = _levelWaveMatrix.at(level);
  const size_t totalEnemies = _damagers.size() + _soulmenders.size();
  // position imagePath radius scale maxHp speed xp damage);
  if (totalEnemies <= static_cast<size_t>(info.countEnemy))
  {
    if (Utils::chance(info.randomEternalDuskLord, 100))
    {
      _damagers.push_back(std::make_unique<EternalDuskLord>(Utils::getRandomPosition(), "Graphics/enemy/eternal_dusk_lord.png", 40, 0.2, 70, 70, 2, 5));
    }

    if (Utils::chance(info.randomSoulmender, 100))
    {
      _soulmenders.push_back(std::make_unique<Soulmender>(Utils::getRandomPosition(), "Graphics/enemy/soulmender.png", 40, 0.2, 30, 30, 1, 5));
    }

    if (Utils::chance(info.randomCrimsonBrute, 100))
    {
      _damagers.push_back(std::make_unique<CrimsonBrute>(Utils::getRandomPosition(), "Graphics/enemy/crimson_brute.png", 40, 0.2, 80, 80, 1, 5));
    }

    if (Utils::chance(info.randomNightStalker, 100))
    {
      _damagers.push_back(std::make_unique<NightStalker>(Utils::getRandomPosition(), "Graphics/enemy/night_stalker.png", 40, 0.2, 60, 60, 4, 5));
    }

    if (Utils::chance(info.randomBloodSpawn, 100))
    {
      _damagers.push_back(std::make_unique<Bloodspawn>(Utils::getRandomPosition(), "Graphics/enemy/bloodspawn.png", 40, 0.2, 50, 50, 3, 5));
    }
  }
}

void EnemyDispatcher::deleteEnemys(const std::vector<int> &ids)
{
  auto deleteById = [](auto &container, int id)
  {
    for (size_t i = 0; i < container.size(); ++i)
    {
      if (container[i]->getId() == id)
      {
        container.erase(container.begin() + i);
        break;
      }
    }
  };

  for (int id : ids)
  {
    deleteById(_damagers, id);
    deleteById(_soulmenders, id);
  }
}

bool EnemyDispatcher::actionEnemy(Cossack &cossack)
{
  _moveEnemy(cossack);
  bool attacked = _attackEnemy(cossack);
  _healEnemy();
  return attacked;
}

bool EnemyDispatcher::_attackEnemy(Cossack &cossack)
{
  bool attacked = false;
  for (auto &d : _damagers)
    if (d->attack(cossack))
      attacked = true;
  return attacked;
}

void EnemyDispatcher::_healEnemy()
{
  for (auto &s : _soulmenders)
    s->heal(_damagers);
}

void EnemyDispatcher::_moveEnemy(Cossack &cossack)
{
  for (auto &d : _damagers)
    d->move(cossack);
  for (auto &s : _soulmenders)
    s->move(cossack);
}