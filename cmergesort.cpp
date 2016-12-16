#include "cmergesort.h"
#include <iostream>
#include <cstring>
using namespace std;

CMergeSort::CMergeSort():
    ISortingAlgorithm(__func__),
    m_auTempArray(nullptr)
{}

CMergeSort::~CMergeSort()
{}

void CMergeSort::sort()
{
    if(nullptr != m_auArray)
    {
        m_auTempArray = new ArrayElement_t[m_uArraySize];
        if(nullptr != m_auTempArray)
        {
            memset(m_auTempArray, 0u, sizeof(ArrayElement_t)*m_uArraySize);
            sortRoutine(0u, m_uArraySize-1u);

            memcpy(m_auArray, m_auTempArray, sizeof(ArrayElement_t)*m_uArraySize);
        }
    }
}

void CMergeSort::sortRoutine(const ISortingAlgorithm::ArraySize_t a_uFirstElementIndex, const ISortingAlgorithm::ArraySize_t a_uLastElementIndex)
{
    // nullptr check not needed - check implemented in CMergeSort::sort() function
    if(a_uFirstElementIndex != a_uLastElementIndex &&
            a_uLastElementIndex < m_uArraySize)
    {
        // split
        const ArraySize_t uCurrentSubarrayLength = a_uLastElementIndex - a_uFirstElementIndex + 1u;

        const ArraySize_t uLeftSubarrayFirstIndex = a_uFirstElementIndex;
        const ArraySize_t uLeftSubarrayLastIndex = (0 != uCurrentSubarrayLength%2 || 0u == uCurrentSubarrayLength/2)?uCurrentSubarrayLength/2u+a_uFirstElementIndex:
                                                                                                                       uCurrentSubarrayLength/2u-1u+a_uFirstElementIndex;

        const ArraySize_t uRightSubarrayFirstIndex = (0 != uCurrentSubarrayLength%2 || 0u == uCurrentSubarrayLength/2)?uCurrentSubarrayLength/2u+1u+a_uFirstElementIndex:
                                                                                                                         uCurrentSubarrayLength/2u+a_uFirstElementIndex;
        const ArraySize_t uRightSubarrayLastIndex = a_uLastElementIndex;

        // sort
        sortRoutine(uLeftSubarrayFirstIndex, uLeftSubarrayLastIndex);  // sort left subarray
        sortRoutine(uRightSubarrayFirstIndex, uRightSubarrayLastIndex);  // sort right subarray

        // subarrays sorted, time to sort this one !
        sortCurrentArray(a_uFirstElementIndex, a_uLastElementIndex, uLeftSubarrayLastIndex, uRightSubarrayFirstIndex);

        // copy only part of temp to original array
        std::copy(&m_auTempArray[uLeftSubarrayFirstIndex], &m_auTempArray[uRightSubarrayLastIndex+1u], &m_auArray[uLeftSubarrayFirstIndex]);
    }
}

void CMergeSort::sortCurrentArray(const ISortingAlgorithm::ArraySize_t a_uFirstElementIndex, const ISortingAlgorithm::ArraySize_t a_uLastElementIndex, const ArraySize_t a_uLeftSubarrayLastIndex, const ArraySize_t a_uRightSubarrayFirstIndex)
{
    ArraySize_t uCurrentTempArrayIndex = a_uFirstElementIndex;
    ArraySize_t uLeftSubarrayIndex = a_uFirstElementIndex;
    ArraySize_t uRightSubarrayIndex = a_uRightSubarrayFirstIndex;

    while(a_uLastElementIndex+1u > uCurrentTempArrayIndex)
    {
        if(uLeftSubarrayIndex <= a_uLeftSubarrayLastIndex &&
                uRightSubarrayIndex <= a_uLastElementIndex)
        {
            // both subarrays not empty
            if(m_auArray[uLeftSubarrayIndex] > m_auArray[uRightSubarrayIndex])
            {
                m_auTempArray[uCurrentTempArrayIndex] = m_auArray[uRightSubarrayIndex];
                ++uRightSubarrayIndex;
            }
            else
            {
                m_auTempArray[uCurrentTempArrayIndex] = m_auArray[uLeftSubarrayIndex];
                ++uLeftSubarrayIndex;
            }
        }
        else if(uLeftSubarrayIndex <= a_uLeftSubarrayLastIndex)
        {
            // left array left
            m_auTempArray[uCurrentTempArrayIndex] = m_auArray[uLeftSubarrayIndex];
            ++uLeftSubarrayIndex;
        }
        else
        {
            // right array left
            m_auTempArray[uCurrentTempArrayIndex] = m_auArray[uRightSubarrayIndex];
            ++uRightSubarrayIndex;
        }
        ++uCurrentTempArrayIndex;
    }
}
