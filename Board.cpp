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

void Board::playerCount()
{
   //Getting player count
        cout << "Will you be playing with another person? Y/N: ";
    cin >> playerAnswer;

    //Making sure input is valid
    while (playerAnswer != 'Y' && playerAnswer != 'y' && playerAnswer != 'N' && playerAnswer != 'n')
    {
        cout << "Sorry, that is an invalid answer. Please enter either 'Y' or 'N'" << endl;
            cout << "Will you be playing with another person? Y/N: ";
        cin >> playerAnswer;
    }

    //setting multiplaer private member variable according to input
    if (playerAnswer == 'Y' || playerAnswer == 'y') board.setMultiplayer(true);
    else board.setMultiplayer(false);
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

//finds and makes the best possible move for the current player
//Bones
void Board::bestMove()
{
	bool moveFound = false;
	
    // 1. Take a winning move if possible
    for (int x = 0; x < 9 && moveFound == false; x++)
    {
        if (boardArray[x] == ' ')
        {
            if (isWinning(current, x))
			{
				boardArray[x] = current;
				moveFound = true;
			}
        }
    }

	// 2. Block opponents winning move
	if (moveFound == false)
	{
		for (int x = 0; x < 9 && moveFound == false; x++)
    	{
        	if (boardArray[x] == ' ')
       		{
            	if (isWinning(opponent, x))
				{
					boardArray[x] = current;
					moveFound = true;
				}
        	}
    	}
	}
	
	// 3. Create a fork
	if (moveFound == false)
	{
		int forkPosition = findFork(current);
		if (forkPosition !=  000)
		{
			boardArray[forkPosition] = current;
			moveFound = true;
		}
	}
	
	// 4. Block opponent fork
	if (moveFound == false)
	{
		int forkPosition = findFork(opponent);
		if (forkPosition !=  000)
		{
			boardArray[forkPosition] = current;
			moveFound = true;
		}
	}
	
	// 5. Take center
	if (moveFound == false)
	{
		if (boardArray[4] == ' ')
		{
			boardArray[4] = current;
			moveFound = true;
		}
	}
	
	// 6. Take corner
	if (moveFound == false)
	{
		int corners[4] = {0, 2, 6, 8};
	    for (int x = 0; x < 4 && moveFound == false; x++)
    	{
       		if (boardArray[corners[x]] == ' ')
			{
				boardArray[corners[x]] = current;
				moveFound = true;
			}
    	}
	}
	
	// 7. Take edge
	if (moveFound == false)
	{
	    int edges[4] = {1, 3, 5, 7};
    	for (int x = 0; x < 4 && moveFound == false; x++)
   		{
        	if (boardArray[edges[x]] == ' ')
			{
				boardArray[edges[x]] = current;
				moveFound = true;
			}
    	}
	}
}

//Determines if placing a symbol at a position will win the game
//Bones
bool Board::isWinning(char symbol, int posistion)
{
	for (int x = 0; x < 8; x++)
    {
        if (boardArray[wins[x][0]] == current &&
            boardArray[wins[x][1]] == current &&
            boardArray[wins[x][2]] == current  )
    	return true;
    }
	return false;
}

//searches the board to see if a move will create a fork for symbol input
//Bones
int Board::findFork(char symbol)
{
	int winningMoves = 0;
	for (int x = 0; x < 9; x++)
    {
        if (boardArray[x] == ' ')
        {
            boardArray[x] = symbol;

			for (int x = 0; x < 9; x++)
			{
				if (boardArray[x] == ' ')
				{
					if (isWinning(symbol, x)) winningMoves++;
				}
				if (winningMoves >= 2) return x;
				else winningMoves = 0;
			}
            boardArray[x] = ' ';
        }
    }
	//returning 000 means that no fork was found
	return 000;
}

//Bones
void Board::makeMove(int position)
{
	if (boardArray[position] == ' ') boardArray[position] = current;
	else cout << "Invalid move" << endl;
}
