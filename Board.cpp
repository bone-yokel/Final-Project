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
	for (int x = 0; x < 9; x++)
	{
		cout << "\t\t|\t\t|\n"
			<< "\t" << boardArray[x] << "\t|\t" << boardArray[++x] << "\t|\t" << boardArray[++x] << "\t\n"
			<< "\t\t|\t\t|\n";
		if (x == 8) cout << "\n\n";
		else cout << "-----------------------------------------------\n";
	}
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

bool Board::isWinning(char symbol, int posistion)
{

}

bool Board::isFork(char symbol, int posistion)
{

}

//Bones
void Board::makeMove(int position)
{
	if (boardArray[position] == ' ') boardArray[position] = current;
	else cout << "Invalid move" << endl;
}
