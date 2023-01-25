#include <iostream>

//class A
//{
//public:
//    std::string name = " ";
//    A() = default;
//    A(std::string _name)
//    {
//        name = _name;
//    }
//    std::string Name()
//    {
//        return name;
//    }
//};
//
//class B : public A
//{
//public:
//    B()
//    {
//        name = 'B';
//    }
//};

class Entity
{
private:
    float life = 0.0f;
public:
    Entity() = default;
    void SetLife(float _life)
    {
        life = _life;
    }
    virtual void Draw()
    {
        std::cout << "Draw entity";
    }
};

class Player : public Entity
{
private:
    std::string nickName = "";
    Entity* ent = new Entity;
public:
    Player() = default;
    Player(std::string _name)
    {
        nickName = _name;
    }
    ~Player()
    {
        delete ent;
    }
    std::string NickName() const
    {
        return nickName;
    }
    void Draw() override
    {
        std::cout << "Draw Player" << std::endl;
    }
      
};

int main()
{
    Player p = Player("Toto");
    Entity e = Entity();
    p.Draw();
    e.Draw();

    /*A a = A("Toto");
    B b = B();
    std::cout << a.Name() << " " << b.Name();*/
}