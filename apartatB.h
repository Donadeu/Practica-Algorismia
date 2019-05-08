#ifndef PERCOLATION_H 
#define PERCOLATION_H

#include "quickUnion.h"

inline std::size_t getRandom(std::size_t N);

class Percolacio {
QuickUnion qu;
  public:
       Percolacio(int N);                  // create n-by-n grid, with all sites blocked
       bool obrir(int row, int col);         // open site (row, col) if it is not open already
       bool isOpen(int row, int col);       // is site (row, col) open?
       bool isFull(int row, int col);       // is site (row, col) full?
       bool percolates();                   // does the system percolate?
       void dPercolacio();
	QuickUnion getQu();
    };

    #endif  /* PERCOLATION_H */
