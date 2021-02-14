#include "player.h"
#include "enemy.h"

bool operator==(const Player &player, const Enemy &enemy)
{
    if(player.x() == enemy.x() && player.y() == enemy.y()) {return true;}
    else return false;
}