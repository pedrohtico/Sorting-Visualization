#pragma once
#include "Sort.h"
class SelectionSort :
    public Sort
{
public:
    SelectionSort(int N);
    void update() override;
};

