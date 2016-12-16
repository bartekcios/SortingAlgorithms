#include "ccountingsort.h"
#include <cstring>
#include <iostream>

using namespace std;

CCountingSort::CCountingSort():
    ISortingAlgorithm(__func__)
{}

CCountingSort::~CCountingSort()
{}

void CCountingSort::sort()
{
    if(nullptr != m_auArray)
    {
        // get max value
        ArrayElement_t uMaxValue = m_auArray[0u];
        for(ArraySize_t uIterator=0u; uIterator<m_uArraySize; ++uIterator)
        {
            if(uMaxValue<m_auArray[uIterator])
            {
                uMaxValue = m_auArray[uIterator];
            }
        }

        ++uMaxValue;
        ArrayElement_t* auCountingArray = new ArrayElement_t[uMaxValue];  // MaxVal + zero

        if(nullptr != auCountingArray)
        {
            memset(auCountingArray, 0u, sizeof(ArrayElement_t)*uMaxValue);
            // fill in counting array
            for(ArraySize_t uIterator=0u; uIterator<m_uArraySize; ++uIterator)
            {
                ++auCountingArray[m_auArray[uIterator]];
            }

            // fill in original array
            ArraySize_t uOriginalArrayIndex = 0u;
            for(ArraySize_t uCountingArrayIterator=0u; uCountingArrayIterator<uMaxValue; ++uCountingArrayIterator)
            {
                for(ArraySize_t uIterator=0u; uIterator<auCountingArray[uCountingArrayIterator]; ++uIterator)
                {
                    m_auArray[uOriginalArrayIndex++] = uCountingArrayIterator;
                }
            }
            delete[] auCountingArray;
        }
    }
}

