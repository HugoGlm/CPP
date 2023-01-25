#include "ItemCMD.h"

#pragma region constructor
ItemCMD::ItemCMD(const std::string _name, const std::string _desc)
{
    name = _name;
    description = _desc;
}
ItemCMD::~ItemCMD()
{
    name = nullptr;
    description = nullptr;
}
#pragma endregion