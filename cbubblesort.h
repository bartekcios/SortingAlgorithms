#ifndef CBUBBLESORT_H
#define CBUBBLESORT_H
#include "isortingalgorithm.h"

class CBubbleSort : public ISortingAlgorithm
{
public:
    CBubbleSort();
    virtual ~CBubbleSort();

    // ISortingAlgorithm interface
    void sort();
};

#endif // CBUBBLESORT_H
