/*
 * Assignment #12: Compare sorting algorithms
 *
 * CMPE 180-92 Data Structures and Algorithms in C++
 * Department of Computer Engineering
 * R. Mak, Nov. 20, 2016
 */
#include "QuickSorter.h"

/**
 * Default constructor.
 */
QuickSorter::QuickSorter() : VectorSorter() {}

/**
 * Destructor.
 */
QuickSorter::~QuickSorter() {}

/**
 * Run the quicksort algorithm.
 * @throws an exception if an error occurred.
 */
void QuickSorter::run_sort_algorithm() throw (string)
{
    quicksort(0, size-1);
}

/**
 * The quicksort algorithm recursively sorts data subranges.
 * @param left the left index of the subrange to sort.
 * @param right the right index of the subrange to sort.
 */
void QuickSorter::quicksort(const int left, const int right)
{
    /***** Complete this member function. *****/
    // http://www.algolist.net/Algorithms/Sorting/Quicksort
    int pivot = choose_pivot(left, right);
    int index = partition(left, right, pivot);
      if (left < index - 1)
        quicksort(left, index - 1);
      if (index < right)
        quicksort(index, right);
}

/**
 * Choose the pivot according to a pivot strategy.
 * The chosen pivot will be moved temporarily to the right end.
 * @param left the left index of the partition to sort.
 * @param right the right index of the partition to sort.
 * @return the pivot value.
 */
int QuickSorter::choose_pivot(const int left, const int right)
{
    return choose_pivot_strategy(left, right);
}

/**
 * Partition the subrange by moving data elements < pivot to the left
 * and data elements > pivot to the right.
 * @param left the left index of the partition to sort.
 * @param right the right index of the partition to sort.
 * @param pivot the pivot value.
 */
int QuickSorter::partition(const int left, const int right, const int pivot)
{
    /***** Complete this member function. *****/
    // http://www.algolist.net/Algorithms/Sorting/Quicksort
    // starting values and a tmp value to hold when swapping
    int i = left;
    int j = right;
    int tmp;

    // continue loop until i and j pass each other
    while (i <= j) {
      // look for a value > pivot starting from left
      while (data[i] < pivot) {
        i++;
        compare_count++;
      }
      compare_count++;
      // look for a value < pivot starting from the right
      while (data[j] > pivot) {
        j--;
        compare_count++;
      }
      compare_count++;
      if (i <= j) {
      // swap values when i > pivot and j < pivot
        swap(i, j);
        i++;
        j--;
        compare_count++;
      }
    }
    return i;
}
