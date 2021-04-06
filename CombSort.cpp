#include "CombSort.h"

CombSort::CombSort(int N)
	: Sort(N) {
	gap = (int) ((N - 1) / shrinking_factor);
	hasSwapped = false;
}

void CombSort::update()
{
	if (isSorted) return;
	for (int i = 0; i < N; i++)
	{
		if (i + gap < N)
		{
			if (array[i] > array[i + gap]) {
				int aux = array[i];
				array[i] = array[i + gap];
				array[i + gap] = aux;
				hasSwapped = true;
			}
		}
		else break;
	}

	gap = (int) (gap / shrinking_factor);
	if (gap <= 0 || !hasSwapped) isSorted = true;

	hasSwapped = false;
}