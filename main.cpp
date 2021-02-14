#include <iostream> 
#include <vector>
#include "setup/player.cpp"
#include "setup/enemy.cpp"

using std::cout;
using std::cin;

//global variables-----------------------------------
Player player;
std::vector<Enemy>enemies;
bool gameOver = false;
//---------------------------------------------------

int spawnEnemies()
{
    int area = MAX_X * MAX_Y;
    return 10;
}

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

            for(size_t k = 0; k < enemies.size(); k++) //handle the enemies
            {
                if(enemies[k].x() == j && enemies[k].y() == i) {cout << "X"; break;}
                
                else if(k == (enemies.size()-1)) {cout << "-";}

            }
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
    int totalEnemies = spawnEnemies();
    for(int i = 0; i < totalEnemies; i++)
    {
        Enemy e;
        enemies.push_back(e);
        cout << e.x() << "\t" << e.y() << "\n";
    }

    //cout << enemies.size();

    while(!gameOver)
    {
        draw();
        getUserInput();
        cout << player.x() << "\t" << player.y() << "\n";
    }
}