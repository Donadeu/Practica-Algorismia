#ifndef QUICKUNION_H
#define QUICKUNION_H

#include <vector>

struct Site {
    bool open = false;
    std::size_t id; // parent
};

typedef std::vector<std::vector<Site>>   Matrix2D;

class QuickUnion {
public:
    QuickUnion(const int N);

    bool isConnected(int p, int q);
    void Union(int p, int q);
    int Root(int p);

    virtual ~QuickUnion(){ }

    Matrix2D grid;
};

#endif  /* QUICKUNION_H */