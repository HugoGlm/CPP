#include <iostream>
using namespace std;

class Vehicule
{
protected:
    int horsePower = 0;
    int numberOfWheels = 0;
    int weight = 0;
public:
    int SetHorsePower(int _horsePower)
    {
        horsePower = _horsePower;
    }
    int SetNumberOfWheels(int _numberOfWheels)
    {
        numberOfWheels = _numberOfWheels;
    }
    int SetWeight(int _weight)
    {
        weight = _weight;
    }
};
class Cars : Vehicule
{
private:
    string carsName = "";
public:
    void CarsName()
    {
        carsName = "Toyota Supra MK4";
        cout << carsName << endl;
    }
    void SetHorsePower()
    {
        horsePower = 330;
        cout << "horse power = " << horsePower << " ch" << endl;
    }
    void SetNumberOfWheels()
    {
        numberOfWheels = 4;
        cout << "number of wheels = " << numberOfWheels << endl;
    }
    void SetWeight()
    {
        weight = 1615;
        cout << "weight = " << weight << " kg" << endl;
    }
};
class Bike : Vehicule
{
private:
    string bikeName = "";
public:
    void BikeName()
    {
        bikeName = "Kawasaki H2R";
        cout << bikeName << endl;
    }
    void SetHorsePower()
    {
        horsePower = 326;
        cout << "horse power = " << horsePower << " ch" << endl;
    }
    void SetNumberOfWheels()
    {
        numberOfWheels = 2;
        cout << "number of wheels = " << numberOfWheels << endl;
    }
    void SetWeight()
    {
        weight = 217;
        cout << "weight = " << weight << " kg" << endl;
    }
};
class Plane : Vehicule
{
private:
    string planeName = "";
public:
    void PlaneName()
    {
        planeName = "concorde";
        cout << planeName << endl;
    }
    void SetHorsePower()
    {
        horsePower = 450;
        cout << "liter per minute = " << horsePower << " l/m" << endl;
    }
    void SetWeight()
    {
        weight = 78700;
        cout << "weight = " << weight << " kg" << endl;
    }
};
int main()
{
    Cars carsName = Cars();
    Cars horsePowerCars = Cars();
    Cars numberOfWheelsCars = Cars();
    Cars weightCars = Cars();
    carsName.CarsName();
    horsePowerCars.SetHorsePower();
    numberOfWheelsCars.SetNumberOfWheels();
    weightCars.SetWeight();
    cout << endl;

    Bike bikeName = Bike();
    Bike horsePowerBike = Bike();
    Bike numberOfWheelsBike = Bike();
    Bike weightBike = Bike();
    bikeName.BikeName();
    horsePowerBike.SetHorsePower();
    numberOfWheelsBike.SetNumberOfWheels();
    weightBike.SetWeight();
    cout << endl;

    Plane planeName = Plane();
    Plane horsePowerPlane = Plane();
    Plane weightPlane = Plane();
    planeName.PlaneName();
    horsePowerPlane.SetHorsePower();
    weightPlane.SetWeight();
}