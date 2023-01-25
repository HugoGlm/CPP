#include <iostream>
#include <vector>
#include "Abstract.h"
#include "AbstractChild.h"
#include "IFly.h"
#include "Bird.h"

int main()
{
	std::vector<Abstract*> abstracts = {};
	AbstractChild a;

	IFly* _fly = new Bird();
}