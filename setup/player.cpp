#include "player.h"
#include "entity.h"
#include "entity.cpp"

Player::Player()
{
    coordinate[axis::x] = 0;
    coordinate[axis::y] = 1;
}

bool Player::checkUserInput(const char &userInput)
{
    for(int i = 0; i < 8; i++) {if(userInput == this->validInputs[i]) {return true;}}
    return false;
}

//move the player's position based on user input
void Player::move(const char &userInput)
{
    switch(userInput)
    {
        case 'w':
            this->coordinate[axis::y] -= 1;
            break;

        case 'W':
            this->coordinate[axis::y] -= 1;
            break;

        case 'a':
            this->coordinate[axis::x] -= 1;
            break;

        case 'A':
            this->coordinate[axis::x] -= 1;
            break;

        case 's':
            this->coordinate[axis::y] += 1;
            break;

        case 'S':
            this->coordinate[axis::y] += 1;
            break;

        case 'd':
            this->coordinate[axis::x] += 1;
            break;

        case 'D':
            this->coordinate[axis::x] += 1;
            break;

        default:
            break;
    }
}




