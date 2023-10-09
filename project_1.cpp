#include <iostream>
using namespace std;

void game()
{
    srand(time(0));
    int ans = rand() % 100 + 1;
    int guesses = 0;
    int guess = -1;
    cout << "WELCOME TO NUMBER GUESSING GAME!" << endl
         << "INSTRUCTIONS: You will have to guess a random number between 0-100 and the program will guide you whether your guess is higher or lower than the actual number. You have a total of 10 attempts" << endl;
    while (guess != ans && guesses <= 10)
    {
        cout << "Enter your guess: ";
        cin >> guess;
        guesses++;
        if (guess > ans)
        {
            cout << "Too High! Please try again" << endl;
        }
        else if (guess < ans)
        {
            cout << "Too Low! Please try again" << endl;
        }
        else
        {
            cout << "CONGRATULATIONS! YOU WON." << endl
                 << "You guessed it in " << guesses << " attempts!" << endl;
            exit(0);
        }
    }
    cout << "You failed to guess the number! Better luck next time." << endl;
}

int main()
{
    game();
    return 0;
}