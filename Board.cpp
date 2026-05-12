#include <iostream>
#include <string>
#include "Board.h"
using namespace std;

/*
* Default constructor for Board Class
* -Bones
*/
Board::Board()
{
	current = 'X';
	opponent = 'O';
	multiplayer = false;
	for (int x = 0; x < 9; x++) boardArray[x] = ' ';
}

/*
* void function to get player count from user,
* validates input
* -Ross
*/
void Board::playerCount()
{
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
    if (playerAnswer == 'Y' || playerAnswer == 'y') multiplayer = true;
    else multiplayer = false;
}

//Swaps the symbols of current and opponenet players
//Srujan
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
	cout << "0\t\t|1\t\t|2\n"; // numbering for the top row
	cout << "\t" << boardArray[0] << "\t|\t" << boardArray[1] << "\t|\t" << boardArray[2] << "\t\n";
	cout << "\t\t|\t\t|\n";
	cout << "------------------------------------------------\n";
	
	cout << "3\t\t|4\t\t|5\n"; // numbering for the middle row
	cout << "\t" << boardArray[3] << "\t|\t" << boardArray[4] << "\t|\t" << boardArray[5] << "\t\n";
	cout << "\t\t|\t\t|\n";
	cout << "------------------------------------------------\n";
	
	cout << "6\t\t|7\t\t|8\n"; // numbering for the bottom row
	cout << "\t" << boardArray[6] << "\t|\t" << boardArray[7] << "\t|\t" << boardArray[8] << "\t\n";
	cout << "\t\t|\t\t|\n";

	
}

void Board::gameEnd(char result)
{
	if (result == 'X') cout << endl << "X won the game!";
	else if (result == 'O') cout << endl << "O won the game!";
	else cout << endl << "The game ended in a draw!";
}

//Cheks if the game has ended and passes for who wins
//Srujan
void Board::checkGameEnd()
{
	bool gameOver = false;
	int fullTiles = 0;
	for (int x = 0; x < 8 && gameOver == false; x++)
    {
        if (boardArray[wins[x][0]] == current &&
            boardArray[wins[x][1]] == current &&
            boardArray[wins[x][2]] == current  )
		{
    	gameEnd(current);
		gameOver = true;
		}
			
		else if (boardArray[wins[x][0]] == opponent &&
           		 boardArray[wins[x][1]] == opponent &&
            	 boardArray[wins[x][2]] == opponent  )
		{
		gameEnd(opponent);
		gameOver = true;
		}
    }
	if (!gameOver)
	{
		for (int x = 0; x <= 8; x++) if (boardArray[x] == 'X' || boardArray[x] == 'O') fullTiles++;
		if (fullTiles == 9) gameEnd('T');
		fullTiles = 0;
	}
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
bool Board::isWinning(char symbol, int position) {
	boardArray[position] = symbol;
	for (int x = 0; x < 8; x++)
    {
        if (boardArray[wins[x][0]] == symbol &&
            boardArray[wins[x][1]] == symbol &&
            boardArray[wins[x][2]] == symbol  ) {
		boardArray[position] = ' ';
    	return true; }
    }
	boardArray[position] = ' ';
	return false;
}
//searches the board to see if a move will create a fork for symbol input
//Bones
int Board::findFork(char symbol)
{
    for (int i = 0; i < 9; i++)
    {
        if (boardArray[i] == ' ')
        {
            boardArray[i] = symbol;
            int winningMoves = 0;

            for (int x = 0; x < 9; x++)
            {
                if (boardArray[x] == ' ')
                {
                    if (isWinning(symbol, x)) winningMoves++;
                }
            }

            boardArray[i] = ' '; // resetting

            if (winningMoves >= 2) return i; // return after checking all x spots
        }
    }
    return 000; // return -1 to indicate no fork being found
}

//Bones
void Board::makeMove(int position)
{
	if (boardArray[position] == ' ') boardArray[position] = current;
	else cout << "Invalid move" << endl;
}
