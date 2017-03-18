/*
 * Assignment #12: Compare sorting algorithms
 *
 * CMPE 180-92 Data Structures and Algorithms in C++
 * Department of Computer Engineering
 * R. Mak, Nov. 20, 2016
 */
#include "ShellSortSuboptimal.h"

/**
 * Default constructor.
 */
ShellSortSuboptimal::ShellSortSuboptimal() {}

/**
 * Destructor.
 */
ShellSortSuboptimal::~ShellSortSuboptimal() {}

/**
 * Get the name of this sorting algorithm.
 * @return the name.
 */
string ShellSortSuboptimal::name() const { return "Shellsort suboptimal"; }

/**
 * Run the suboptimal shellsort algorithm.
 * @throws an exception if an error occurred.
 */
void ShellSortSuboptimal::run_sort_algorithm() throw (string)
{
    /***** Complete this member function. *****/
    /* calculate interval*/
    int h = size / 2;


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
      h = (h) / 2;
    }
}
