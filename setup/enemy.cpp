#include "enemy.h"
#include "map_size.cpp"
#include <ctime>
#include <iostream>

bool clockStarted = false;

void startClock() {std::srand(time(NULL));}

//constructor
Enemy::Enemy()
{
    if(!clockStarted) {startClock(); clockStarted = true;}

    generatePosition(coordinate[axis::x], 'x');
    generatePosition(coordinate[axis::y], 'y');
}

//generate a random location inside the map
void Enemy::generatePosition(int &position, const char &axis)
{
    if(axis == 'x') {position = randomNumberGenerator(1, (MAX_X-3));}
    else if(axis == 'y') {position = randomNumberGenerator(1, (MAX_Y-3));}
    else return;
}

//generate a random number based on a lowerbound and an upperbound
int Enemy::randomNumberGenerator(const int &lowerBound, const int &upperBound)
{
    return (rand() % (upperBound+1)) + lowerBound; 
}

//move the enemy
void Enemy::move()
{
    int prevCoordinate[2];
    prevCoordinate[axis::x] = this->coordinate[axis::x];
    prevCoordinate[axis::y] = this->coordinate[axis::y];

    int move = randomNumberGenerator(0,1);

    int moveX_decider = randomNumberGenerator(0,1);
    int moveY_decider = randomNumberGenerator(0,1);

    if(move == axis::x) {moveX_decider == 0 ? coordinate[axis::x] -= 1 : coordinate[axis::x] += 1;}
    else {moveY_decider == 0 ? coordinate[axis::y] -= 1 : coordinate[axis::y] += 1;}

}






