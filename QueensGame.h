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
    //Precondition: none
    //Postcondition: Constructor
    QueensGame(int size);

    //Precondition: Takes valid input for row and col from user
    //Poscondition: Places queen or tells user if invalid
    bool placeQueen(int row, int col); 

    //Precondition: Takes user input for an existing queen 
    //Postcondition: Removes queen or tells user if invalid
    void removeQueen(int row, int col);

    //Precondition: Checks if all queens have been placed
    //Postcondition: Returns placed
    bool allQueensPlaced() const;    

    //Precondition: None
    //Postcondition: Displays board
    void showBoard() const;
};

#endif // QUEENSGAME_H
