#include <iostream>
#include "Utils/Matrice/Matrice.h"
#include <format>

void Display(std::string _text, Matrice _item)
{
    std::string _aff = "==============================";
    std::cout << _aff << std::endl << _text << std::endl << _item.ToString() << std::endl << _aff << std::endl;
}
void Display(std::string _text, float _item)
{
    std::string _aff = "==============================";
    std::cout << _aff << std::endl << _text << std::endl << _item << std::endl << _aff << std::endl;
}

int main()
{
    Matrice M = Matrice(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
    Matrice M1 = Matrice(17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32);
    Display("Identity", Matrice::Identity());
    Display("Translation", Matrice::CreateTranslation(10, 25, 45));
    Display("RotationX", Matrice::CreateRotationX(25.0f));
    Display("RotationY", Matrice::CreateRotationY(35.0f));
    Display("RotationZ", Matrice::CreateRotationZ(45.0f));
    Display("Orthographic", Matrice::CreateOrthographic(100, 80, 250, 150));
    Display("Lerp => 0", Matrice::Lerp(M, M1, 0.0f));
    Display("Lerp => 0.5", Matrice::Lerp(M, M1, 0.5f));
    Display("Lerp => 1", Matrice::Lerp(M, M1, 1.0f));
    Display("Determinant", M.GetDeterminant());
}