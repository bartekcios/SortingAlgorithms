#ifndef CSELECTIONSORT_H
#define CSELECTIONSORT_H
#include "isortingalgorithm.h"

class CSelectionSort : public ISortingAlgorithm
{
public:
    CSelectionSort();
    virtual ~CSelectionSort();

    // ISortingAlgorithm interface
    void sort();
};

#endif // CSELECTIONSORT_H
