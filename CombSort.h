#pragma once
#include "Sort.h"
class CombSort :
    public Sort
{
public:
    CombSort(int N);
    void update() override;
private:
    int gap;
    bool hasSwapped;
    const double shrinking_factor = 1.247330950103979;
};

