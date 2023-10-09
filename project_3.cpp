#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'},
                    {'4', '5', '6'},
                    {'7', '8', '9'}};
char turn = 'X';
bool draw = false;

void displayBoard()
{
    cout << "\t     |     |     \n";
    cout << "\t  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << " \n";
    cout << "\t_____|_____|_____\n";
    cout << "\t     |     |     \n";
    cout << "\t  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << " \n";
    cout << "\t_____|_____|_____\n";
    cout << "\t     |     |     \n";
    cout << "\t  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << " \n";
    cout << "\t     |     |     \n";
}

bool playerTurn()
{
    int row, col;
    int choice;
    if (turn == 'X')
    {
        cout << "Player 1 [X] turn:" << endl;
    }
    else if (turn == 'O')
    {
        cout << "Player 2 [O] turn:" << endl;
    }
    cin >> choice;
    if (choice < 1 || choice > 9)
    {
        cout << "Invalid Input" << endl;
    }
    else
    {
        row = (choice - 1) / 3;
        col = (choice - 1) % 3;
        if (board[row][col] != 'X' && board[row][col] != 'O')
        {
            board[row][col] = turn;
            return true;
        }
        else
        {
            cout << "Box already filled! Please try another one" << endl;
        }
    }
    return false;
}

bool gameover()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return false;
        }
    }
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return false;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return true;
        }
    }
    draw = true;
    return false;
}

int main()
{
    char choice;
    do
    {
        cout << "WELCOME TO TIC TAC TOE GAME" << endl;
        while (gameover())
        {
            displayBoard();
            if (playerTurn())
            {
                if (turn == 'X')
                {
                    turn = 'O';
                }
                else
                {
                    turn = 'X';
                }
            }
        }
        displayBoard();
        if (turn == 'X' && draw == false)
        {
            cout << "Player 2 [O] WINS" << endl;
        }
        else if (turn == 'O' && draw == false)
        {
            cout << "Player 1 [X] WINS" << endl;
        }
        else
        {
            cout << "IT'S A DRAW!" << endl;
        }
        cout << "Do you want to play another game? [Y/N]" << endl;
        cin >> choice;
        if (choice == 'Y' || choice == 'y')
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    board[i][j] = '1' + i * 3 + j;
                }
            }
            turn = 'X';
            draw = false;
        }
    } while (choice == 'Y' || choice == 'y');
    return 0;
}