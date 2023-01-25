#include <iostream>
using namespace std;

class Vehicule
{
protected:
    string name = "";
public:
    string Name()
    {
        return name;
    }
    Vehicule() = default;
    Vehicule(const string _name)
    {
        name = _name;
    }
};
class LandVehicule : public Vehicule
{
protected:
    int wheels = 0;
public:
    int Wheel()
    {
        return wheels;
    }
    LandVehicule() = default;
    LandVehicule(const string _name) : Vehicule(_name){ }
};
class Car : public LandVehicule
{
public:
    Car() : LandVehicule("Car")
    {
        wheels = 4;
    }
};
class Motorcycle : public LandVehicule
{
public:
    Motorcycle() : LandVehicule("Motorcycle")
    {
        wheels = 2;
    }
};
class Plane : public Vehicule
{
private:
    int wheels = 0;
    int engine = 0;
public:
    int Wheels()
    {
        return wheels;
    }
    int Engine()
    {
        return engine;
    }
    Plane() = default;
    Plane(const string _name, int _wheels = 8, int _engine = 2) : Vehicule(_name)
    {
        wheels = _wheels;
        engine = _engine;
    }
};
int main()
{
    
}