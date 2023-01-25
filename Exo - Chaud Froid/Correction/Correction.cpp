#include <iostream>
using namespace std;

int guessMin = 1,
guessMax = 100,
guess = 0;

bool IsValidGuess(int _input, int _minGuess, int _maxGuess)
{
    if (_input < _minGuess || _input > _maxGuess)
        return false;
    return true;// <- else 
}

void SetNumberGuess(int _min, int _max)
{
    cout << "Set number to guess : \n";
    cin >> guess;
    if (IsValidGuess(guess, _min, _max) == false)
        SetNumberGuess(_min, _max);
    else
        system("CLS");
}

bool Guess(int _guessInput, int _guessValid)
{
    if (_guessInput == _guessValid)
        return true;
    if (_guessInput > _guessValid)
    {
        cout << "Wrong ! It's less !\n";
        return false;
    }
    if (_guessInput < _guessValid)
    {
        cout << "Wrong ! It's more !\n";
        return false;
    }
}

void MainLoop()
{
    int _currentPlayerGuess = 0;
    cin >> _currentPlayerGuess;
    if (Guess(_currentPlayerGuess, guess) == true)
        cout << "Win !";
    else
        MainLoop();
}

int main()
{
    SetNumberGuess(guessMin, guessMax);
    MainLoop();
}