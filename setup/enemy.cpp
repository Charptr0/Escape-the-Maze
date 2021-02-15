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
    int prevCoord[2];
    prevCoord[axis::x] = this->coordinate[axis::x];
    prevCoord[axis::y] = this->coordinate[axis::y];

    //if 0, move in the x direction
    //if y, move in the y direction
    int move = randomNumberGenerator(0,1);

    //if 0, move -1 in the x direction
    //if 1, move +1 in the x direction
    int moveX_decider = randomNumberGenerator(0,1);

    //if 0, move -1 in the y direction
    //if 1, move +1 in the y direction
    int moveY_decider = randomNumberGenerator(0,1);

    if(move == axis::x) {moveX_decider == 0 ? coordinate[axis::x] -= 1 : coordinate[axis::x] += 1;}
    else {moveY_decider == 0 ? coordinate[axis::y] -= 1 : coordinate[axis::y] += 1;}

    //if the enemy move outside the map, it will teleport them back to their previous location
    if(this->coordinate[axis::x] < 0 || this->coordinate[axis::x] >= (MAX_X-1) || this->coordinate[axis::y] <= 0 || this->coordinate[axis::y] >= (MAX_Y-1))
    {
        coordinate[axis::x] = prevCoord[axis::x];
        coordinate[axis::y] = prevCoord[axis::y];
    }

}






