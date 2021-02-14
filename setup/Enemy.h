#pragma once
#include "Entity.h"

enum PositionX
{
    left = 0, right = 1
};

enum PositionY
{
    up = 1, down = 1
};


class Enemy : public Entity
{
    public:
    Enemy();
    void generatePosition(int &position, const char &axis);

    int randomNumberGenerator(int lowerBound, int upperBound);

    void move();
};