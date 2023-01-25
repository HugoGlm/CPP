#include <iostream>
#include <string>
using namespace std;

// cin / out - choisir le mode, et entrer la valeur 
// result

#pragma region Feet/Meter
std::string GetFeetFromMeter(float _meter)
{
	float _result = _meter * 3.28f;
	return to_string(_meter) + "m to feet is = " + to_string(_result) + " ft\n";
}
string GetMeterFromFeet(float _feet)
{
	float _result = _feet / 3.28f;
	return to_string(_feet) + "feet to m is = " + to_string(_result) + " m\n";
}
#pragma endregion
#pragma region Kmh/Knots
string GetKmhFromKnots(float _knots)
{
	float _result = _knots * 1.852f;
	return to_string(_knots) + "kts to km/h is = " + to_string(_result) + " km/h\n";
}

string GetKnotsFromKmh(float _kmh)
{
	float _result = _kmh / 1.852f;
	return to_string(_kmh) + "km/h to kts is = " + to_string(_result) + " kts\n";
}
#pragma endregion
#pragma region Celcius/Far
string GetCelciusFromF(float _fTemp)
{
	float _result = (_fTemp * 9 / 5) + 32;
	return to_string(_fTemp) + "F to C is = " + to_string(_result) + " C\n";
}
string GetFFromCelcius(float _celcius)
{
	float _result = (_celcius - 32) * 5 / 9;
	return to_string(_celcius) + "C to F is = " + to_string(_result) + " F\n";
}
#pragma endregion
#pragma region Liter/Gallon
string GetLiterFromGallon(float _liter)
{
	float _result = _liter / 3.785f;
	return to_string(_liter) + "L to G is = " + to_string(_result) + " G\n";
}
string GetGallonFromLitter(float _gallon)
{
	float _result = _gallon * 3.785f;
	return to_string(_gallon) + "G to L is = " + to_string(_result) + " L\n";
}
#pragma endregion

float GetValueToConvert()
{
	cout << "Enter value to convert : \n";
	float _value;
	cin >> _value;
	return _value;
}

void ConverterMenu()
{
#pragma region menu
	cout << "1 - Convert meter to feet\n";
	cout << "2 - Convert feet to meter \n";
	cout << "3 - Convert kmh to kts \n";
	cout << "4 - Convert kts to kmh \n";
	cout << "5 - Convert F to C \n";
	cout << "6 - Convert C to F \n";
	cout << "7 - Convert G/US to L \n";
	cout << "8 - Convert L to G/US \n";
	cout << "[Select number from 1 to 8] \n";
#pragma endregion
	char _input;
	cin >> _input;
	if (_input == '1')
		cout << GetMeterFromFeet(GetValueToConvert());
	else if(_input == 2)
		cout << GetFeetFromMeter(GetValueToConvert());
	else if (_input == '3')
		cout << GetKmhFromKnots(GetValueToConvert());
	else if (_input == '4')
		cout << GetKnotsFromKmh(GetValueToConvert());
	else if (_input == '5')
		cout << GetFFromCelcius(GetValueToConvert());
	else if (_input == '6')
		cout << GetCelciusFromF(GetValueToConvert());
	else if (_input == '7')
		cout << GetGallonFromLitter(GetValueToConvert());
	else if (_input == '8')
		cout << GetLiterFromGallon(GetValueToConvert());
	else
	{
		system("CLS");
		ConverterMenu();
	}
}

int main()
{
	system("CLS");
	ConverterMenu();
}