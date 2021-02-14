#include "entity.h"

int Entity::x() const {return coordinate[axis::x];}
int Entity::y() const {return coordinate[axis::y];}

void Entity::setX(const int &x)
{
    coordinate[axis::x] = x;
}

void Entity::setY(const int &y)
{
    coordinate[axis::y] = y;
}

void Entity::setPosition(const int coordinate[2])
{
    this->coordinate[axis::x] = coordinate[axis::x];
    this->coordinate[axis::y] = coordinate[axis::y];
}

void Entity::setPosition(const int &x, const int &y)
{
    this->coordinate[axis::x] = x;
    this->coordinate[axis::y] = y;
}






