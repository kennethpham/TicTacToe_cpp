#include "ticTacToe.hpp"

TicTacToe::TicTacToe(){
    counter = 1;
	char* ptr;
	ptr = board;
	
    for (int i = 0; i < size*size; i++){
             *(ptr + i) = ' ';
			 
    }
}

void TicTacToe::printGrid(){
    for (int i = 0; i < size*size; i++){
			if(i%3 == 0){
				printf(" %c |", board[i]);	
			}
			if(i%3 == 1){
				printf(" %c ", board[i]);
			}
			if(i%3 == 2){
				printf("| %c \n", board[i]);
				if(i != 8){
					printf("---+---+---\n");
			}
		}
    }
	printf("\n");
}

int TicTacToe::playerTurn(){
	printf("Round %d\n\n",counter++);
	printf("Current Grid:\n\n");
	printGrid();
	
    for (int i = 0; i < size*size; i++){
			if(i%3 == 0){
				printf(" %d |", i+1);	
			}
			if(i%3 == 1){
				printf(" %d ", i+1);
			}
			if(i%3 == 2){
				printf("| %d \n", i+1);
				if(i != 8){
					printf("---+---+---\n");
			}
		}
    }
	char userInput = ' ';
	std::string buffer;
	while((userInput < 49 || userInput > 57)){
		
		printf("\nEnter a number(1-9) on the board to put your 'X'.\n");
		std::getline(std::cin, buffer);
		if (buffer.length() == 1){
			if(board[std::stoi(buffer)-1] == ' '){
				userInput = buffer[0];
			}
		}

	}
	board[std::stoi(buffer)-1] = 'X';
	int result = 0;
	result += winChecker();
	if(result == 1){
		printf("\nFinal Grid:\n");
		printGrid();
		return 1;
	}
	srand((int)time(0));
	int opponentChoice = rand() % 9;
	while(board[opponentChoice] != ' '){
		opponentChoice = rand() % 9;
	}
	board[opponentChoice] = 'O';
	printGrid();
	result += winChecker();
	if(result == 1){
		printf("\nFinal Grid:\n");
		printGrid();
		return 1;
	}
	
	return 0;
}

int TicTacToe::winChecker(){
// Return: 1 = win
// 		   0 = lose

	// Row checker
	for (int i = 0; i < 7; i=i+3){
		if(board[i] == board[i+1] && board[i+1] == board[i+2]
		 && board[i] != ' '){
			if (board[i] == 'X'){
				printf("You won! :)\n");
				return 1;
			}
			else{
				printf("You lost! :(\n");
				return 1;			
			}
		}
	}

	// Column checker
	for (int i = 0; i < 3; i++){
		if(board[i] == board[i+3] && board[i+3] == board[i+6]
		 && board[i] != ' '){
			if (board[i] == 'X'){
				printf("You won! :)\n");
				return 1;
			}
			else{
				printf("You lost! :(\n");
				return 1;			
			}
		}
	}		
	
	// Diagonal Checker
	for(int i = 0; i < 3; i=i+2)
	if(board[i] == board[4] && board[4] == board[8-i]
	&& board[i] != ' '){
		if (board[i] == 'X'){
			printf("You won! :)\n");
			return 1;
		}
		else{
			printf("You lost! :(\n");
			return 1;			
		}
	}	

	return 0;
}

TicTacToe::~TicTacToe(){
	
}
