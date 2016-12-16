#include "isortingalgorithm.h"
#include <iostream>
#include <typeinfo>

ISortingAlgorithm::ISortingAlgorithm(std::__cxx11::string a_szAlgorithmName):
    m_uArraySize(0u),
    m_auArray(nullptr),
    m_randomNumberEngine(std::random_device()()),
    m_uniformDistribution(),
    m_szAlgorithmName(a_szAlgorithmName)
{

}

ISortingAlgorithm::~ISortingAlgorithm()
{

}

bool ISortingAlgorithm::createRandomArray(const ArraySize_t a_uSize)
{
    bool fRetVal = false;

    m_auArray = new ArrayElement_t[a_uSize];

    if(nullptr != m_auArray)
    {
        m_uArraySize = a_uSize;

        for(ArraySize_t uIterator=0u;uIterator<a_uSize;++uIterator)
        {
            m_auArray[uIterator] = m_uniformDistribution(m_randomNumberEngine);
        }
    }

    return fRetVal;
}

bool ISortingAlgorithm::createSortedArray(const ArraySize_t a_uSize)
{
    bool fRetVal = false;

    m_auArray = new ArrayElement_t[a_uSize];

    if(nullptr != m_auArray)
    {
        m_uArraySize = a_uSize;

        for(ArraySize_t uIterator=0u;uIterator<a_uSize;++uIterator)
        {
            m_auArray[uIterator] = uIterator;
        }
    }

    return fRetVal;
}

bool ISortingAlgorithm::createReversedArray(const ArraySize_t a_uSize)
{
    bool fRetVal = false;

    m_auArray = new ArrayElement_t[a_uSize];

    if(nullptr != m_auArray)
    {
        m_uArraySize = a_uSize;

        for(ArraySize_t uIterator=0u;uIterator<a_uSize;++uIterator)
        {
            m_auArray[uIterator] = a_uSize - uIterator;
        }
    }

    return fRetVal;
}

void ISortingAlgorithm::displayArray()
{
    if(nullptr != m_auArray)
    {
        for(ArraySize_t uIterator=0u; uIterator<m_uArraySize; ++uIterator)
        {
            std::cout << m_auArray[uIterator] << std::endl;
        }
    }
}

std::clock_t ISortingAlgorithm::getSortingTime()
{
    std::clock_t lRetVal;
    std::clock_t lStart = ::clock();

    sort();

    std::clock_t lStop = ::clock();
    lRetVal = 1000.0 * (lStop-lStart) / CLOCKS_PER_SEC;
    std::cout << "Time: " << lRetVal << " " << m_szAlgorithmName << " isSorted: " << isSorted() << std::endl;

    return lRetVal;
}

bool ISortingAlgorithm::isSorted()
{
    bool fRetVal = false;

    if(nullptr != m_auArray)
    {
        fRetVal = true;
        for(ArraySize_t uIterator=0u; uIterator<m_uArraySize-1; ++uIterator)
        {
            if(m_auArray[uIterator]>m_auArray[uIterator+1])
            {
                fRetVal = false;
                break;
            }
        }
    }

    return fRetVal;
}

