#include "InsertionSort.h"

InsertionSort::InsertionSort(int N)
	: Sort(N) {}

void InsertionSort::update()
{
	if (isSorted) return;
	int i = this->step;
	int aux = array[i];
	int j = i - 1;
		
	while(j >= 0 && array[j] > aux)
	{
		array[j + 1] = array[j];
		j--;
	}
	array[j + 1] = aux;
	this->step++;
	if (this->step >= N) isSorted = true;
}