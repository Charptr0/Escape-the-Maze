#include <iostream> 
#include "setup/player.cpp"
#include "setup/enemy.cpp"

using std::cout;
using std::cin;

//global variables-----------------------------------
Player player;
bool gameOver = false;
//---------------------------------------------------

//draw the board, the player, and the enemies
void draw() 
{
    for(int i = 0; i < MAX_Y; i++)
    {
        cout << "*";
        for(int j = 0; j < MAX_X; j++)
        {
            if(i == 0 || i == (MAX_Y-1) || j == (MAX_X-1)) {cout << "*"; continue;} //handles the borders
            if(player.x() == j && player.y() == i) {cout << "P"; continue;} //draw the player
            else cout << "-"; //empty space
        }
        cout << "\n";
    }
}

void getUserInput()
{
    char input;
    cout << "Input: ";
    cin >> input;

    if(player.checkUserInput(input)) {player.move(input);}
    else return;
}

int main()
{
    /*
    while(!gameOver)
    {
        draw();
        getUserInput();
        cout << player.x() << "\t" << player.y() << "\n";
    }
    */
   
}