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


/*
bool Entity::operator==(const Entity &e1, const Entity &e2)
{
    if(e1.x() == e2.x() && e1.y() == e2.y()) {return true;}
    else return false;
}
*/




