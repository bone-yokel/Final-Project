#include <iostream>
#include <string>
#include "Board.h"
using namespace std;

//constructor
//Bones
Board::Board()
{
	current = 'X';
	opponent = 'O';
	multiplayer = false;
	for (int x = 0; x < 9; x++) boardArray[x] = ' ';
}

//Swaps the symbols of current and opponenet players
//Bones
void Board::changeTurn()
{
	if (current == 'X')
	{
		current = 'O';
		opponent = 'X';
	}
	else
	{
		current = 'X';
		opponent = 'O';
	}
}

//prints the current state of the board
//Bones
void Board::showBoard()
{
	cout << "\t\t|\t\t|\n";
	cout << "\t" << boardArray[0] << "\t|\t" << boardArray[1] << "\t|\t" << boardArray[2] << "\t\n";
	cout << "\t\t|\t\t|\n";
	cout << "------------------------------------------------\n";
	cout << "\t\t|\t\t|\n";
	cout << "\t" << boardArray[3] << "\t|\t" << boardArray[4] << "\t|\t" << boardArray[5] << "\t\n";
	cout << "\t\t|\t\t|\n";
	cout << "------------------------------------------------\n";
	cout << "\t\t|\t\t|\n";
	cout << "\t" << boardArray[6] << "\t|\t" << boardArray[7] << "\t|\t" << boardArray[8] << "\t\n";
	cout << "\t\t|\t\t|\n";

	
}

//sets the multiplayer private member variable to input
//Bones
void Board::setMultiplayer(bool b)
{
	multiplayer = b;
}

void Board::checkGameEnd()
{

}

void Board::bestMove(char symbol)
{

}

//Determines if placing a symbol at a position will win the game
//Bones
bool Board::isWinning(char symbol, int posistion)
{
	for (int x = 0; x < 8; x++)
    {
        if (boardArray[wins[x][0]] == current &&
            boardArray[wins[x][1]] == current &&
            boardArray[wins[x][2]] == current  )
    	return true;
    }
	return false;
}

//searches the board to see if a move will create a fork for symbol input
//Bones
int Board::findFork(char symbol)
{
	int winningMoves = 0;
	for (int x = 0; x < 9; x++)
    {
        if (boardArray[x] == ' ')
        {
            boardArray[x] = symbol;

			for (int x = 0; x < 9; x++)
			{
				if (boardArray[x] == ' ')
				{
					if (isWinning(symbol, x)) winningMoves++;
				}
				if (winningMoves >= 2) return x;
				else winningMoves = 0;
			}
            boardArray[x] = ' ';
        }
    }
	//returning 000 means that no fork was found
	return 000;
}

//Bones
void Board::makeMove(int position)
{
	if (boardArray[position] == ' ') boardArray[position] = current;
	else cout << "Invalid move" << endl;
}
