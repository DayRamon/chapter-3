#ifndef QUEENSGAME_H
#define QUEENSGAME_H

#include <vector>
using namespace std;

class QueensGame {
private:
    int N;        // Board size
    int placed;
    vector<vector<int>> board;            // The board

    void printBoard() const;              // Print the board
    bool isSafe(int row, int col) const;  // Check if a move is safe

public:
    QueensGame(int size);
    bool placeQueen(int row, int col); // tries to place, returns success/fail
    void removeQueen(int row, int col);
    bool allQueensPlaced() const;      // check if done
    void showBoard() const;
};

#endif // QUEENSGAME_H
