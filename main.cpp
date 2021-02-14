#include <iostream> 
#include <vector>
#include "setup/player.cpp"
#include "setup/enemy.cpp"
#include "setup/operators.cpp"

using std::cout;
using std::cin;

//global variables-----------------------------------
Player player;
std::vector<Enemy>enemies;
std::vector<std::vector<int>>deathPosition;
bool gameOver = false;
//---------------------------------------------------

//based on the area of the map, it will spawn the apprioate amount of enemies
void spawnEnemies()
{
    int area = MAX_X * MAX_Y;
    int totalEnemies = 10; //area / 10;
    for(int i = 0; i < totalEnemies; i++)
    {
        Enemy e;
        enemies.push_back(e);
        cout << e.x() << "\t" << e.y() << "\n";
        deathPosition.push_back({e.x(), e.y()});
    }
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
                //cout << enemies[k].x() << "\t" << enemies[k].y() << "\n";
                if(deathPosition[k][axis::x] == j && deathPosition[k][axis::y] == i) {cout << "X"; break;}
                
                else if(k == (enemies.size()-1)) {cout << "-";}
            }
        }

        cout << "\n";
    }
}

//get the user input and move the player
void getUserInput()
{
    char input;
    cout << "Input: ";
    cin >> input;

    if(player.checkUserInput(input)) {player.move(input);}
    else return;
}

void logic()
{
    deathPosition.clear();

    for(Enemy enemy : enemies)
    {
        if(player == enemy) {gameOver = true; break;}
        //cout << enemy.x() << "\t" << enemy.y() << "\n";
        enemy.move();
        cout << enemy.x() << "\t" << enemy.y() << "\n";
        deathPosition.push_back({enemy.x(), enemy.y()});
    }
}

int main()
{
    spawnEnemies();

    while(!gameOver)
    {
        draw();
        getUserInput();
        logic();
    }

    draw();
}