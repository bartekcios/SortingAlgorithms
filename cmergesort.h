#ifndef CMERGESORT_H
#define CMERGESORT_H
#include "isortingalgorithm.h"

class CMergeSort : public ISortingAlgorithm
{
public:
    CMergeSort();
    virtual ~CMergeSort();

    // ISortingAlgorithm interface
    void sort();
private:
    // methods
    void sortRoutine(const ArraySize_t a_uFirstElementIndex, const ArraySize_t a_uLastElementIndex);
    void sortCurrentArray(const ISortingAlgorithm::ArraySize_t a_uFirstElementIndex, const ArraySize_t a_uLastElementIndex, const ArraySize_t a_uLeftSubarrayLastIndex, const ArraySize_t a_uRightSubarrayFirstIndex);
    // members
    ArrayElement_t* m_auTempArray;
};

#endif // CMERGESORT_H
