#include <iostream>
using namespace std;

const int sizeTab = 5;
string tabFr[sizeTab] = { "avion", "arbre", "pomme", "eau", "chevre" },
       tabEn[sizeTab] = { "plane", "tree", "apple", "water", "goat"};
string lastInput;
bool isFrenchTranslation = false;

string GetModeWords(bool _frMode)
{
    string _word = "";
    if (_frMode)
    {
        for (int i = 0; i < sizeTab; i++)
        {
            string _endWord = (i == sizeTab-1) ? "." : ", ";
            _word += tabEn[i] + _endWord;
        }
        return " Word are : " + _word;
    }
    else
    {
        for (int i = 0; i < sizeTab; i++)
        {
            string _endWord = (i == sizeTab-1) ? "." : ", ";
            _word += tabFr[i] + _endWord;
        }
        return " Les mots sont : " + _word;
    }
}
void InitTranslator(bool _frMode)
{
    cout << GetModeWords(_frMode) << endl;
}
string IsValidWord(string _input)
{
    for (int i = 0; i < sizeTab; i++)
    {
        if (_input == tabFr[i])
            return  tabEn[i];
        if (_input == tabEn[i])
            return tabFr[i];
    }
}

string InputMode()
{
    string _input;
    cin >> _input;
    cout << "Word is : " << _input << endl;
    return _input;
}

int main()
{
    InitTranslator(isFrenchTranslation);
    lastInput = InputMode();
    cout << IsValidWord(lastInput) << endl;
    main();
}