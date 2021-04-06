#pragma once
#include "Sort.h"
class BubbleSort :
    public Sort
{
public:
    BubbleSort(int N);
    void update() override;
private:
    bool has_swapped;
};

