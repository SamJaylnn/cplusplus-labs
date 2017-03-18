/*
 * Assignment #12: Compare sorting algorithms
 *
 * CMPE 180-92 Data Structures and Algorithms in C++
 * Department of Computer Engineering
 * R. Mak, Nov. 20, 2016
 */
#include "InsertionSort.h"

/**
 * Default constructor.
 */
InsertionSort::InsertionSort() : VectorSorter() {}

/**
 * Destructor.
 */
InsertionSort::~InsertionSort() {}

/**
 * Get the name of this sorting algorithm.
 * @return the name.
 */
string InsertionSort::name() const { return "Insertion sort"; }

/**
 * Run the insertion sort algorithm.
 * @throws an exception if an error occurred.
 */
void InsertionSort::run_sort_algorithm() throw (string)
{
    /***** Complete this member function. *****/
    /* Data Structures using C++ */
    int firstOutOfOrder, location;
    int temp;

    for(firstOutOfOrder = 1; firstOutOfOrder < size; firstOutOfOrder++) {
      if(data[firstOutOfOrder] < data[firstOutOfOrder - 1]) {
        temp = data[firstOutOfOrder];
        location = firstOutOfOrder;

        do {
          data[location] = data[location - 1];
          location--;
          move_count++;
          compare_count++;
        }
        while (location > 0 && data[location - 1] > temp);

        data[location] = temp;
        move_count++;
      }
      compare_count++;
    }
}
