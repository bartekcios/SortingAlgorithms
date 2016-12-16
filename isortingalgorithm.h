#ifndef ISORTINGALGORITHM_H
#define ISORTINGALGORITHM_H
#include <random>
#include <ctime>
#include <string>

class ISortingAlgorithm
{
public:
    // types
    typedef unsigned long long SortingElement_t;
    typedef unsigned long long ArraySize_t;
    //methods
    ISortingAlgorithm();
    virtual ~ISortingAlgorithm();
    virtual void sort() = 0;

    bool createRandomArray(const ArraySize_t a_uSize);
    bool createSortedArray(const ArraySize_t a_uSize);
    bool createReversedArray(const ArraySize_t a_uSize);
    void displayArray();
    std::clock_t getSortingTime();

protected:
    // methods
    bool isSorted();
    // variables
    std::string m_szAlgorithmName;
    ArraySize_t m_uArraySize;
    SortingElement_t* m_auArray;
    // random
    std::random_device m_randomDevice;
    std::mt19937 m_randomNumberEngine;
    std::uniform_int_distribution<SortingElement_t> m_uniformDistribution;
};

#endif // ISORTINGALGORITHM_H
