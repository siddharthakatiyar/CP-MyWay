#ifndef DSU_H
#define DSU_H

#include <vector>
using namespace std;

namespace Algos
{
    struct disjoint_set
    {
        vector<int> par;

        disjoint_set(int n) : par(n + 1, -1) {}

        int find(int v) { return par[v] < 0 ? v : par[v] = find(par[v]); }

        void join(int u, int v)
        {
            if ((u = find(u)) != (v = find(v)))
            {
                if (par[u] > par[v])
                    par[v] += par[u], par[u] = v;
                else
                    par[u] += par[v], par[v] = u;
            }
        }
    };
}

#endif // DSU_H