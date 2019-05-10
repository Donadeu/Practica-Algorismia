#ifndef QUICKUNION_H
#define QUICKUNION_H

#include <vector>

struct Site {
    bool open = false;
    std::size_t id; // parent
};

typedef std::vector< std::vector<Site> > Matrix2D;

class QuickUnion {
     Matrix2D grid;
     int mida;
public:
    QuickUnion();
    QuickUnion(int N);
    void setOpen(int i, int j, bool b);
    bool isConnected(int p, int q);
    void Union(int p, int q);
    int root(int p);
    Site getSite(int x, int y);
    virtual ~QuickUnion(){ }
};

#endif  /* QUICKUNION_H */
