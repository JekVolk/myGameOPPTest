#include "award_dispatcher.hpp"
#include "utils.hpp"
#include "cossack_boots.hpp"
#include "garlic.hpp"
#include "xp_book.hpp"
#include <memory>

const std::unordered_map<EnemyType, CreateAwardInfo> AwardDispatcher::_awardMatrix = {
    {SoulmenderType, {10, 20, 50, 100, 5, 15, 10, 5}},
    {CrimsonBruteType, {10, 20, 50, 100, 5, 15, 10, 5}},
    {EternalDuskLordType, {10, 20, 50, 100, 5, 15, 10, 5}},
    {BloodspawnType, {10, 20, 50, 100, 5, 15, 10, 5}},
    {NightStalkerType, {10, 20, 50, 100, 5, 15, 10, 5}}};

void AwardDispatcher::createAward(EnemyType type, const Vector2 &position)
{
  const CreateAwardInfo &info = _awardMatrix.at(type);
  const int awardRadius = 50;
  Vector2 xp_position = {position.x + 15, position.y + 15};
  _awards.push_back(std::make_unique<XPBook>(xp_position, "Graphics/award/xp_book.png", awardRadius, 0.2, Utils::getRandomInt(info.minXP, info.maxXP)));

  if (Utils::chance(info.speedRandom, 100))
  {
    Vector2 boots_position = {position.x + 15, position.y - 15};
    _awards.push_back(std::make_unique<CossackBoots>(boots_position, "Graphics/award/cossack_boots.png", awardRadius, 0.2, Utils::getRandomInt(info.minSpeed, info.maxSpeed)));
  }
  if (Utils::chance(info.hpRandom, 100))
  {
    Vector2 garlic_position = {position.x - 15, position.y - 15};
    _awards.push_back(std::make_unique<Garlic>(garlic_position, "Graphics/award/garlic.png", awardRadius, 0.2, Utils::getRandomInt(info.minHP, info.maxHP)));
  }
}

void AwardDispatcher::checkAwards(Cossack &cossack)
{
  for (auto it = _awards.begin(); it != _awards.end();)
  {
    if ((*it)->activate(cossack))
    {
      it = _awards.erase(it);
    }
    else
    {
      ++it;
    }
  }
}
