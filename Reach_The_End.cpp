#include <iostream>
#include <conio.h>
using namespace std;

const int ROWS = 10;
const int COLS = 10;

char grid[ROWS][COLS] = {
    {'S', '.', '.', '.', '#', '.', '.', '.', '.', '.'},
    {'.', '#', '#', '.', '.', '#', '.', '#', '.', '.'},
    {'.', '.', '#', '.', '.', '#', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '#', '#', '.', '#', '.', '.'},
    {'.', '#', '.', '.', '.', '.', '#', '.', '.', '.'},
    {'.', '#', '#', '#', '.', '.', '#', '#', '#', '.'},
    {'.', '.', '.', '#', '.', '.', '.', 'E', '.', '.'},
    {'.', '#', '.', '.', '#', '#', '.', '#', '.', '.'},
    {'.', '.', '.', '#', '.', '.', '.', '.', '#', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}
};

void displayGrid() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }
}

void movePlayer(int &playerX, int &playerY, char direction) {
    int newX = playerX;
    int newY = playerY;

    if (direction == 'w') newX--;
    else if (direction == 's') newX++;
    else if (direction == 'a') newY--;
    else if (direction == 'd') newY++;

    if (newX >= 0 && newX < ROWS && newY >= 0 && newY < COLS && grid[newX][newY] != '#') {
        if (grid[playerX][playerY] == 'P') {
            grid[playerX][playerY] = '.'; 
        }
        playerX = newX;
        playerY = newY;

        if (grid[playerX][playerY] == 'E') {
            grid[playerX][playerY] = 'P'; 
        } else {
            grid[playerX][playerY] = 'P'; 
        }
    }
}

int main() {
    int playerX = 0, playerY = 0;
    grid[playerX][playerY] = 'P';

    char input;
    bool gameRunning = true;

    while (gameRunning) {
        displayGrid();
        cout << "Enter move (w/a/s/d) or 'q' to quit: ";

        input = _getch();
        cout << input << endl;

        if (input == 'q') {
            gameRunning = false;
        } else {
            movePlayer(playerX, playerY, input);
        }

        if (grid[playerX][playerY] == 'E') {
            displayGrid();
            cout << "Congratulations! You've reached the end!" << endl;
            gameRunning = false;
        }
    }

    return 0;
}

