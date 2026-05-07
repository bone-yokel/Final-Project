#include <iostream>
#include "Board.h"

//constructor
Board::Board()
{
  current = 'X';
  opponent = 'O';
  multiplayer = false
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
