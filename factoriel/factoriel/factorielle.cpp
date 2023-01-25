#include <iostream>

int Factorielle(int _n)
{
	if (_n >= 1)
		return (_n * (Factorielle(_n - 1)));
	return 1;
}

int main()
{
	std::cout << Factorielle(11);
}