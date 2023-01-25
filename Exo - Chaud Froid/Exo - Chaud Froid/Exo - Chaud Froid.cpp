#include <iostream>
using namespace std;
#pragma region Parameter
int numberGuess = 0,
    minGuess = 1,
    maxGuess = 100,
    gameAttempt = 0,
    gameAttemptMax = 30;
bool useLimitGame = false;
#pragma endregion
void SetGuessNumber(int _min, int _max)
{
    gameAttempt = 0;
    cout << "Set number between " << _min << " and " << _max << endl;
    cin >> numberGuess;
    system("CLS");
}

void IsValidGuess(int _min, int _max)
{
    if (numberGuess < _min || numberGuess > _max)
        SetGuessNumber(_min, _max);
}
void GuessGame(int _min, int _max)
{
    cout << "Choose number between " << _min << " and " << _max << endl;
    int _number = 0;
    cin >> _number;
    gameAttempt++;
    if (useLimitGame)
    {
        if (gameAttempt >= gameAttemptMax)
        {
            cout << "You lose ! No more try \n";
            SetGuessNumber(_min, _max);
            GuessGame(minGuess, maxGuess);
        }
    }
    if (_number < numberGuess)
    {
        cout << "More !\n";
        GuessGame(minGuess, maxGuess);
    }
    else if (_number > numberGuess)
    {
        cout << "less !\n";
        GuessGame(minGuess, maxGuess);
    }
    else if (_number == numberGuess)
    {
        cout << "It's win !\n";
        cout << gameAttempt << " attempt !\n";
        SetGuessNumber(_min, _max);
        GuessGame(minGuess, maxGuess);
    }

}
int main()
{
    SetGuessNumber(minGuess, maxGuess);
    IsValidGuess(minGuess, maxGuess);
    GuessGame(minGuess, maxGuess);
}