/*
 * Assignment #12: Compare sorting algorithms
 *
 * CMPE 180-92 Data Structures and Algorithms in C++
 * Department of Computer Engineering
 * R. Mak, Nov. 20, 2016
 */
#include "QuickSortOptimal.h"

/**
 * Get the name of this sorting algorithm.
 * @return the name.
 */
QuickSortOptimal::QuickSortOptimal() {}

/**
 * Destructor.
 */
QuickSortOptimal::~QuickSortOptimal() {}

/**
 * Get the name of this sorting algorithm.
 * @return the name.
 */
string QuickSortOptimal::name() const { return "Quicksort optimal"; }

/**
 * Choose a good pivot, the median-of-three:
 * The middle value of the leftmost, rightmost, and center elements.
 * This is a compromise since the most optimal pivot would be the
 * median of the subrange, but that's too expensive to compute.
 * @param left the left index of the subrange to sort.
 * @param right the right index of the subrange to sort.
 * @return the chosen pivot value.
 */
int QuickSortOptimal::choose_pivot_strategy(const int left, const int right)
{
    /***** Complete this member function. *****/
    int check1 = data[left];
    int check2 = data[(left + right) / 2];
    int check3 = data[right];
    if((check1 >= check2 && check1 <= check3) ||
      (check1 >= check3 && check1 <= check2)) {
      return check1;
    }
    else if((check2 >= check1 && check2 <= check3) ||
        (check2 >= check3 & check2 <= check1)) {
      return check2;
    }
    else {
      return check3;
    }
}
