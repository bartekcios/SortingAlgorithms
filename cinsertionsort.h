#ifndef CINSERTIONSORT_H
#define CINSERTIONSORT_H
#include "isortingalgorithm.h"

class CInsertionSort : public ISortingAlgorithm
{
public:
    CInsertionSort();
    virtual ~CInsertionSort();

    // ISortingAlgorithm interface
    void sort();
};

#endif // CINSERTIONSORT_H
