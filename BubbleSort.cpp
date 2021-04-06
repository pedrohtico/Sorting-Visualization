#include "BubbleSort.h"

BubbleSort::BubbleSort(int N)
	: Sort(N) {
	has_swapped = false;
	this->step++;
}

void BubbleSort::update()
{
	if (isSorted) return;
	for (int i = 0; i < N - this->step; i++)
	{
		if (array[i] > array[i+1])
		{
			int aux = array[i];
			array[i] = array[i+1];
			array[i+1] = aux;
			has_swapped = true;
		}
	}

	if (!has_swapped) isSorted = true;
	
	this->step++;
	has_swapped = false;
}