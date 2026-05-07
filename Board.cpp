#include <iostream>
#include "Board.h"

//constructor
Board::Board()
{
  current = 'X';
  opponent = 'O';
  multiplayer = false
  for (int x = 0; x<9; x++) boardArray[x] = ' ';
}

//Swaps the symbols of current and opponenet players
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

void Board::showBoard();
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

void Board::setMultiplayer(bool b);
{

}

void Board::checkGameEnd();
{

}

void Board::bestMove(char symbol);
{

}

bool Board::isWinning(char symbol, int posistion);
{

}

bool Board::isFork(char symbol, int posistion);
{

}

void Board::makeMove(int position);
{

}
