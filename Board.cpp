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

bool Board::isWinning(char symbol, int posistion)
{
	//place holder return
	return false;
}

bool Board::isFork(char symbol, int posistion)
{
	//place holder return
	return false;
}

//Bones
void Board::makeMove(int position)
{
	if (boardArray[position] == ' ') boardArray[position] = current;
	else cout << "Invalid move" << endl;
}
