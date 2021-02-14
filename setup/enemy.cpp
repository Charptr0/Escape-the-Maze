#include "enemy.h"
#include "map_size.cpp"
#include <ctime>
#include <iostream>

bool clockStarted = false;

void startClock() {std::srand(time(NULL));}

Enemy::Enemy()
{
    if(!clockStarted) {startClock(); clockStarted = true;}

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
    return (rand() % (upperBound+1)) + lowerBound; 
}





