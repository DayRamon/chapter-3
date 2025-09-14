#pragma once
#include <iostream>

class TicTacToe {
private:
    static const int SIZE = 3;
    char board[SIZE][SIZE]; // 2d array 
    char player; 
    char computer;

public:

    // pre condtion : none 
    // post condition : initializes board and players symobls 
    TicTacToe();

    // pre condition: none
    // post condition : prints board 
    void printBoard() const;

    // pre condition : 0 <= row < SIZE, 0 <= col < SIZE
    // post condtion : returns true if spot is empty move was placed, else false 
    bool move(int row, int col, char symbol);

    // pre condition : none 
    // post condition : places computers turn based on,
    // if winning move is available of not if player has a wining move availble block, 
    // else computer chooses first available  
    void computerTurn();

    // pre condition: symbol is 'x' or 'o' 
    // post condition: returns true if player has won else false 
    bool win(char symbol) const;

    // pre condition : none 
    // post condition : returns true is all spots are full, else false  
    bool isBoardFull() const;
    
    // pre condition : none 
    // post condition : back to blank spaces 
    void resetBoard();

    // pre condition : none 
    // post condition : returns 'x' , for player 
    char getPlayerSymbol() const;

    // pre condition : none 
   // post condition : returns 'o' , for computer 
    char getComputerSymbol() const;
};
