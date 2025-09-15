#include "QueensGame.h"
#include <iostream>
using namespace std;

// Constructor
QueensGame::QueensGame(int size) : N(size), placed(0), board(size, vector<int>(size, 0)) {}

// Print the board
void QueensGame::printBoard() const 
{
    cout << "\n\t   ";
    for (int j = 1; j <= N; j++) cout << j << " ";
    cout << endl;
    for (int i = 0; i < N; i++) 
    {
        cout << "\t" << i + 1 << " |";
        for (int j = 0; j < N; j++)
        {
            cout << (board[i][j] ? "Q" : ".") << " ";
        }
        cout << endl;
    }
}

// Check if a queen can be placed at (row, col)
bool QueensGame::isSafe(int row, int col) const 
{
    // Row
    for (int j = 0; j < N; j++)
        if (board[row][j]) return false;

    // Column
    for (int i = 0; i < N; i++)
        if (board[i][col]) return false;

    // Diagonals
    for (int i = -N; i <= N; i++) {
        if (row + i >= 0 && row + i < N && col + i >= 0 && col + i < N)
            if (board[row + i][col + i]) return false;
        if (row + i >= 0 && row + i < N && col - i >= 0 && col - i < N)
            if (board[row + i][col - i]) return false;
    }

    return true;
}

bool QueensGame::placeQueen(int row, int col) {
    if (row < 0 || row >= N || col < 0 || col >= N) {
        cout << "\n\tInvalid position.\n";
        return false;
    }
    if (board[row][col]) {
        cout << "\n\tAlready a queen there!\n";
        return false;
    }
    if (!isSafe(row, col)) {
        cout << "\n\tThat position is under attack!\n";
        return false;
    }

    board[row][col] = 1;
    placed++;
    cout << "\n\tPlaced queen at (" << row + 1 << ", " << col + 1 << ")\n";
    return true;
}

void QueensGame::removeQueen(int row, int col) {
    if (row < 0 || row >= N || col < 0 || col >= N) {
        cout << "\n\tInvalid position.\n";
        return;
    }
    if (board[row][col]) {
        board[row][col] = 0;
        placed--;
        cout << "\n\tRemoved queen at (" << row + 1 << ", " << col + 1 << ")\n";
    }
    else {
        cout << "\n\tNo queen at (" << row + 1 << ", " << col + 1 << ")\n";
    }
}

bool QueensGame::allQueensPlaced() const 
{
    return placed == N;
}

void QueensGame::showBoard() const 
{
    printBoard();
}