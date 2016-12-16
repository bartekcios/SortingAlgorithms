#ifndef CQUICKSORT_H
#define CQUICKSORT_H
#include "isortingalgorithm.h"

class CQuickSort : public ISortingAlgorithm
{
public:
    CQuickSort();
    virtual ~CQuickSort();

    // ISortingAlgorithm interface
    void sort();
    void sort(ArraySize_t a_uFirstElementIndex, ArraySize_t a_uLastElementIndex);
};

#endif // CQUICKSORT_H
