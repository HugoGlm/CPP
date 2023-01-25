#include "Exit.h"

std::string Exit::Name()
{
    return "exit";
}
std::string Exit::Description()
{
    return "Quits the CMD.EXE program (command interpreter).";
}
void Exit::Exec()
{
    int _input;
    std::cin >> _input;
    exit(_input);
}
