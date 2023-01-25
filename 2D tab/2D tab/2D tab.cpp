#include <iostream>
using namespace std;

const int sizeTab = 4;
int oneTab[sizeTab] = { 1, 2, 3, 4 };
int twoTab[sizeTab][sizeTab] = {
								{1, 2, 3, 4}, // 0 -> [0, 1, 2, 3] 
								{4, 5, 6, 7},  // 1 -> [0, 1, 2, 3] 
								{8, 9, 10, 11},  // 2 -> [0, 1, 2, 3]
								{12, 13, 14, 15}  // 3 -> [0, 1, 2, 3]
							   }; //4x4

int a[1][2] = {
				{0, 1}
};

int b[2][2] = {
				{0, 1},
				{0, 1}
};

int main()
{
	for (int i = 0; i < sizeTab; i++)
	{
		cout << oneTab[i] << endl;
	}
	for (int i = 0; i < sizeTab; i++)
	{
		for (int j = 0; j < sizeTab; j++)
		{
			cout << twoTab[j] << endl;
		}
	}
}