/*
 * Assignment #12: Compare sorting algorithms
 *
 * CMPE 180-92 Data Structures and Algorithms in C++
 * Department of Computer Engineering
 * R. Mak, Nov. 20, 2016
 */
#include "ShellSortOptimal.h"

/**
 * Default constructor.
 */
ShellSortOptimal::ShellSortOptimal() {}

/**
 * Destructor.
 */
ShellSortOptimal::~ShellSortOptimal() {}

/**
 * Get the name of this sorting algorithm.
 * @return the name.
 */
string ShellSortOptimal::name() const { return "Shellsort optimal"; }

/**
 * Run the optimal shellsort algorithm.
 * According to Don Knuth:
 * h = 3*i + 1 for i = 0, 1, 2, ... used in reverse.
 * @throws an exception if an error occurred.
 */
void ShellSortOptimal::run_sort_algorithm() throw (string)
{
    /***** Complete this member function. *****/
    int h = 1;
    /* calculate interval*/
    while(h < size/3) {
      h = h * 3 + 1;
    }

    while (h > 0) {
      for(int i = h; i < size; i++){

      /* select value to be inserted */
      int valueToInsert = data[i];
      int j = i;

         /*shift element towards right*/
        while(j > h - 1 && data[j - h] >= valueToInsert) {
            data[j] = data[j - h];
            compare_count++;
            j = j - h;
            move_count++;
        }

      /* insert the number at hole position */
      data[j] = valueToInsert;
      compare_count++;
      }
      /* calculate interval*/
      h = (h - 1) /3;
    }
}
