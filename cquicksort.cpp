#include "cquicksort.h"

CQuickSort::CQuickSort()
{
    m_szAlgorithmName = __func__;
}

CQuickSort::~CQuickSort()
{

}

void CQuickSort::sort()
{
    // TODO
    ArraySize_t uLeftPointer = 0u;
    ArraySize_t uRightPointer = m_uArraySize-1u;
    ArraySize_t uLeftChangeIndex = 0u;
    ArraySize_t uRightChangeIndex = 0u;


    for(ArraySize_t uIterator=uLeftPointer+1u; uIterator<m_uArraySize; ++uIterator)
    {
        if(m_auArray[uLeftPointer]<m_auArray[uIterator])
        {
            uLeftChangeIndex = uIterator;
            break;
        }
    }

    for(ArraySize_t uIterator=uRightChangeIndex; uIterator<m_uArraySize; --uIterator)
    {
        if(m_auArray[uRightPointer]>=m_auArray[uIterator])
        {
            uLeftChangeIndex = uIterator;
            break;
        }
    }
}

void CQuickSort::sort(ISortingAlgorithm::ArraySize_t a_uFirstElementIndex, ISortingAlgorithm::ArraySize_t a_uLastElementIndex)
{
    // TODO
}

