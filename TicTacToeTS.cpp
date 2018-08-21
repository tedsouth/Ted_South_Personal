//Author: Ted South
//Date: 8/20/2018

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>

using namespace std;
class TicTacToe{
	public:
		int square[9];			//Board Layout
		int player;			
		int turnNum;			//Keeps track for full board (Tie)
		int playerNum;			//Number of players (Set to two later)
		
		bool compOrHum[10];		//Stands for computer or human, 0=Computer, 1=Human

		TicTacToe();
		void printTurn();
		void makeBoard();
		void nextTurn();
		void humanTurn();
		void computerTurn();
		
		bool humanPlayer();
		bool win();
		bool tieGame();	
};

TicTacToe::TicTacToe()
{
	srand(time(0));
	
	player = (rand()%2)+1;		//Random start between human or computer
	
	turnNum = 0;
	compOrHum[1] = 1;			//Human is marked as 1
	compOrHum[2] = 0;			//Computer is marked as 2
	
	for (int i=0 ; i<9 ; i++)
	{
		square[i] = 0;
	}
	
}

void TicTacToe::makeBoard()		//Initializes TTT board layout
{
	
	std::cout	
				<< "\t\t" << square[0] <<" | " << square[1] << " | " << square[2]
				<< "\n\t\t--|---|--\n"
				<< "\t\t" << square[3] <<" | " << square[4] << " | " << square[5]
				<< "\n\t\t--|---|--\n"
				<< "\t\t" << square[6] <<" | " << square[7] << " | " << square[8];
				
}

void TicTacToe::printTurn()
{
	std::cout << "\n\nPlayer " << player << "'s turn.\n\n";
	
}

void TicTacToe::nextTurn()		//Processes who goes next
{								//and adds to total turn counter
	turnNum++;
	
	player = player == 1? 2 : 1;
}

bool TicTacToe::humanPlayer()
{
	return compOrHum[player];
}

void TicTacToe::humanTurn()
{
	std::cout << "\nWhat square would you like to fill? \n";
	int choice;
	
	do{
		std::cin >> choice;		//Input for which square to hit
		choice--;
		}while (choice < 0 || choice > 8 || square[choice] !=0);		//Checks for valid entries
		
		square[choice] = player;
  
}

void TicTacToe::computerTurn()
{
	int choice;
	
	do{
		choice = (rand()%9)+1;			//Computer chooses random square
	}while(choice<0 || choice > 8 || square[choice] !=0);	//Makes sure of valid values
	
	square[choice] = player;
}

bool::TicTacToe::win()
{
	//Winning combinations
	int board[8][3] = {	{0,1,2},	//Horizontal
						{3,4,5},
						{6,7,8},
						{0,3,6},	//Vertical
						{1,4,7},
						{2,5,8},
						{0,4,8},	//Diagonal
						{2,4,6}};
						
	for(int i = 0; i < 8 ; i++)	//Check for wins
	{
		if ((square[board[i][0]] == square[board[i][1]])
			&& (square[board[i][1]] == square[board[i][2]])
			&& square[board[i][0]] !=0)
		{
				
				std::cout << "\n\nPlayer " << square[board[i][0]]
							<< " won the game!\n\n";
							
				return 1;
			}
	}
}

bool TicTacToe::tieGame()
{
	if(turnNum == 9)
	{
		std::cout << "\nGame has ended in a tie.\n\n";
		return 1;
	}
	else{
	
		return 0;
	}
}

int main()
{
	std:: cout 	<< "\n*********Welcome to Tic-Tac-Toe!*********\n\n"
				<< "You are player 1, computer is player 2. \"0\" means an empty square.\n\n"
				<< "Similarly, your mark will be a 1, the computer's will be a 2.\n\n"
				<< "The player who goes first is chosen at random by the game.\n"
				<< "Also, if you pick a square that is already picked, the menu will wait for an open square's number.\n"
				<< "Here is the layout of the board, and the numbers you choose\n"
				<< "for the square you want.\n\n"
				
				<< "\t\t" << "(1)" <<" | " << "(2)" << " | " << "(3)"
				<< "\n\t\t----|-----|----\n"
				<< "\t\t" << "(4)" <<" | " << "(5)" << " | " << "(6)"
				<< "\n\t\t----|-----|----\n"
				<< "\t\t" << "(7)" <<" | " << "(8)" << " | " << "(9)\n\n"
				<< "Here is the empty board. Have Fun!\n\n";
				
	TicTacToe game;
	game.makeBoard();
	
	do{
		
		game.printTurn();
		
		if(game.humanPlayer())
		{
			game.humanTurn();
		}
		else{
			game.computerTurn();
		}
			
			game.makeBoard();
			game.nextTurn();
	
	}while(!game.win() && !game.tieGame());
	
	return 0;
}
