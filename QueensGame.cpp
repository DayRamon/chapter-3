#include "QueensGame.h"
#include <iostream>
#include<string>
using namespace std;

// Constructor
QueensGame::QueensGame(int size) : N(size), placed(0), board(size, vector<int>(size, 0)) {}

// Print the board with ASCII borders
void QueensGame::printBoard() const
{
    cout << "\n";

    // Top border
    cout << "\t  " << char(201); // ┌
    for (int j = 0; j < N; j++)
    {
        cout << char(205) << char(205); // ──
        if (j < N - 1) cout << char(203); // ┬
    }
    cout << char(187) << "\n"; // ┐

    // Rows
    for (int i = 0; i < N; i++)
    {
        cout << "\t  " << char(186); // │
        for (int j = 0; j < N; j++)
        {
            cout << right << (board[i][j] ? "Q" : "-") << " " << char(186); // cell + │
        }
        cout << "\n";

        // Middle or bottom border
        if (i < N - 1)
        {
            cout << "\t  " << char(199); // ├
            for (int j = 0; j < N; j++)
            {
                cout << char(205) << char(205); // ──
                if (j < N - 1) cout << char(206); // ┼
            }
            cout << char(185) << "\n"; // ┤
        }
        else
        {
            cout << "\t  " << char(200); // └
            for (int j = 0; j < N; j++)
            {
                cout << char(205) << char(205); // ──
                if (j < N - 1) cout << char(202); // ┴
            }
            cout << char(188) << "\n"; // ┘
        }
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
