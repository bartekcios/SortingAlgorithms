#ifndef CCOUNTINGSORT_H
#define CCOUNTINGSORT_H
#include "isortingalgorithm.h"

class CCountingSort : public ISortingAlgorithm
{
public:
    CCountingSort();
    virtual ~CCountingSort();

    // ISortingAlgorithm interface
    void sort();
};

#endif // CCOUNTINGSORT_H
