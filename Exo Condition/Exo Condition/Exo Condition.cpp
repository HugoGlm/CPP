#include <iostream>
using namespace std;

int x, y;

char ChooseSign()
{
	cout << "Set operator (+, -, *, /) : " << endl;
	char _tmpResult;
	cin >> _tmpResult;
	return _tmpResult;
}

void SetMember()
{
	cout << "Set x member : " << endl;
	cin >> x;
	cout << "Set y member : " << endl;
	cin >> y;
}

int Add(int _a, int _b)
{
	return _a + _b;
}

int Sub(int _a, int _b)
{
	return _a - _b;
}

int Multiply(int _a, int _b)
{
	return _a * _b;
}

int Divide(int _a, int _b)
{
	if (_b == 0)
		return 0;
	return _a / _b;
}

void SelectCalculator(char _mode, int _x, int _y)
{
	if (_mode == '+')
		cout << "result : " << Add(_x, _y);
	else if (_mode == '-')
		cout << "result : " << Sub(_x, _y);
	else if (_mode == '*' || _mode == 'x' || _mode == 'X')
		cout << "result : " << Multiply(_x, _y);
	else if (_mode == '/' || _mode == ':')
		cout << "result : " << Divide(_x, _y);
	else
		SelectCalculator(ChooseSign(), x, y);
}

int main()
{
	SetMember();
	SelectCalculator(ChooseSign(), x, y);
}