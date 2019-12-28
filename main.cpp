#include <iostream>
#include "ticTacToe.hpp"

int main(int argc, char** argv){

	TicTacToe game;
	int gameFinished = 0;
	while (gameFinished == 0){
		gameFinished = gameFinished + game.playerTurn();
	}
	printf("Thanks for playing!\n");
    return 0;
}
