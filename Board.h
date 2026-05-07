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
  void setMultiplayer(bool);
  void checkGameEnd();
  void bestMove(char);
  bool isWinning(char, int);
  bool isFork(char, int);
  void makeMove(int);
};
