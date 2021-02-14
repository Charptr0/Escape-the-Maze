#include "enemy.h"
#include "player.h"
#include <ctime>
#include <iostream>

Enemy::Enemy()
{
    generatePosition(coordinate[axis::x], 'x');
    generatePosition(coordinate[axis::y], 'y');
}

void Enemy::generatePosition(int &position, const char &axis)
{
    if(axis == 'x') {position = randomNumberGenerator(1, (MAX_X-1));}
    else if(axis == 'y') {position = randomNumberGenerator(1, (MAX_Y-1));}
    else return;
}

int Enemy::randomNumberGenerator(int lowerBound, int upperBound)
{
    std::srand(time(NULL));
    return (rand() % upperBound) + lowerBound; 
}






