#include <iostream>
#include <vector>

class Entity
{
public:
	virtual ~Entity()
	{

	}
};
class Player : public Entity
{
public:
	Player() = default;
};
int main()
{
	std::vector<Entity*> _entities = std::vector<Entity*>();
	_entities.push_back(new Entity());
	_entities.push_back(new Player());

	for (int i = 0; i < _entities.size(); i++)
	{
		Entity* _entity = _entities[i];
		Player* p = dynamic_cast<Player*>(_entity);
		if (p != nullptr)
		{
			std::cout << "Is player" << std::endl;
		}
	}
}





//enum Axis
//{
//    x = 1000,
//    y = 1
//};
//
//int main()
//{
//    int _axis = 0;
//    if (_axis == Axis::x)
//    {
//
//    }
//    else if (_axis == Axis::y)
//    {
//
//    }
//    switch (_axis)
//    {
//
//        case 0:
//        {
//            std::cout << "Axis x" << std::endl;
//            break;
//        }
//        case 1:
//        {
//            std::cout << "Axis y" << std::endl;
//            break;
//        }
//        case 3:
//        {
//            std::cout << "Axis Move x" << std::endl;
//            break;
//        }
//        default:
//        {
//            std::cout << "Default" << std::endl;
//            break;
//        }            
//    }
//}