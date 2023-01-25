#include <iostream>
using namespace std;

int x, y;

int ChooseNumber()
{
	cout << "Set Number (1 to 100) : " << "\n";
	cin >> x;
	return x;
}

void NumberSelection()
{
	cout << "Choose Number (1 to 100) : " << "\n";
	cin >> y;

	if (y > x)
	{
		cout << "Less" << "\n";
		NumberSelection();
	}
	else if (y < x)
	{
		cout << "More" << "\n";
		NumberSelection();
	}
	else
		cout << "It's win !!!";
}

int main()
{
	ChooseNumber();
	system("CLS");
	NumberSelection();
}