#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
#include <cstdlib>
#include <ctime>

class TicTacToe
{
private:
    static int const size = 3;
    /* data */
    int counter;
    char board[size*size];

public:
    TicTacToe();
    ~TicTacToe();

    int playerTurn();
    void printGrid();
    int winChecker();
};



#endif
