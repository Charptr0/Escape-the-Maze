#pragma once
#include "Entity.h"
#include <ctime>

class Enemy : public Entity
{
    public:
    Enemy();
    void generateRandomPosition();
    void setX(int x);
    void setY(int y);
    
};