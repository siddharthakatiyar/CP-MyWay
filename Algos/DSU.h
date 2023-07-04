#ifndef DSU_H
#define DSU_H

#include <vector>
using namespace std;

namespace Algos
{
    class DSU
    {
    public:
        DSU(int n);
        ~DSU();

        int find(int x);
        void merge(int x, int y);

    private:
        vector<int> parent;
        vector<int> rank;
    };
}

#endif // DSU_H