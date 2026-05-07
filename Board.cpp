#include <iostream>
#include "Board.h"

//constructor
Board::Board()
{
  current = 'X';
  opponent = 'O';
  multiplayer = false
}

void Board::changeTurn()
{

}

void Board::showBoard();
{

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
