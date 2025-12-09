#include "enemy_dispatcher.hpp"
#include "utils.hpp"
#include "blood_spawn.hpp"
#include "eternal_dusk_lord.hpp"
#include "night_stalker.hpp"
#include "crimson_brute.hpp"

const std::unordered_map<int, CreateEnemyInfo> EnemyDispatcher::_levelWaveMatrix = {
    {1, {3, 1, 1, 0, 1, 0}},
    {2, {4, 1, 1, 1, 1, 0}},
    {3, {5, 2, 1, 1, 1, 0}}};

std::vector<std::unique_ptr<Enemy>> EnemyDispatcher::getEnemys()
{
  std::vector<std::unique_ptr<Enemy>> allEnemies;
  for (auto &d : _damagers)
    allEnemies.push_back(std::move(d));
  for (auto &s : _soulmenders)
    allEnemies.push_back(std::move(s));
  return allEnemies;
}

void EnemyDispatcher::createEnemys(int level)
{
  const CreateEnemyInfo &info = _levelWaveMatrix.at(level);
  size_t totalEnemies = _damagers.size() + _soulmenders.size();

  if (totalEnemies <= info.countEnemy)
  {
    if (Utils::chance(info.randomEternalDuskLord, 100))
    {
      Vector2 position = {Utils::getRandomInt(100, 700), Utils::getRandomInt(100, 500)};
      _damagers.push_back(std::make_unique<EternalDuskLord>(position, "Graphics/enemy/eternal_dusk_lord.png", 40, 0.2, 70, 70, 2));
    }

    if (Utils::chance(info.randomSoulmender, 100))
    {
      Vector2 position = {Utils::getRandomInt(100, 700), Utils::getRandomInt(100, 500)};
      _soulmenders.push_back(std::make_unique<Soulmender>(position, "Graphics/enemy/soulmender.png", 40, 0.2, 30, 30, 2));
    }

    if (Utils::chance(info.randomCrimsonBrute, 100))
    {
      Vector2 position = {Utils::getRandomInt(100, 700), Utils::getRandomInt(100, 500)};
      _damagers.push_back(std::make_unique<CrimsonBrute>(position, "Graphics/enemy/crimson_brute.png", 40, 0.2, 80, 80, 1));
    }

    if (Utils::chance(info.randomNightStalker, 100))
    {
      Vector2 position = {Utils::getRandomInt(100, 700), Utils::getRandomInt(100, 500)};
      _damagers.push_back(std::make_unique<NightStalker>(position, "Graphics/enemy/night_stalker.png", 40, 0.2, 60, 60, 4));
    }

    if (Utils::chance(info.randomBloodSpawn, 100))
    {
      Vector2 position = {Utils::getRandomInt(100, 700), Utils::getRandomInt(100, 500)};
      _damagers.push_back(std::make_unique<Bloodspawn>(position, "Graphics/enemy/bloodspawn.png", 40, 0.2, 50, 50, 3));
    }
  }
}

void EnemyDispatcher::deleteEnemys(std::vector<int> ids)
{
  for (int id : ids)
  {
    for (size_t i = 0; i < _damagers.size(); ++i)
    {
      if (_damagers[i]->getId() == id)
      {
        _deleteDamagerEnemy(i);
        break;
      }
    }

    for (size_t i = 0; i < _soulmenders.size(); ++i)
    {
      if (_soulmenders[i]->getId() == id)
      {
        _deleteSoulmender(i);
        break;
      }
    }
  }
}

bool EnemyDispatcher::actionEnemy(Cossack &cossack)
{
  _moveEnemy(cossack);
  bool attacked = _attackEnemy(cossack);
  _healEnemy(cossack);
  return attacked;
}

bool EnemyDispatcher::_attackEnemy(Cossack &cossack)
{
  bool attacked = false;
  for (size_t i = 0; i < _damagers.size(); ++i)
  {
    if (_damagers[i]->attack(cossack))
      attacked = true;
  }
  return attacked;
}

void EnemyDispatcher::_healEnemy(Cossack &cossack)
{
  for (size_t i = 0; i < _soulmenders.size(); ++i)
    _soulmenders[i]->heal(cossack);
}

void EnemyDispatcher::_moveEnemy(Cossack &cossack)
{
  for (auto &d : _damagers)
    d->move(cossack);

  for (auto &s : _soulmenders)
    s->move(cossack);
}

void EnemyDispatcher::_deleteDamagerEnemy(size_t i)
{
  if (i < _damagers.size())
    _damagers.erase(_damagers.begin() + i);
}

void EnemyDispatcher::_deleteSoulmender(size_t i)
{
  if (i < _soulmenders.size())
    _soulmenders.erase(_soulmenders.begin() + i);
}