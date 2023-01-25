#include <iostream>

int main()
{
    std::string t = "Hello World!";

	std::string res = "";
    
	for (int i = 0; i < t.length(); i++)
	{
		if (isspace(t[i]))
			res += "*";
		else if (isupper(t[i]))
			res += "-";
		else
			res += "_";
	}
	std::cout << res << std::endl;
}