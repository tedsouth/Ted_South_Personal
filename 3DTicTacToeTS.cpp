//Author: Ted South
//Date: 8/20/2018

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>

using namespace std;
class TicTacToe{
	public:
		int square[30];			//Board Layout
		int player;			
		int turnNum;			//Keeps track for full board (Tie)
		int playerNum;			//Number of players (Set to two later)
		int humScore;
		int compScore;
		
		bool compOrHum[100];		//Stands for computer or human, 0=Computer, 1=Human

		TicTacToe();
		void printTurn();
		void makeBoard();
		void nextTurn();
		void humanTurn();
		void computerTurn();
		void declareWinner();
		
		bool humanPlayer();
		bool addScores();
		bool endGame();	
};

TicTacToe::TicTacToe()
{
	srand(time(0));
	
	player = (rand()%2)+1;		//Random start between human or computer
	
	turnNum = 0;
	humScore = 0;
	compScore = 0;
	compOrHum[1] = 1;			//Human is marked as 1
	compOrHum[2] = 0;			//Computer is marked as 2
	
	for (int i=0 ; i<27 ; i++)
	{
		square[i] = 0;
	}
	
}

void TicTacToe::makeBoard()		//Initializes TTT board layout
{
	
	std::cout	<< "\t     Top Board (1-9)\t    Middle Board(10-18)\t    Bottom Board(19-27)\n"
				<< "\t\t" << square[0] <<" | " << square[1] << " | " << square[2]
				<< "\t\t" << square[9] <<" | " << square[10] << " | " << square[11]
				<< "\t\t" << square[18] <<" | " << square[19] << " | " << square[20]
				<< "\n\t\t--|---|--\t\t--|---|--\t\t--|---|--\n"
				<< "\t\t" << square[3] <<" | " << square[4] << " | " << square[5]
				<< "\t\t" << square[12] <<" | " << square[13] << " | " << square[14]
				<< "\t\t" << square[21] <<" | " << square[22] << " | " << square[23]
				<< "\n\t\t--|---|--\t\t--|---|--\t\t--|---|--\n"
				<< "\t\t" << square[6] <<" | " << square[7] << " | " << square[8]
				<< "\t\t" << square[15] <<" | " << square[16] << " | " << square[17]
				<< "\t\t" << square[24] <<" | " << square[25] << " | " << square[26];
				
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
		}while (choice < 0 || choice > 26 || square[choice] !=0);		//Checks for valid entries
		
		square[choice] = player;
  
}

void TicTacToe::computerTurn()
{
	int choice;
	
	do{
		choice = (rand()%26)+1;			//Computer chooses random square
	}while(choice<0 || choice > 26 || square[choice] !=0);	//Makes sure of valid values
	
	square[choice] = player;
}

bool::TicTacToe::addScores()
{
	//Winning combinations
	int board[33][3] = {{0,1,2},	//Horizontal
						{3,4,5},
						{6,7,8},
						{9,10,11},
						{12,13,14},
						{15,16,17},
						{18,19,20},
						{21,22,23},
						{24,25,26},
						{0,3,6},	//Vertical
						{1,4,7},
						{2,5,8},
						{9,12,15},
						{10,13,16},
						{11,14,17},
						{18,21,24},
						{19,22,25},
						{20,23,26},
						{0,4,8},	//Diagonal
						{2,4,6},
						{9,13,17},
						{11,13,15},
						{18,22,26},
						{20,22,24},
						{0,9,18},		//Through Board
						{1,10,19},
						{2,11,20},
						{3,12,21},
						{4,13,22},
						{5,14,23},
						{6,15,24},
						{7,16,25},
						{8,17,26},};
						
	for(int i = 0; i < 26 ; i++)	//Check for wins
	{
		if ((square[board[i][0]] == square[board[i][1]])
			&& (square[board[i][1]] == square[board[i][2]]))
		{
				
				if(square[board[i][0]] == 1)
				{
					humScore++;
				}
				else if(square[board[i][0]] == 2)
				{
					compScore++;
				}			
		
		}
	}
}

void TicTacToe::declareWinner()
{
	if(humScore > compScore)
	{
		cout << endl << endl;
		cout << "Your score: " << humScore <<endl;
		cout << "Computer's score: " << compScore << endl;
		cout << "You won the Game!";
	}
	else if(humScore > compScore)
	{
		cout << endl << endl;
		cout << "Your score: " << humScore <<endl;
		cout << "Computer's score: " << compScore << endl;
		cout << "The computer won the game.";
	}
}

bool TicTacToe::endGame()
{
	if(turnNum == 27)
	{
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
				<< "for the square you want.\n"
				<< "\t\tTop Board\t\tMiddle Board\t\tBottom Board\n\n"
				
				<< "\t\t" << "(1)" <<" | " << "(2)" << " | " << "(3)"
				<< "\t\t" << "(10)" <<" | " << "(11)" << " | " << "(12)"
				<< "\t" << "(19)" <<" | " << "(20)" << " | " << "(21)"
				<< "\n\t\t----|-----|----\t\t-----|------|-----\t-----|------|-----\n"
				<< "\t\t" << "(4)" <<" | " << "(5)" << " | " << "(6)"
				<< "\t\t" << "(13)" <<" | " << "(14)" << " | " << "(15)"
				<< "\t" << "(22)" <<" | " << "(23)" << " | " << "(24)"
				<< "\n\t\t----|-----|----\t\t-----|------|-----\t-----|------|-----\n"
				<< "\t\t" << "(7)" <<" | " << "(8)" << " | " << "(9)"
				<< "\t\t" << "(16)" <<" | " << "(17)" << " | " << "(18)"
				<< "\t" << "(25)" <<" | " << "(26)" << " | " << "(27)\n\n"
				<< "Here is the empty board. Have Fun!" << endl << endl;
				
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
	
	}while(!game.endGame());
	
	game.addScores();
	game.declareWinner();
	
	return 0;
}
