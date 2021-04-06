#pragma once
#include "Sort.h"
class InsertionSort :
    public Sort
{
public:
    InsertionSort(int N);
    void update() override;
};

