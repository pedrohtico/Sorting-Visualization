#include "SelectionSort.h"

SelectionSort::SelectionSort(int N)
	: Sort(N) {}

void SelectionSort::update()
{
	if (isSorted) return;

	int min = this->array[0];
	int index = 0;
	int aux;


	for (int j = this->step; j < N; j++)
	{
		if (array[j] < min) {
			min = array[j];
			index = j;
		}
	}
	aux = array[this->step];
	array[this->step] = min;
	array[index] = aux;

	this->step++;
	if (this->step >= N)
		isSorted = true;
}