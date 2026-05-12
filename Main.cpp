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

    bool gameOver = false;
    int choice;

    //Checks to see if the game is over.
    //Figures out what the game will be and who's playing. Then, it will go through turns and check for a win until someone wins oor a draw happens.
    //Srujan
    while (!gameOver)
    {
        if (board.getMultiplayer() || (!board.getMultiplayer() && board.getCurrent() == 'X'))
        {
            cout << "\nPlayer " << board.getCurrent() << ", enter your move (0-8): ";
            cin >> choice;

            // validation to make sure the spot is on the board
            if (choice < 0 || choice > 8) {
                cout << "Invalid spot! Please choose 0-8." << endl;
                continue; 
            }
            
            board.makeMove(choice);
        }
        else
        {
            // Computer turn
            cout << "\nComputer (O) is thinking..." << endl;
            board.bestMove();
        }

        // Gotta show the user the board
        board.showBoard();
        //check for game end
        board.checkGameEnd();
        // Move on with the turn
        board.changeTurn();

        char response;
        cout << "Do you wish to play another game? (y/n): ";
        cin >> response;

        if (response == 'y' || response == 'Y') {
            gameOver = false;
            //reset booard
            for (int c = 0; c <= 8; c++) {
                resetboardArray(c);
            }
        }
        else {
        gameOver = true;
        cout << "Thanks for playing!" << endl;
        }
    }

    return 0;
}
