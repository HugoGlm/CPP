#include <iostream>

int Partitionner(int _tab[], int _first, int _last)
{
	int _pivot = _tab[_first];
	int count = 0;
	for (int i = _first + 1; i <= _last; i++)
		if (_tab[i] <= _pivot)
			count++;
	int pivotIndex = _first + count;
	std::swap(_tab[pivotIndex], _tab[_first]);
	int i = _first, j = _last;

	while (i < pivotIndex && j > pivotIndex)
	{
		while (_tab[i] <= _pivot) i++;
		while (_tab[j] > _pivot) j--;
		if (i < pivotIndex && j > pivotIndex)
			std::swap(_tab[i++], _tab[j--]);
	}

	return pivotIndex;
}

void QuickSort(int _tab[], int _first, int _last)
{
	if (_first >= _last) return;
	int _p = Partitionner(_tab, _first, _last);
	QuickSort(_tab, _first, _p - 1);
	QuickSort(_tab, _p + 1, _last);
}

int main()
{
	int tab[] = { 1, 4, 7, 2, 5, 8, 3, 6, 9, 11, 14, 17, 12, 15, 18, 13, 16, 19, 10};
	int size = sizeof(tab) / sizeof(int);

	QuickSort(tab, 0, size - 1);
	for (int i = 0; i < size; i++)
	{
		std::cout << tab[i] << " ";
	}
	return 0;
}