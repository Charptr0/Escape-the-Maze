#pragma once
#include "entity.h"

class Enemy : public Entity
{
    public:
    Enemy();
    void generatePosition(int &position, const char &axis);

    int randomNumberGenerator(const int &lowerBound, int const &upperBound);

    void move();
};