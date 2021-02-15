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
bool victory = false;
int totalMoves = 0;
//---------------------------------------------------

//based on the area of the map, it will spawn the apprioate amount of enemies
void spawnEnemies()
{
    int area = MAX_X * MAX_Y;
    int totalEnemies = area / 10;
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
            if(player.x() == j && player.y() == i) 
            {
                //if(player.x() == 5 && player.y() == 5) {victory = true; gameOver = true;}
               {cout << "P"; continue;}
            } //draw the player

            for(size_t k = 0; k < enemies.size(); k++) //handle the enemies
            {
                if(deathPosition[k][axis::x] == j && deathPosition[k][axis::y] == i) {cout << "X"; break;}
                
                else if(k == (enemies.size()-1)) {cout << "-";}
            }

            if(i == EXIT_Y && j == EXIT_X) {cout << "\bE";} //the exit
        }

        cout << "\n";
    }
}

//get the user input and move the player
void getUserInput()
{
    char input;
    cout << "Move with W,A,S,D" << "\n";
    cout << "Total Moves: " << totalMoves << "\n";
    cout << "Input: ";
    cin >> input;

    if(player.checkUserInput(input)) {player.move(input);}
    else return;
}

void logic()
{
    deathPosition.clear();

    if(player.x() == EXIT_X && player.y() == EXIT_Y) {victory = true; gameOver = true;} //if the player has reached the exit

    totalMoves++;

    for(Enemy enemy : enemies)
    {
        if(player == enemy) {gameOver = true; break;} //if the player's pos and the enemy's pos equal, the player lose the game
        enemy.move(); //move the enemy
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

    draw(); //draw the board one last time

    if(victory) {printf("You have escaped the maze\n");} //if the player has escaped
    else {printf("You have died in the maze\n");} //if the player has died

    printf("Total Moves: %d\n", totalMoves); //show the score
}