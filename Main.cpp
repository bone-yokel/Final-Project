#include <iostream>
#include "Board.h"
#include <string>
using namespace std;

int main()
{

    //Objects and variables
    Board board;
    char playerAnswer = ' ';

    //Introduction text
    cout << "Welcome to Tic Tac Toe" << endl;
    cout << "Here are the rules of the game:" << endl << endl;
    cout << "1) The game only accepts 2 opponents, within a 1 player game mode or a 2 player game mode, whether it be a player vs. player, player vs. computer" << endl;
    cout << "2) The game consists of a 3 by 3 grid, of which each grid is made to hold a reprehensive symbol, (0 or 1) for each player" << endl;
    cout << "3) Players take turns, in alternating order, placing their representative symbol in a grid slot" << endl;
    cout << "4) Players may not override or replace any grid slot that has already been filled with a player’s symbol" << endl;
    cout << "5) Players win the game when 3 grid slots containing the player’s symbols align in a row, column, or diagonal across the 3 by 3 grid." << endl << endl;

    //Getting player count
    board.playerCount();

    cout << "\nYou will be playing X. Here is the board:" << endl << endl;
    board.showBoard();


    return 0;
}
