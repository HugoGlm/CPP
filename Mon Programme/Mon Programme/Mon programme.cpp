#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
const HANDLE _hconsole = GetStdHandle(STD_OUTPUT_HANDLE);

#pragma region Proto calculator
int Add(int , int);
int Substract(int, int);
int Multiply(int, int);
int Div(int , int );
void Number();
void TitleCalculator();
void ChooseOperator();
void ResultCalcul();
#pragma endregion
#pragma region Proto  table of Multiplication
void TitleTable();
void ChooseNumber();
void Calcul(int );
void ResultTableOfMultiplication();
#pragma endregion
#pragma region Proto swap
void MenuSwapAdresse();
void SwapAToB(int*, int*);
void DefineAdresse();
#pragma endregion

#pragma region parameter menu
const int sizeMenu = 3;
char inputMenu[sizeMenu] = { 't', 'c', 's'};
#pragma endregion
#pragma region parameter cacul
int x, y;
int tab[4] = {'+', '-', '*', '/'};
#pragma endregion
#pragma region parameter table of multiplication
int numberChoose, calcul, result;
#pragma endregion
#pragma region parameter swap
int a, b;
#pragma endregion

#pragma region Calculator
int Add(int _a, int _b)
{
	return _a + _b;
}
int Substract(int _a, int _b)
{
	return _a - _b;
}
int Multiply(int _a, int _b)
{
	return _a * _b;
}
int Div(int _a, int _b)
{
	return _b == 0 ? 0 : _a / _b;
}
void Number()
{
	cout << "Number One : ";
	cin >> x;
	cout << "Number Two : ";
	cin >> y;
	cout << "\n";
}
void TitleCalculator()
{
	cout << "calculator \n";
}
void ChooseOperator()
{
	cout << "Choose operator +, -, *, / : \n";
	char _input;
	cin >> _input;

	if (_input == tab[0])
		cout << "Add : " << Add(x, y) << "\n";
	else if (_input == tab[1])
		cout << "Substract : " << Substract(x, y) << "\n";
	else if (_input == tab[2])
		cout << "Multiply : " << Multiply(x, y) << "\n";
	else if (_input == tab[3])
		cout << "Div : " << Div(x, y) << "\n";
}
void MenuCalcul()
{
	SetConsoleTextAttribute(_hconsole, 6);
	TitleCalculator();
	Number();
	ChooseOperator();
}
#pragma endregion

#pragma region Table of multiplication
void TitleTable()
{
    cout << "Menu table of multiplication\n" << endl;
}
void ChooseNumber()
{
	TitleTable();
	cout << "Set number to see his table of multiplication (between 1 and 10)\n";
	cin >> numberChoose;
}
void Calcul(int _number)
{
	cout << "You choose the table of " << _number << endl;

	for (int i = 1; i <= 10; i++)
	{
		cout << _number << " * "<< i << " : " << _number * i << endl;
	}
}
void MenuTableOfMultiplication()
{
	SetConsoleTextAttribute(_hconsole, 3);
	ChooseNumber();
	Calcul(numberChoose);
}
#pragma endregion

#pragma region Swap adresse
void DefineAdresse()
{
	cout << "Define a : " << endl;
	cin >> a;
	cout << "Define b : " << endl;
	cin >> b;
}
void SwapAToB(int* _a, int* _b)
{
	cout << "a : " << _a << " == " << a << endl;
	cout << "b : " << _b << " == " << b << endl;
	int* _tmp;
	_tmp = _a;
	_a = _b;
	_b = _tmp;
	int _tmpo;
	_tmpo = a;
	a = b;
	b = _tmpo;
	cout << "a : " << _a << " == " << a << endl;
	cout << "b : " << _b << " == " << b << endl;
}
void MenuSwapAdresse()
{
	SetConsoleTextAttribute(_hconsole, 5);
	DefineAdresse();
	SwapAToB(&a, &b);
}
#pragma endregion

void Menu()
{
	SetConsoleTextAttribute(_hconsole, 2);
	cout << "Choose option :" << endl
		<< "table of multiplication " << inputMenu[0] << endl
		<< "calculator " << inputMenu[1] << endl
		<< "swap " << inputMenu[2] << endl;
	char _option;
    cin >> _option;

	if (_option == inputMenu[0])
        MenuTableOfMultiplication();
    else if (_option == inputMenu[1])
        MenuCalcul();
    else if (_option == inputMenu[2])
        MenuSwapAdresse();
	else
		Menu();
}

void main()
{
	while(true)
		Menu();
}