#ifndef PERCOLATION_H 
#define PERCOLATION_H

#include "QuickUnion.h"

inline std::size_t getRandom(std::size_t N);

class Percolation {
  public:
       Percolation(int N);                  // create n-by-n grid, with all sites blocked
       void open(int row, int col);         // open site (row, col) if it is not open already
       bool isOpen(int row, int col);       // is site (row, col) open?
       bool isFull(int row, int col);       // is site (row, col) full?
       bool percolates();                   // does the system percolate?
       ~Percolation();

        QuickUnion *qu;
    };

    #endif  /* PERCOLATION_H */