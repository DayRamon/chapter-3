#include "TicTacToe.h"
#include <iostream>
using namespace std;

//initializes board and player symbols 
TicTacToe::TicTacToe() {
    player = 'X'; 
    computer = 'O'; 
    resetBoard();
}

// prints board 2d array 3x3 size is set as a const in .h
void TicTacToe::printBoard() const {
    cout << "\n";
    for (int i = 0; i < SIZE; ++i) {
        cout << string(30, ' ');  // 30 spaces indentation
        for (int j = 0; j < SIZE; ++j) {
            cout << " " << board[i][j] << " ";
            if (j < SIZE - 1) cout << "|";
        }
        cout << "\n";

        if (i < SIZE - 1) {
            cout << string(30, ' '); 
            cout << "---+---+---\n";
        }
    }
    cout << "\n";
}

//spaces set to blank 
void TicTacToe::resetBoard() {
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            board[i][j] = ' ';
}

//sets spot and returns true if spot is taken return false  
bool TicTacToe::move(int row, int col, char symbol) {
    if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
        board[row][col] = symbol;
        return true;
    }
    return false;
}

//checks rows and colum for a win 
bool TicTacToe::win(char symbol) const {
    //checks rows and colum for a win 
    for (int i = 0; i < SIZE; ++i) {
        if ((board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) ||
            (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol))
            return true;
    }
    //checks diagonal for win
    if ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) ||
        (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol))
        return true;

    return false;
}
//checks to see if all spots on board are full , if there are empty spots return as false 
bool TicTacToe::isBoardFull() const {
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            if (board[i][j] == ' ')
                return false;
    return true;
}
//computers turn / logic 
void TicTacToe::computerTurn() {

    // check to see if there is a wining move available 
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            if (board[i][j] == ' ') {
                board[i][j] = computer;
                if (win(computer)) return;
                board[i][j] = ' ';
            }
    // if move is available return move else block the players next move if it is a wining move
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            if (board[i][j] == ' ') { 
                board[i][j] = player;
                if (win(player)) {
                    board[i][j] = computer;
                    return;
                }
                board[i][j] = ' ';
            }
    // center is the preffered spot 
    if (board[1][1] == ' ') {
        board[1][1] = computer;
        return;
    }
    //pick first available spot 
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            if (board[i][j] == ' ') {
                board[i][j] = computer;
                return;
            }

    printBoard();

}

char TicTacToe::getPlayerSymbol() const {
    return player;
}

char TicTacToe::getComputerSymbol() const {
    return computer;
}
