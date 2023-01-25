#include <iostream>
using namespace std;

int n, u, k;

int CelciusToFar(int _c)
{
	return (_c * 9 / 5) + 32;
}
int FarToCelcius(int _f)
{
	return (_f - 32) * 5 / 9;
}
int KmhToKnots(int _k)
{
	return _k / 1.852;
}
int KnotsToKmh(int _k)
{
	return _k * 1.852;
}
int LiterToGallon(int _l)
{
	return _l / 3.785;
}
int GallonToLiter(int _g)
{
	return _g * 3.785;
}
int FeetToMeter(int _f)
{
	return _f / 3.281;
}
int MeterToFeet(int _m)
{
	return _m * 3.281;
}

void SelectUnit()
{
	cout << "Select unit :" << "\n" << "1 = celcius to far" << "\n" << "2 = invert of 1" << "\n" << "3 = kmh to knots" << "\n" << "4 = invert of 3" << "\n" << "5 = litre to gallon" << "\n" << "6 = invert of 5" << "\n" << "7 = feet to meter" << "\n" << "8 = invert of 7" << "\n";
	cin >> u;
	cout << "Set your number : " << "\n";
	cin >> n;
	if (u == 1)
	{
		cout << "result : " << CelciusToFar(n) << "Fh" <<"\n";
		SelectUnit();
	}
	else if (u == 2)
	{
		cout << "result : " << FarToCelcius(n) << "°C" << "\n";
		SelectUnit();
	}
	else if (u == 3)
	{
		cout << "result : " << KmhToKnots(n) << "Kn" << "\n";
		SelectUnit();
	}
	else if (u == 4)
	{
		cout << "result : " << KnotsToKmh(n) << "Km/h" << "\n";
		SelectUnit();
	}
	else if (u == 5)
	{
		cout << "result : " << LiterToGallon(n) << "G" << "\n";
		SelectUnit();
	}
	else if (u == 6)
	{
		cout << "result : " << GallonToLiter(n) << "L" << "\n";
		SelectUnit();
	}
	else if (u == 7)
	{
		cout << "result : " << FeetToMeter(n) << "M" << "\n";
		SelectUnit();
	}
	else if (u == 8)
	{
		cout << "result : " << MeterToFeet(n) << "F" << "\n";
		SelectUnit();
	}
	else
	{
		SelectUnit();
	}
}

int main()
{
	SelectUnit();
}