#include <client/Players/PlayerInformation.hpp>


bool PlayerData::RightHealth(PlayerData player)
{
  return ( player.health && 4 );
}

bool PlayerData::LeftHealth(PlayerData player)
{
  return ( player.health && 3 );
}

bool PlayerData::BackHealth(PlayerData player)
{
  return ( player.health && 2 );
}

bool PlayerData::FrontHealth(PlayerData player)
{
  return ( player.health && 1 );
}

