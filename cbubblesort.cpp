#include "cbubblesort.h"

CBubbleSort::CBubbleSort():
    ISortingAlgorithm(__func__)
{}

CBubbleSort::~CBubbleSort()
{}

void CBubbleSort::sort()
{
    bool fChanged = true;
    if(nullptr != m_auArray)
    {
        while(fChanged)
        {
            fChanged = false;

            for(unsigned long long uIterator=0u; uIterator<m_uArraySize-1; ++uIterator)
            {
                if(m_auArray[uIterator] > m_auArray[uIterator+1u])
                {
                    unsigned long long uTemp = m_auArray[uIterator];
                    m_auArray[uIterator] = m_auArray[uIterator+1u];
                    m_auArray[uIterator+1u] = uTemp;

                    fChanged = true;
                }
            }
        }
    }
}

