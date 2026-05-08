#pragma once
#include <iostream>
#include <string>
using namespace std;

class Board
{
private:
  char current;
  char opponent;
  bool multiplayer;
  char boardArray[9];
  int wins[8][3] =
    {
        {0,1,2}, {3,4,5}, {6,7,8}, // rows
        {0,3,6}, {1,4,7}, {2,5,8}, // columns
        {0,4,8}, {2,4,6}           // diagonals
    };
public:
  Board();
  void changeTurn();
  void showBoard();
  void setMultiplayer(bool b);
  void checkGameEnd();
  void bestMove();
  bool isWinning(char symbol, int posistion);
  int findFork(char symbol);
  void makeMove(int position);
  void playerCount(char answer);
};
