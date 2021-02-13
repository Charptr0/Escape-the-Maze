#pragma once
#include "entity.h"

class Player : public Entity
{
    private:
    const char validInputs[8] = {'w', 's', 'a', 'd', 'W', 'A', 'S', 'D'};
    
    public:
    Player();
    bool checkUserInput(const char &userInput);
    void move(const char &userInput);

    int totalMoves() const;
    

};