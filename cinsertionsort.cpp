#include "cinsertionsort.h"

CInsertionSort::CInsertionSort():
    ISortingAlgorithm(__func__)
{}

CInsertionSort::~CInsertionSort()
{}

void CInsertionSort::sort()
{
    if(nullptr != m_auArray)
    {
        for(unsigned long long uIteratorUnsorted=0u; uIteratorUnsorted<m_uArraySize; ++uIteratorUnsorted)
        {
            for(unsigned long long uIteratorSorted=0u; uIteratorSorted<uIteratorUnsorted; ++uIteratorSorted)
            {
                if(m_auArray[uIteratorUnsorted]<m_auArray[uIteratorSorted])
                {
                    unsigned long long uTemp = m_auArray[uIteratorUnsorted];
                    // shift right uIteratorSorted:uIteratorUnsorted-1
                    for(unsigned long long uIteratorShift=uIteratorUnsorted; uIteratorShift>uIteratorSorted; --uIteratorShift)
                    {
                        m_auArray[uIteratorShift] = m_auArray[uIteratorShift-1];
                    }
                    m_auArray[uIteratorSorted] = uTemp;
                }
            }
        }
    }
}

