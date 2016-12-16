#include <iostream>
#include "cbubblesort.h"
#include "cinsertionsort.h"
#include "cselectionsort.h"
#include "ccountingsort.h"
#include "cmergesort.h"

using namespace std;

int main()
{
    const ISortingAlgorithm::ArraySize_t uArraySize = 100000u;
    CBubbleSort oBubbleSort;
    oBubbleSort.createReversedArray(uArraySize);
    //oBubbleSort.getSortingTime();

    CInsertionSort oInsertionSort;
    oInsertionSort.createReversedArray(uArraySize);
    //oInsertionSort.getSortingTime();

    CSelectionSort oSelectionSort;
    oSelectionSort.createReversedArray(uArraySize);
    //oSelectionSort.getSortingTime();

    CCountingSort oCountingSort;
    oCountingSort.createReversedArray(uArraySize);
    //oCountingSort.getSortingTime();

    CMergeSort oMergeSort;
    oMergeSort.createReversedArray(uArraySize);
    oMergeSort.getSortingTime();

    return 0;
}

