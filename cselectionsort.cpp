#include "cselectionsort.h"

CSelectionSort::CSelectionSort():
    ISortingAlgorithm(__func__)
{}

CSelectionSort::~CSelectionSort()
{}

void CSelectionSort::sort()
{
    if(nullptr != m_auArray)
    {
        for(ArraySize_t uIteratorUnsorted=0u; uIteratorUnsorted<m_uArraySize; ++uIteratorUnsorted)
        {
            //find min
            ArrayElement_t uMin = m_auArray[uIteratorUnsorted];
            ArraySize_t uMinIndex=uIteratorUnsorted;
            for(ArraySize_t uIteratorMinIndex=uIteratorUnsorted; uIteratorMinIndex<m_uArraySize; ++uIteratorMinIndex)
            {
                if(uMin>m_auArray[uIteratorMinIndex])
                {
                    uMin = m_auArray[uIteratorMinIndex];
                    uMinIndex = uIteratorMinIndex;
                }
            }
            ArrayElement_t uTemp = m_auArray[uIteratorUnsorted];
            m_auArray[uIteratorUnsorted] = m_auArray[uMinIndex];
            m_auArray[uMinIndex] = uTemp;
        }
    }
}

