#pragma once
#include <iostream>

Class Board
{
private:
  char current;
  char opponent;
  bool multiplayer;
public:
  Board();
  void changeTurn();
  void showBoard();
  void setMultiplayer(bool b);
  void checkGameEnd();
  void bestMove(char symbol);
  bool isWinning(char symbol, int posistion);
  bool isFork(char symbol, int posistion);
  void makeMove(int position);
};
